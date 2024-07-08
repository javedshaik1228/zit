#pragma once

#include <Logger.hpp>

#define LOG_MSG(message)                \
    do                                  \
    {                                   \
        std::stringstream ss;           \
        ss << "MSG: " << message;       \
        Logger::getInstance()->log(ss); \
    } while (0)

#define LOG_ERROR(message)              \
    do                                  \
    {                                   \
        std::stringstream ss;           \
        ss << "ERR: " << message;       \
        Logger::getInstance()->log(ss); \
    } while (0)

#define THROW_RUNTIME(message)              \
    do                                      \
    {                                       \
        std::stringstream ss;               \
        ss << "EXC: " << message;           \
        Logger::getInstance()->log(ss);     \
        throw std::runtime_error(ss.str()); \
    } while (0)

// END