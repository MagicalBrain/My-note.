# HinYeung机器人插件开发demo01

## 控制机器人走到几个点

代码写的规范一点，定义一个Point类，Path类

path.h:

```cpp
#pragma once
#include <iostream>
#include <vector>

using std::vector;

class Point
{
private:
    double x, y, z, u, v, w;

public:
    Point();
    ~Point();

    void inputPoint();
    vector<double> getPoint();
};

class Path
{
private:
    int num_point_;     //路径点的数量
    vector<vector<double> > path_line_;     //存储路径点坐标的vector

public:
    Path();
    ~Path();

    int getNumPoint();
    bool setNumPoint(int num);

    bool pushPathLine(vector<double> point);
    void pushPathLine();

    //int popPathLine(vector<vector<double> >& path_line);
    //bool inputPoint();

    vector<vector<double> > getPatnLine();
    bool clearPathLine();
};

```

Path.cpp

```cpp
#include "include/Path.h"

Point::Point() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
    this->u = 0.0;
    this->v = 0.0;
    this->w = 0.0;
}

Point::~Point() {

}

void Point::inputPoint() {
    //std::cout << "请输入点位坐标（x/y/z/u/v/w)" << std::endl;
    std::cout << "Please input the coordinate of the destination. (x/y/z/u/v/w)" << std::endl;
    std::cin >> this->x >> this->y >> this->z >> this->u >> this->v >> this->w;

}

vector<double> Point::getPoint() {
    vector<double> re;

    re.push_back(this->x);
    re.push_back(this->y);
    re.push_back(this->z);
    re.push_back(this->u);
    re.push_back(this->v);
    re.push_back(this->w);
    return re;
}

/* ----- ------ */

Path::Path() {
    this->num_point_ = 0;
}

Path::~Path() {

}

int Path::getNumPoint() {
    return this->num_point_;
}

bool Path::setNumPoint(int num) {
    if (num < 0)
        return false;

    this->num_point_ = num;
    return true;
}

bool Path::pushPathLine(vector<double> point) {
    std::cout << "the size of point: " << point.size() << std::endl;
    if (point.size() < 6)
        return false;

    this->path_line_.push_back(point);
    return true;
}       

void Path::pushPathLine() {
    Point tmp;
    tmp.inputPoint();
    this->path_line_.push_back(tmp.getPoint());
}

//int popPathLine(vector<vector<double> >& path_line);

vector<vector<double> > Path::getPatnLine() {
    return this->path_line_;
}

bool Path::clearPathLine() {
    this->path_line_.clear();
    return true;
}

```

source.cpp

```cpp
#include <common/HYPluginFactory.hpp>
#include <robot/HYRobotPlugin.hpp>

#include <io/FileHelper.h>
#include <common/LoggerHelper.hpp>

#include "include/Path.h"

#include <iostream>

using namespace hy;

int main(int argc, const char** argv)
{
	std::string path;
	std::cout << "Please input plugin path:";
	std::cin >> path;
	HY_LOG_SEV(info) << "looking at " << path;
	std::vector<std::string> files;
	FileHelper::EnumerateFiles(path, files, "^.*?Plugin\.dll$");
	HYPluginFactory* factory = PluginFactoryInstance();
	std::string id;
	for (auto file : files)
	{
		factory->load(file, id);
	}
	
	files.clear();
	factory->all(files, PLUGIN_TYPE_ROBOT);
	std::cout << "Plugin loaded:" << std::endl;
	for (auto file : files)
		std::cout << "\t" << file << std::endl;

	std::cout << "Select plugin: ";
	std::cin >> id;
	std::cin.ignore();
	HYRobotPlugin::Ptr robot_plugin_ = factory->find<HYRobotPlugin>(id);

	std::cout << "Please input paramter json path:";
	std::cin >> path;
	robot_plugin_->workspace(path);

 	if (robot_plugin_ == nullptr)
	{
		HY_LOG_SEV(error) << boost::format("no plugin id match %1%") % id;
		return HY_FAIL_UNDEFINE;
	}
	else
		HY_LOG_SEV(info) << boost::format("get plugin %1% sucess") % id;

	if (HY_SUCESS != robot_plugin_->initialize())
	{
		HY_LOG_SEV(error) << boost::format("plugin %1% initialize fail") % id;
		return HY_FAIL_UNDEFINE;
	}



    //获取当前点位世界坐标
	std::vector<double> pose;
    //点位关节坐标
	std::vector<double> jointsPose;

	//char key;
	//double value;
	std::string host;
	int port;
	NavigationParam param;

    //connect to robot
    std::cout << "Please input the IP address of Robot." << std::endl;
    std::cin >> host;
    std::cout << "Please input the TCP port of Robot." << std::endl;
    std::cin >> port;
    robot_plugin_->address(host, port);
    robot_plugin_->connect();

    //get pose
    robot_plugin_->pose(pose);
    HY_LOG_SEV(info) << boost::format("the pose of robot is %1%.") % pose;

    //get path
    Path road;
    int num;
    //std::cout << "请输入路径点个数:" << std::endl;
    std::cout << "Please input the number of points:" << std::endl;
    std::cin >> num;
    road.setNumPoint(num);
    for (int i = 0; i < num; i++) {
        std::cout << i + 1 << ":";
        road.pushPathLine();
    }

    //move
    std::string flag;
    std::cout << "Ready to go?(yes/no)" << std::endl;
    std::cin >> flag;

    if (flag == "yes" ||
        flag == "y" ||
        flag == "Yes") {
        for (auto i : road.getPatnLine()) {
            HY_LOG_SEV(info) << boost::format("the Destination of robot is %1%.") % i;
            robot_plugin_->move(i);
            robot_plugin_->pose(pose);
            HY_LOG_SEV(info) << boost::format("the pose of robot is %1%.") % pose;
        }
    }
    else {
        std::cout << "Cancel! Stop the robot and quit" << std::endl;
        //return 0;
    }
    
    //disconnect
    robot_plugin_->disconnect();
    robot_plugin_->release();
	
	return HY_SUCESS;
}

```

正方形点位：
UR的
```bash
200 -200 600 1 1 1
200 -100 600 1 1 1
200 -100 300 1 1 1
200 -200 300 1 1 1
```

## 进阶demo

控制机器人走一个心形路径，结束后触发相机拍照保存生成的点云


