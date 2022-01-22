# C++ 如何读取json

## 使用map直接处理？

HYPlugin.hpp里处理json的代码

```cpp

std::map<std::string, HYPluginConfig> kv_;

// 读取json里的int键值
int HYPlugin::readi(const std::string& name, int& value)
{
	if (kv_.find(name) == kv_.end())
	{
		HY_LOG_W("config {} not found", name);
		return HY_FAIL_NOT_FOUND;
	}
	try
	{
		value = std::stoi(kv_[name].Value);
	}
	catch (const std::exception& ex)
	{
		HY_LOG_E("read config {} value {} catch exception: {}", name, kv_[name].Value, ex.what());
		return HY_FAIL_EXCEPTION;
	}
	
	HY_LOG_D("config {} set to {}", name, value);
	return HY_SUCESS;
}

// // 读取json里的float键值
int HYPlugin::readf(const std::string& name, float& value)
{
	if (kv_.find(name) == kv_.end())
	{
		HY_LOG_W("config {} not found", name);
		return HY_FAIL_NOT_FOUND;
	}
	try
	{
		value = std::stof(kv_[name].Value);
	}
	catch (const std::exception& ex)
	{
		HY_LOG_E("read config {} value {} catch exception: {}", name, kv_[name].Value, ex.what());
		return HY_FAIL_EXCEPTION;
	}

	HY_LOG_D("config {} set to {}", name, value);
	return HY_SUCESS;
}

// 读取json里的double键值
int HYPlugin::readd(const std::string& name, double& value)
{
	if (kv_.find(name) == kv_.end())
	{
		HY_LOG_W("config {} not found", name);
		return HY_FAIL_NOT_FOUND;
	}
	try
	{
		value = std::stod(kv_[name].Value);
	}
	catch (const std::exception& ex)
	{
		HY_LOG_E("read config {} value {} catch exception: {}", name, kv_[name].Value, ex.what());
		return HY_FAIL_EXCEPTION;
	}

	HY_LOG_D("config {} set to {}", name, value);
	return HY_SUCESS;
}

// 读取json里的string键值

```

----

```cpp
int HYPlugin::loadConfig(bool clear)
{
    if (clear)
        kv_.clear();
    return this->load(workspace_ + "/config.json", kv_);
}

int HYPlugin::load(const std::string& file, std::map<std::string, HYPluginConfig>& kv)
{
	try
	{
		boost::property_tree::ptree ptree;
		boost::property_tree::read_json(file, ptree);
		//name_ = ptree.get<std::string>("Name", name_);
		//version_ = ptree.get<std::string>("Version", version_);
		auto childs = ptree.get_child_optional("KeyValues");
		if (childs)
		{
			for (auto it = childs.value().begin(); it != childs.value().end(); ++it)
			{
				HYPluginConfig config;
				config.Value = it->second.get<std::string>("Value");
				config.ReadOnly = it->second.get<bool>("ReadOnly", true);
				kv[it->second.get<std::string>("Key")] = config;
			}
		}
		return HY_SUCESS;
		//HY_LOG_SEV(error) << boost::format("load config file %1% fail") % file;
	}
	catch (const std::exception& ex)
	{
		HY_LOG_E("load config file {} catch exception: {}", file, ex.what());
	}
	return HY_FAIL_UNDEFINE;
}
```
