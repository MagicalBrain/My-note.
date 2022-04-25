# 设置Cmake 的最小版本
cmake_minimum_required(VERSION 3.13)

# 项目名字即：文件夹的名字
project(simple_example)

# 添加源代码文件
aux_source_directory(./ DIR_SRC)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRC})

