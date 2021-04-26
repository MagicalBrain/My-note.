# boost::format的用法

## format的用途

使用来控制格式化输出的，用来替代C中的sprintf函数。
优点：
类型齐全，不会因为类型和参数不匹配而导致程序崩溃，而且还可以重复使用参数，并且效率更高

## 实际应用

先看公司大佬写的定义：
```cpp
#define BOOST_LOG_STREAM_SEV(logger, lvl)\
    BOOST_LOG_STREAM_WITH_PARAMS((logger), (::boost::log::keywords::severity = (lvl)))
    
#define BOOST_LOG_SEV(logger, lvl) BOOST_LOG_STREAM_SEV(logger, lvl)

#define HY_LOG_SEV(lvl) BOOST_LOG_SEV(LoggerHelperInstance()->DefaultLogger(), ::boost::log::trivial::lvl) \
						<< boost::log::add_value("FileName", boost::filesystem::path(__FILE__).filename().string()) \
						<< boost::log::add_value("FileLine", __LINE__)
```