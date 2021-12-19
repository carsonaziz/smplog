//
// Created by Carson Aziz on 2021-12-18.
//

#ifndef SMPLOG_LOGGER_H
#define SMPLOG_LOGGER_H

#include <iostream>
#include <sstream>
#include <string>

namespace Logger
{
#define NC  "\e[0m"
#define WHT "\e[1;97m"
#define RED "\e[1;31m"
#define YLW "\e[1;93m"
#define GRN "\e[1;92m"

#define LOG_LEVEL Logger::Logger::level

    class Logger {
    public:
        enum class level
        {
            Debug       = 0,
            Info        = 1,
            Warning     = 2,
            Error       = 3
        };
    private:
        std::string m_name;
        level m_level;

    public:
        Logger(std::string name) : m_name(name) { m_level = level::Debug; }

        void set_level(level lvl);

        void debug(const std::string msg, ...);
        void info(const std::string msg, ...);
        void warn(const std::string msg, ...);
        void error(const std::string msg, ...);
    private:
        std::string format(const std::string msg, va_list args);
    };
}

#endif //SMPLOG_LOGGER_H
