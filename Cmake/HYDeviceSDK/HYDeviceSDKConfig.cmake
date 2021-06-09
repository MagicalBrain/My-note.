find_library(HYDeviceSDK_LIBRARYS NAMES HYDeviceSDK PATHS "/usr/local/lib" )
HYDeviceSDK_LIBRARY_DIRS
find_path(HYDeviceSDK_INCLUDE_DIRS  
    NAMES HYDeviceSDK.h HYGRPCClient.h HYWebSocketClient.h HYSensorClient.h  
    PATHS "/usr/local/include")
set(HYDeviceSDK_FOUND TRUE)
