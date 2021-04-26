# boost::format的用法学习

## format的用途

使用来控制格式化输出的，用来替代C中的sprintf函数。
优点：
类型齐全，不会因为类型和参数不匹配而导致程序崩溃，而且还可以重复使用参数，并且效率更高

## 实际应用

先看部门里大佬写的定义：

```cpp
#define BOOST_LOG_STREAM_WITH_PARAMS_INTERNAL(logger, rec_var, params_seq)\
    for (::boost::log::record rec_var = (logger).open_record((BOOST_PP_SEQ_ENUM(params_seq))); !!rec_var;)\
        ::boost::log::aux::make_record_pump((logger), rec_var).stream()

#define BOOST_LOG_STREAM_WITH_PARAMS(logger, params_seq)\
    BOOST_LOG_STREAM_WITH_PARAMS_INTERNAL(logger, BOOST_LOG_UNIQUE_IDENTIFIER_NAME(_boost_log_record_), params_seq)

#define BOOST_LOG_STREAM_SEV(logger, lvl)\
    BOOST_LOG_STREAM_WITH_PARAMS((logger), (::boost::log::keywords::severity = (lvl)))
    
#define BOOST_LOG_SEV(logger, lvl) BOOST_LOG_STREAM_SEV(logger, lvl)

#define HY_LOG_SEV(lvl) BOOST_LOG_SEV(LoggerHelperInstance()->DefaultLogger(), ::boost::log::trivial::lvl) \
						<< boost::log::add_value("FileName", boost::filesystem::path(__FILE__).filename().string()) \
						<< boost::log::add_value("FileLine", __LINE__)
```

### 使用占位符输出

不用理会类型，注意占位符与输出变量之间的对应关系就可以了。

```cpp
	host_ = "192.168.10.188";
	port_ = 9760;
	HY_LOG_SEV(debug) << boost::format("initialize Host = %1%, Port = %2%") % host_ % port_;
```

输出：
```cpp
initialize Host = 192.168.10.188, Port = 9760
```

### 使用 类C 格式控制符

类C格式控制符：
```

```

```cpp
HY_LOG_SEV(debug) << boost::format("initialize Host = %s, Port = %d") % host_ % port_;
```

输出：
```cpp
initialize Host = 192.168.10.188, Port = 9760
```