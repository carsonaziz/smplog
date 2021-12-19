//
// Created by Carson Aziz on 2021-12-18.
//
#include "logger.h"

void Logger::Logger::set_level(level lvl)
{
    m_level = lvl;
}

void Logger::Logger::debug(const std::string msg, ...)
{
    if(level::Debug >= m_level)
    {
        std::stringstream ss;
        ss << "[" << m_name << "][" << WHT"DEBUG" << NC"]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        ss << std::endl;

        std::cout << ss.str();
    }
}

void Logger::Logger::info(const std::string msg, ...)
{
    if(level::Info >= m_level)
    {
        std::stringstream ss;
        ss << "[" << m_name << "][" << GRN"INFO" << NC"]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        ss << std::endl;

        std::cout << ss.str();
    }
}

void Logger::Logger::warn(const std::string msg, ...)
{
    if(level::Warning >= m_level)
    {
        std::stringstream ss;
        ss << "[" << m_name << "][" << YLW"WARN" << NC"]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        ss << std::endl;

        std::cout << ss.str();
    }
}

void Logger::Logger::error(const std::string msg, ...)
{
    if(level::Error >= m_level)
    {
        std::stringstream ss;
        ss << "[" << m_name << "][" << RED"ERROR" << NC"]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        ss << std::endl;

        std::cout << ss.str();
    }
}

std::string Logger::Logger::format(const std::string msg, va_list args)
{
    std::stringstream ss;
    for(int i = 0; i < msg.length(); i++)
    {
        if (msg[i] == '%')
        {
            switch (msg[i + 1])
            {
                case 'i':
                    ss << va_arg(args, int);
                    break;
                case 'd':
                    ss << va_arg(args, double);
                    break;
                case 'f':
                    ss << va_arg(args, double);
                    break;
                case 'c':
                    ss << va_arg(args, char);
                    break;
                case 's':
                    ss << va_arg(args, char*);
                    break;
                default:
                    break;
            }
        }
        else
        {
            if(msg[i-1] != '%')
                ss << msg[i];
        }
    }

    return ss.str();
}

