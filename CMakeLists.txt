# 查找当前目录下的所有源文件

# 并将名称保存到 DIR_LIB_SRCS 变量

#aux_source_directory(. DIR_LIB_SRCS)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#set(SRC_PATH
#    "${CMAKE_CURRENT_SOURCE_DIR}"
#    "${CMAKE_CURRENT_SOURCE_DIR}/include")
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


#get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#message(">>> include_dirs=${dirs}") #打印一下目录情况

##message(STATUS "CMake step for googletest failed: ${PROJECT_SOURCE_DIR}")
#MESSAGE("<<< INCLUDE_DIRECTORIES:${INCLUDE_DIRECTORIES}")
# 生成链接库
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SDS_STATES_ALL_SOURCES)
#set(SDS_STATES_ALL_SOURCES  ${PROJECT_SOURCE_DIR}/src/max.cpp)

message(STATUS "CMake AndroidContentDevice test: ${SDS_STATES_ALL_SOURCES}")
if(ANDROID)
    #添加宏定义
    add_definitions(-DQ_ANDROID_CONTENT_DEVICE_EXPORT)
endif()


#add_library (MathFunctions ${DIR_LIB_SRCS})

#AndroidContentDevice
set(ANDROID_CONTENT_DEVICE_SOURCES
    ${SDS_STATES_ALL_SOURCES}
    PARENT_SCOPE
   )
