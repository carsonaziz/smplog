//
// Created by Carson Aziz on 2021-12-18.
//
#include "logger.h"

/*
 * Sets the loggers' severity log_level
 * @param lvl: log_level enum
 */
void smplog::Logger::set_level(log_level lvl)
{
    m_level = lvl;
}

/*
 * Prints a debug message to the terminal
 * @param msg: std::string
 * @param ...: currently only supports int, double, float, char, string
 */
void smplog::Logger::debug(const std::string& msg, ...)
{
    if(log_level::Debug >= m_level)
    {
        std::stringstream ss;
        if (m_output == log_output::Console)
            ss << "[" << m_name << "][" << WHT"DEBUG" << NC"]";
        else
            ss << "[" << m_name << "][DEBUG]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        log(ss.str());
    }
}

/*
 * Prints an info message to the terminal
 * @param msg: std::string
 * @param ...: currently only supports int, double, float, char, string
 */
void smplog::Logger::info(const std::string& msg, ...)
{
    if(log_level::Info >= m_level)
    {
        std::stringstream ss;
        if (m_output == log_output::Console)
            ss << "[" << m_name << "][" << GRN"INFO" << NC"]";
        else
            ss << "[" << m_name << "][INFO]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        log(ss.str());
    }
}

/*
 * Prints a warning message to the terminal
 * @param msg: std::string
 * @param ...: currently only supports int, double, float, char, string
 */
void smplog::Logger::warn(const std::string& msg, ...)
{
    if(log_level::Warning >= m_level)
    {
        std::stringstream ss;
        if (m_output == log_output::Console)
            ss << "[" << m_name << "][" << YLW"WARN" << NC"]";
        else
            ss << "[" << m_name << "][WARN]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        log(ss.str());
    }
}

/*
 * Prints an error message to the terminal
 * @param msg: std::string
 * @param ...: currently only supports int, double, float, char, string
 */
void smplog::Logger::error(const std::string& msg, ...)
{
    if(log_level::Error >= m_level)
    {
        std::stringstream ss;
        if (m_output == log_output::Console)
            ss << "[" << m_name << "][" << RED"ERROR" << NC"]";
        else
            ss << "[" << m_name << "][ERROR]";

        va_list args;
        int n = std::count(msg.begin(), msg.end(), '%');
        va_start(args, n);
        ss << format(msg, args);
        va_end(args);

        log(ss.str());
    }
}

/*
 * Logs the message to the console or the file
 * @param msg: std::string
 */
void smplog::Logger::log(const std::string& msg)
{
    if (m_output == log_output::Console)
        std::cout << msg << std::endl;
    else
        m_ofs << msg << std::endl;
}

/*
 * Returns the current logger severity level
 * @return m_level: log_level
 */
smplog::log_level smplog::Logger::get_level()
{
    return m_level;
}

/*
 * Returns the current logger output method
 * @return m_output: log_output
 */
smplog::log_output smplog::Logger::get_output()
{
    return m_output;
}

/*
 * Formats the arguments list based on the types of each element
 * @param msg: std::string
 * @param args: va_list
 */
std::string smplog::Logger::format(const std::string& msg, va_list args)
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

