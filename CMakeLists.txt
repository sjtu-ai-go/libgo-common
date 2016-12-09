cmake_minimum_required(VERSION 3.1)
project(libgo-common)

option(libgo-common_build_tests "Build libgo-common's own tests" OFF)

set(CMAKE_CXX_STANDARD 11)

##################################
# Spdlog
##################################
set(spdlog_SOURCE_DIR vendor/spdlog)
add_subdirectory (${spdlog_SOURCE_DIR})
include_directories(${spdlog_SOURCE_DIR}/include)

##################################
# libgo-common
##################################
include_directories(${libgo-common_SOURCE_DIR}/src)

set(logger_SRC src/logger.cpp)

add_library(go-common STATIC ${logger_SRC})


#################################
# tests
################################
if (libgo-common_build_tests)
    enable_testing()
    ################################
    # GTest
    ################################
    ADD_SUBDIRECTORY (vendor/googletest/googletest)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    ###############################
    # Logger-test
    ###############################
    add_executable(logger-test src/logger_test.cpp)
    target_link_libraries(logger-test go-common gtest gtest_main)
    add_test(logger_test logger-test)
endif()