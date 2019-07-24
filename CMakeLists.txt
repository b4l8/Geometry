cmake_minimum_required(VERSION 3.13)
project(SegmentTree)

set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE ${PROJECT_NAME}_CPP_FILES src/*.cpp src/*.c)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(Glog QUIET REQUIRED)
find_package(GTest QUIET REQUIRED)
message("find glog include dir: ${GLOG_INCLUDE_DIRS}")
message("find gtest include dir: ${GTEST_INCLUDE_DIRS}")

add_executable(SegmentTree main.cpp
    ${${PROJECT_NAME}_CPP_FILES}
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    include
    ${GLOG_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
    #${PROJECT_NAME}_lib
    ${GLOG_LIBRARIES})


add_library(${PROJECT_NAME}_lib ${${PROJECT_NAME}_CPP_FILES})
target_include_directories(${PROJECT_NAME}_lib
    PUBLIC
    include
    ${GLOG_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}_lib
    ${GLOG_LIBRARIES})

#### Test project
enable_testing()
file(GLOB_RECURSE ${PROJECT_NAME}_TEST_FILES test/*.cpp test/*.c)
#
add_executable(${PROJECT_NAME}_test ${${PROJECT_NAME}_TEST_FILES})
#
target_include_directories(${PROJECT_NAME}_test PUBLIC ${GTEST_INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test gtest_main gtest pthread)