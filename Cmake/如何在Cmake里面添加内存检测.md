# 如何在Cmake里面添加内存检测

使用valgrind

NOTE ：此示例代码可以在https://github.com/dev-cafe/cmake-cookbook/tree/v1.0/chapter-@4/recipe-05中找到，包含一个C++的示例。该示例在CMake3.5版（或更高版本）中是有效的，并且已经在GNU/Linux、 macos和Windows上进行过测试。

内存缺陷：写入或读取越界，或者内存泄漏（已分配但从未释放的内存），会产生难以跟踪的bug，最好尽早将它们检查出来。Valgrind（ http://valgrind.org ）是一个通用的工具，用来检测内存缺陷和内存泄漏。本节中，我们将在使用CMake/CTest测试时使用Valgrind对内存问题进行警告。

