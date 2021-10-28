cmake_minimum_required(VERSION 3.8)

project(AuboRobotPlugin-HRL VERSION 0.0.1)

# 开启对Qt moc工具的支持
set(CMAKE_AUTOMOC ON)

# 查找Qt5的Core模块
#find_package(Qt5 COMPONENTS Core REQUIRED)

# 查找OpenCV
file(TO_CMAKE_PATH $ENV{OPENCV_ROOT} OPENCV_ROOT) # 将OPENCV_ROOT环境变量中的"\"转为"/"，将转换后的值存入CMake变量
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_ROOT}) # 将${OPENCV_ROOT}加入CMake的模块查找路径
find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME} SHARED)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

# 添加包含目录
target_include_directories(${PROJECT_NAME} 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$ENV{HYSDK_ROOT}/include/HYCommon
		$ENV{HYSDK_ROOT}/include/HYPluginCore
		$ENV{PCL_ROOT}/3rdParty/Boost/include/boost-1_74
		$ENV{HYSDK_ROOT}/3rdParty/Aubo/include
		${OpenCV_INCLUDE_DIRS}
)

# 添加源码
target_sources(${PROJECT_NAME} 
	PRIVATE
		include/AuboRobotPlugin.h
		src/AuboRobotPlugin.cpp
)

# 添加链接库
target_link_libraries(${PROJECT_NAME}
	PUBLIC
		$ENV{HYSDK_ROOT}/3rdParty/Aubo/lib/libserviceinterface.lib
		${OpenCV_LIBS}
		$ENV{HYSDK_ROOT}/lib/HYCommon.lib
		$ENV{HYSDK_ROOT}/lib/HYPluginCore.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/boost_log-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_log_setup-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_thread-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_regex-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_filesystem-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_date_time-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_chrono-vc142-mt-x64-1_74.lib
		$ENV{PCL_ROOT}/3rdParty/Boost/lib/libboost_atomic-vc142-mt-x64-1_74.lib
)

target_compile_definitions(${PROJECT_NAME} 
	PRIVATE 
		BOOST_LOG_DYN_LINK
)

# 生成后自动从hysdk复制AuboRobotPlugin所依赖的dll
add_custom_command(
	TARGET
		${PROJECT_NAME}
	POST_BUILD
		COMMAND
			${CMAKE_COMMAND} -E copy_directory $ENV{HYSDK_ROOT}/3rdParty/Aubo/bin $<TARGET_FILE_DIR:${PROJECT_NAME}>
	VERBATIM
)

# 生成后自动复制dll到测试文件夹，以方便测试
# message(SEND_ERROR ../${PROJECT_SOURCE_DIR})
string(REGEX REPLACE "(.+)\\AuboRobotPlugin-HRL.*" "\\1" PROJECT_INIT_PATH ${PROJECT_SOURCE_DIR})
# message(SEND_ERROR ${PROJECT_INIT_PATH}PluginTest/AuboRobotPlugin-HRL)
add_custom_command(
	TARGET
		${PROJECT_NAME}
	POST_BUILD
		COMMAND
			${CMAKE_COMMAND} -E copy_directory $ENV{HYSDK_ROOT}/3rdParty/Aubo/bin ${PROJECT_INIT_PATH}PluginTest/AuboRobotPlugin-HRL
		COMMAND
			${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.dll ${PROJECT_INIT_PATH}PluginTest/AuboRobotPlugin-HRL
	VERBATIM
)

# 设置安装规则
set(_bin_install_path ${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} 
	RUNTIME DESTINATION ${_bin_install_path}
)
install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
	DESTINATION ${_bin_install_path}
	OPTIONAL
)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/config.json
		${CMAKE_CURRENT_SOURCE_DIR}/coordinate.json
		${CMAKE_CURRENT_SOURCE_DIR}/io_task.json
		${CMAKE_CURRENT_SOURCE_DIR}/AxlesModel.json
	DESTINATION ${_bin_install_path}
	OPTIONAL
)
