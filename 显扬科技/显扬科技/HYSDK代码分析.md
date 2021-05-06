# HYSDK代码分析

## 文件目录结构

### common

#### HYPluginCoreVersion.h

```cpp
#pragma once
#include <common/HYVersion.h>

HY_MODEL_VERSION(HYPluginCore, "1.0.0", "d4134dd8d5979b36d449b86633ba0ddda8601321", "2021-04-08 10:03:36 +0800");
```

#### HYPluginFactory.hpp

```cpp
#pragma once

#include <functional>
#include <common/HYPlugin.hpp>

namespace hy
{
    class HYPluginFactory
    {
    public:
        HY_SHARED_PTR(HYPluginFactory);

        HYPluginFactory() {}
        virtual ~HYPluginFactory() {}

        template <class T>
        std::shared_ptr<T> find(const std::string& id)
        {
            return std::static_pointer_cast<T>(this->create(id));
        }

        virtual int load(const std::string& file, std::string& id) = 0;
        virtual std::size_t size() = 0;
        virtual int add(const std::string& id, const HYPlugin::Ptr& plugin, bool load) = 0;
        virtual void all(std::vector<std::string>& ids, int type = PLUGIN_TYPE_UNDEFINE) = 0;
        virtual void remove(const std::string& id) = 0;
        //virtual void clear() = 0;

    protected:
        virtual HYPlugin::Ptr create(const std::string& id) = 0;
    };

    extern "C" HYPLUGIN_API HYPluginFactory * PluginFactoryInstance();

    template <class T>
    class HYPluginRegister
    {
    public:
        HYPluginRegister(const std::string& id, bool load) : id_(id)
        {
            dynamic_cast<HYPluginFactory*>(PluginFactoryInstance())->add(id_,
                std::static_pointer_cast<HYPlugin>(std::make_shared<T>()), load);
        }
        virtual ~HYPluginRegister()
        {
            dynamic_cast<HYPluginFactory*>(PluginFactoryInstance())->remove(id_);
        }
    private:
        std::string id_;
    };
}

///< 通过动态加载dll，使用此宏注册其创建的插件类
#define HYPLUGIN_REGISTER(id, plugin) static hy::HYPluginRegister<plugin> _##plugin##_register_(id, true); 
///< 自动加载dll，插件提供者应使用此宏注册其创建的插件类
#define HYPLUGIN_REGISTER_AUTO(id, plugin) static hy::HYPluginRegister<plugin> _##plugin##_register_(id, false); 
```

#### HYPlugin.hpp

```cpp
#pragma once

#ifdef _USRDLL
	#ifdef HYPLUGIN_EXPORTS
		#define HYPLUGIN_API __declspec(dllexport)
	#else
		#define HYPLUGIN_API __declspec(dllimport)
	#endif
#else
	#define HYPLUGIN_API
#endif

#include <string>
#include <memory>

#include <common/HYCommon.h>

#include <opencv2/opencv.hpp>

namespace hy
{	
	enum PluginError
	{
		PLUGIN_ERROR_FAIL = -1,
		PLUGIN_ERROR_SUCESS = 0
	};

	enum PluginType
	{
		PLUGIN_TYPE_UNDEFINE,
		PLUGIN_TYPE_ROBOT,
		PLUGIN_TYPE_SENSOR_2D,
		PLUGIN_TYPE_SENSOR_3D,
		PLUGIN_TYPE_ALGORITHM
	};

	enum PluginMode
	{
		PLUGIN_MODE_NORMAL
	};

	class HYPLUGIN_API HYPlugin : public std::enable_shared_from_this<HYPlugin>
	{
	public:
		HY_SHARED_PTR(HYPlugin);

		HYPlugin(int type = PLUGIN_TYPE_UNDEFINE)
			: type_(type), initialize_(false), workspace_("."), mode_(PLUGIN_MODE_NORMAL)
		{
		}
		virtual ~HYPlugin() {}

		inline int type() {
			return type_;
		}

		void workspace(const std::string& path) {
			workspace_ = path;
			load(workspace_ + "/config.json", kv_);
		}

		const std::string& workspace() const {
			return workspace_;
		}

		const std::string& name() const {
			return name_;
		}

		const std::string& version() const {
			return version_;
		}

		virtual int initialize() {
			initialize_ = true;
			return PLUGIN_ERROR_SUCESS;
		}

		virtual int mode(int mode) {
			mode_ = mode;
			return PLUGIN_ERROR_SUCESS;
		}

		virtual void release() {
			initialize_ = false;
		}

	protected:		
		int readi(const std::string& name, int& value);
		int readf(const std::string& name, float& value);
		int readd(const std::string& name, double& value);
		int check(const std::string& name);

	private:
		int load(const std::string& file, std::map<std::string, std::string>& kv);
		int save(const std::string& file, const std::map<std::string, std::string>& kv);

	protected:
		int type_, mode_;
		std::string name_, version_, workspace_;
		bool initialize_;
		std::map<std::string, std::string> kv_;
	};
}
```

### robot

#### HYRobotPluginParam.h

```cpp
#pragma once

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

namespace hy
{
	enum RobotIOType
	{
		ROBOT_IO_TYPE_DI,
		ROBOT_IO_TYPE_DO,
		ROBOT_IO_TYPE_AI,
		ROBOT_IO_TYPE_AO,
		ROBOT_IO_TYPE_VAL
	};

	enum RobotIOAction
	{
		ROBOT_IO_ACTION_GET,
		ROBOT_IO_ACTION_SET,
		ROBOT_IO_ACTION_WAIT_EQ, // 等于
		ROBOT_IO_ACTION_WAIT_GT, // 大于
		ROBOT_IO_ACTION_WAIT_LT, // 小于
		ROBOT_IO_ACTION_WAIT_MS  // 毫秒
	};
	/// <summary>
	/// 机械坐标轴（XYZUVW）限制操作符
	/// </summary>
	enum AxisLimitOperate
	{
		DEFAULT,	//<不进行修改
		SET_VAULE,	//<设置值，覆盖原值
		OFFSET		//<补偿值，在原值上添加补偿值
	};
	/// <summary>
	/// 关节(J0~J5)限制操作符
	/// 目前只支持Aubo
	/// </summary>
	enum JointLimitOperate
	{
        JOINT_DEFAULT,	//<不进行修改
        JOINT_SET_VAULE,	//<设置值，覆盖原值
        JOINT_OFFSET		//<补偿值，在原值上添加补偿值
	};
	struct HYRobotIOTask
	{
		int Action;
		int Type;
		std::string Name;
		double Value;
	};
	/// <summary>
	/// 机械坐标轴限制
	/// </summary>
	struct HYAxisLimitSet
	{
		std::string Name;
		AxisLimitOperate Operate;
		double Value;
	};
    /// <summary>
    /// 关节坐标轴限制
    /// </summary>
    struct HYJointLimitSet
    {
        int Name;
		JointLimitOperate Operate;
        double Value;
    };
	struct HYRobotCoordinate
	{
		cv::Mat HandEye;
		std::vector<double> Tool;
		std::vector<std::vector<double>> Positions;
		std::vector<HYAxisLimitSet> AxisLimit;	//机械坐标轴限制
		std::vector<HYJointLimitSet> JointLimit;//关节坐标轴限制
	};
}
```

#### HYRobotPlugin.hpp

```cpp
#pragma once

#include <common/HYPlugin.hpp>
#include <robot/HYRobotPluginParam.h>
#include <common/LoggerHelper.hpp>
#include <opencv2/opencv.hpp>

#include <vector>
#include <map>
#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif // !_USE_MATH_DEFINES
#include <math.h>

namespace hy
{
	enum RobotPoseType
	{
		ROBOT_POSE_TCP,
		ROBOT_POSE_JOINT
	};

	struct NavigationParam
	{
		int Position;
		std::vector<double> Destination;
		std::vector<double> Transition;
	};

	struct RobotModelParam {
		struct Axis {
			std::string File;
			std::vector<double> Origin = { 0,0,0 };
			std::vector<double> AxisAngle = { 0,0,0};
		};
		std::vector<Axis> axis;

		static int read(std::string file, RobotModelParam& model_param) 
		{
			cv::FileStorage fs(file, cv::FileStorage::READ);
			RobotModelParam::Axis axis;
			if (fs.isOpened())
			{
				try
				{
					for (auto& it : fs.root())
					{
						it["File"] >> axis.File;
						it["Origin"] >> axis.Origin;
						it["AxisAngle"] >> axis.AxisAngle;
						model_param.axis.push_back(axis);
					}
					return PLUGIN_ERROR_SUCESS;
				}
				catch (const std::exception& ex)
				{
					HY_LOG_SEV(error) << boost::format("read model file %1% catch exception: %2%") % file % ex.what();
					return PLUGIN_ERROR_FAIL;
				}
			}
			HY_LOG_SEV(error) << boost::format("read model file %1% fail") % file;
			return PLUGIN_ERROR_FAIL;
		}

		static int write(std::string file, RobotModelParam& model_param) 
		{
			cv::FileStorage fs(file, cv::FileStorage::WRITE);
			if (fs.isOpened()) {
				try {
					for (int i = 0; i < model_param.axis.size(); i++) {
						fs << (boost::format("Axis_%1%") % i).str();
						fs << "{";
						fs << model_param.axis[i].File;
						fs << model_param.axis[i].AxisAngle;
						fs << model_param.axis[i].Origin;
						fs << "}";
					}
				}
				catch (const std::exception& ex)
				{
					HY_LOG_SEV(error) << boost::format("read model file %1% catch exception: %2%") % file % ex.what();
					return PLUGIN_ERROR_FAIL;
				}
			}
		}
	};

	class HYPLUGIN_API HYRobotPlugin : public HYPlugin
	{
	public:
		HY_SHARED_PTR(HYRobotPlugin);
		HYRobotPlugin()
			: host_("localhost"), port_(0), speed_(0), connected_(false), HYPlugin(PLUGIN_TYPE_ROBOT)
		{}
		virtual ~HYRobotPlugin() {}

		void workspace(const std::string& path) {
			HYPlugin::workspace(path);
			this->updateCoordinate();
		}

		virtual bool connected() {
			return connected_;
		}

		virtual void address(const std::string& host, uint16_t port) {
			host_ = host;
			port_ = port;
		}

		virtual int remote(std::string& host, uint16_t& port) {
			host = host_;
			port = port_;
			return PLUGIN_ERROR_SUCESS;
		}

		virtual void speed(double speed) {			
			speed_ = speed;
		}

		virtual int move(size_t position) {
			if (position < coordinate_.Positions.size())
				return this->move(coordinate_.Positions[position]);
			else
				return PLUGIN_ERROR_FAIL;
		}

		virtual int gripper2base(cv::Mat& R, cv::Mat& t) {
			std::vector<double> pose; // x y z rx ry rz
			if (PLUGIN_ERROR_SUCESS == this->pose(pose) && pose.size() == 6)
			{
				R = cv::Mat(3, 3, CV_64FC1);
				R.at<double>(0, 0) = cos(pose[4]) * cos(pose[5]);
				R.at<double>(0, 1) = -cos(pose[4]) * sin(pose[5]);
				R.at<double>(0, 2) = sin(pose[4]);
				R.at<double>(1, 0) = cos(pose[3]) * sin(pose[5]) + cos(pose[5]) * sin(pose[3]) * sin(pose[4]);
				R.at<double>(1, 1) = cos(pose[3]) * cos(pose[5]) - sin(pose[3]) * sin(pose[4]) * sin(pose[5]);
				R.at<double>(1, 2) = -cos(pose[4]) * sin(pose[3]);
				R.at<double>(2, 0) = sin(pose[3]) * sin(pose[5]) - cos(pose[3]) * cos(pose[5]) * sin(pose[4]);
				R.at<double>(2, 1) = cos(pose[5]) * sin(pose[3]) + cos(pose[3]) * sin(pose[4]) * sin(pose[5]);
				R.at<double>(2, 2) = cos(pose[3]) * cos(pose[4]);
				t = cv::Mat(3, 1, CV_64FC1);
				t.at<double>(0, 0) = pose[0];
				t.at<double>(1, 0) = pose[1];
				t.at<double>(2, 0) = pose[2];
				return PLUGIN_ERROR_SUCESS;
			}
			else
				return PLUGIN_ERROR_FAIL;
		}

		void handeye(cv::Mat& handeye) {
			handeye = coordinate_.HandEye;
		}

		int update(const cv::Mat& handeye) {
			coordinate_.HandEye = handeye;
			return save(this->workspace_ + "/coordinate.json", coordinate_);
		}

		void tool(std::vector<double>& tool) {
			tool = coordinate_.Tool;
		}

		int update(const std::vector<double>& tool) {
			coordinate_.Tool = tool;
			return save(this->workspace_ + "/coordinate.json", coordinate_);
		}

		virtual int connect() = 0;		
		virtual void disconnect() = 0;
		virtual bool ready() = 0;
		virtual int pose(std::vector<double>& loc, int type = ROBOT_POSE_TCP) = 0;
		virtual int move(const std::vector<double>& loc, int type = ROBOT_POSE_TCP) = 0;
		virtual void stop() = 0;
		
		virtual int navigation(const NavigationParam& param, int type = ROBOT_POSE_TCP) = 0;
		virtual bool reached() = 0;
		virtual int run(const std::string& task) {
			if (task_.find(task) == task_.end())
				return PLUGIN_ERROR_FAIL;
			
			return PLUGIN_ERROR_SUCESS;
		}
		virtual int readModel(RobotModelParam& model_param);

	protected:
		int load(const std::string& file, std::map<std::string, std::vector<HYRobotIOTask>>& task);
		int save(const std::string& file, const std::map<std::string, std::vector<HYRobotIOTask>>& task);
		int updateCoordinate();

	private:
		int load(const std::string& file, HYRobotCoordinate& coordinate);
		int save(const std::string& file, const HYRobotCoordinate& coordinate);

	protected:
		//void checkoutAxisConfig(const NavigationParam& param, const std::vector<HYAxisLimitSet> axisLimitSet);
		void checkoutAxisConfig(const NavigationParam& param, NavigationParam& limitedparam);
		cv::Mat eulerAnglesToRotationMatrix(float U, float V, float W);//ŷ����ת��ת����

protected:
		std::string host_;
		uint16_t port_;
		bool connected_;
		std::map<std::string, std::vector<HYRobotIOTask>> task_;
		HYRobotCoordinate coordinate_;
		double speed_;
	};
}

```

## 源代码