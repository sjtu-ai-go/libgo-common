//
// Created by lz on 10/14/16.
//
#include <memory>
#include "logger.hpp"

std::shared_ptr<spdlog::logger> LoggerSingleton::logger = spdlog::stderr_color_mt("default");

