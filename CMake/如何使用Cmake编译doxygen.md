# 如何使用Cmake编译doxygen

## 创建Doxyfile.in文件

注：在Linux命令行里是直接使用`doxygen -g`命令生成默认的Doxyfile，而cmake则是通过`Doxyfile.in`来生成Doxyfile

```bash
# 项目名称，将作为于所生成的程序文档首页标题
PROJECT_NAME        = “xxx”
# 文档版本号，可对应于项目版本号，譬如 svn、cvs 所生成的项目版本号
PROJECT_NUMBER      = "1.0.0"
PROJECT_BRIEF          = "xxx"
# 程序文档输出目录
OUTPUT_DIRECTORY    =  docs
 
# 程序文档输入目录 
INPUT                = @CMAKE_CURRENT_LIST_DIR@/apps    \
                       @CMAKE_CURRENT_LIST_DIR@/include \
                       @CMAKE_CURRENT_LIST_DIR@/modules \
                       @CMAKE_CURRENT_LIST_DIR@/samples
 
# 程序文档语言环境
OUTPUT_LANGUAGE      = Chinese
DOXYFILE_ENCODING  = UTF-8
# 只对头文件中的文档化信息生成程序文档 
FILE_PATTERNS        = *.h *.cpp
 
# 递归遍历当前目录的子目录，寻找被文档化的程序源文件 
RECURSIVE            = YES 
# 如果是制作 C 程序文档，该选项必须设为 YES，否则默认生成 C++ 文档格式
OPTIMIZE_OUTPUT_FOR_C  = NO
 
#提取信息，包含类的私有数据成员和静态成员
EXTRACT_ALL            = yes
EXTRACT_PRIVATE        = yes
EXTRACT_STATIC        = yes
# 对于使用 typedef 定义的结构体、枚举、联合等数据类型，只按照 typedef 定义的类型名进行文档化
TYPEDEF_HIDES_STRUCT  = YES
# 在 C++ 程序文档中，该值可以设置为 NO，而在 C 程序文档中，由于 C 语言没有所谓的域/名字空间这样的概念，所以此处设置为 YES
HIDE_SCOPE_NAMES      = YES
# 让 doxygen 静悄悄地为你生成文档，只有出现警告或错误时，才在终端输出提示信息
QUIET  = YES
# 递归遍历示例程序目录的子目录，寻找被文档化的程序源文件
EXAMPLE_RECURSIVE      = YES
# 允许程序文档中显示本文档化的函数相互调用关系
REFERENCED_BY_RELATION = YES
REFERENCES_RELATION    = YES
REFERENCES_LINK_SOURCE = YES
# 不生成 latex 格式的程序文档
GENERATE_LATEX        = NO
# 在程序文档中允许以图例形式显示函数调用关系，前提是你已经安装了 graphviz 软件包
HAVE_DOT              = YES
CALL_GRAPH            = YES
CALLER_GRAPH          = YES
#在最后生成的文档中，把所有的源代码包含在其中
SOURCE_BROWSER        = YES
#这会在HTML文档中，添加一个侧边栏，并以树状结构显示包、类、接口等的关系
GENERATE_HTML         = YES
#GENERATE_TREEVIEW      ＝ YES
```

这`Doxyfile.in`里面的内容貌似和Doxyfile内容一致，那为啥不直接用，而是还要生成个`Doxyfile.in`？

## 参考链接

https://stackoverflow.com/questions/34878276/build-doxygen-from-cmake-script

I found on the Web a sample cmake file and put it in the `/doc` subdirectory of my project, where the file `myproject.doxgen` is also located, containing Doxygen configuration.

我发现网上的一些简单例子里面，cmakefile和`myproject.doxgen`一起被放在my project的子文件夹里，且包含了Doxygen的设置。

I've tested that running doxygen.exe myproject.doxygen produces valid output. I only need to build this into the CMake process. So /doc/CMakeLists.txt is:

我已经测过用doxygen.exe运行`myproject.doxgen`是可以的。我只需要将build这部分指令加进去`CMakeLists.txt`就可以了，`CMakeLists.txt`如下：

```bash
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API        
documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
         message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/../doc/myproject.doxygen)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    message("Doxygen build started.")

    add_custom_target(doc
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
                      COMMENT "Generating API documentation with Doxygen"
                      VERBATIM)

    #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
endif()
```

It doesn't work for me, it only copies the original config file into /build/my/project/doc/ and does nothing more.

What I want is to generate the doxygen documentation during my builds; ideally, only when building the Release configuration.


