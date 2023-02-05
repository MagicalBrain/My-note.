# README

https://github.com/MagicalBrain/MyTestManagerSystem.git

恐怕是要先生成.so动态库才能够编译吧。

先不用cmake，使用g++编译试试

## questionsDemo

```bash
g++ questionsDemo.cpp -o questionsDemo.o -std=c++11 -lQuestions
```

## 使用cmake编译QuestionsSDK的错误

```bash
Undefined symbols for architecture arm64:
  "questions::questions()", referenced from:
      choiceQuestions::choiceQuestions() in choiceQuestions.cpp.o
  "questions::~questions()", referenced from:
      choiceQuestions::~choiceQuestions() in choiceQuestions.cpp.o
  "typeinfo for questions", referenced from:
      typeinfo for choiceQuestions in choiceQuestions.cpp.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make[2]: *** [questionsDemo] Error 1
make[1]: *** [CMakeFiles/questionsDemo.dir/all] Error 2
make: *** [all] Error 2
```

我一开始以为是cmake不支持M1芯片，后来发现不是这个问题，Cmake支持M1芯片。
其实就是在questions.cpp文件里把questions类的构造函数和析构函数删除了。

## add_library cannot create target “XXXX“ because another target with the same name already exists.

CMake Error at CMakeLists.txt
add_library cannot create target “xxx” because another target with the same name already exists. The existing target is an executable created in source directory “/root/xxx/xxx”.See documentation for policy CMP0002 for more details.

在使用cmake进行编译时出现上述问题，最大的可能是编译生成的应用程序名称和生成的库文件名称是一样而导致的错误。所以需要检查add_executable内的程序名称和add_library的库文件名称。库文件的名称一般来说不与应用程序名称相同。修改后可能可解决上述问题

例如：
```bash
# 添加源代码文件
aux_source_directory(${PROJECT_DIR}/src  PROJECT_SOURCE_DIR)

# 生成可执行文件
# add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR})

# 生成动态库.so文件
add_library(${PROJECT_NAME} SHARED  ${PROJECT_SOURCE_DIR})
```

add_executable生成的目标文件和add_library生成的库文件名重复了。

将add_executable注释掉或者改个名字就好了
