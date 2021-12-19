//
// Created by Carson Aziz on 2021-12-18.
//

#ifndef SMPLOG_LOGGER_H
#define SMPLOG_LOGGER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace smplog
{
#define NC  "\e[0m"
#define WHT "\e[1;97m"
#define RED "\e[1;31m"
#define YLW "\e[1;93m"
#define GRN "\e[1;92m"

#define LOG_LEVEL smplog::log_level

    // Logger severity levels
    enum class log_level
    {
        Debug       = 0,
        Info        = 1,
        Warning     = 2,
        Error       = 3
    };

    // Logger output destination
    enum class log_output
    {
        Console     = 0,
        File        = 1
    };

    class Logger {
    private:
        std::string m_name;

        log_level m_level;
        log_output m_output;
        std::ofstream m_ofs;
        std::string m_output_file;

    public:
        /*
         * Logger console constructor - m_level set to debug and m_output set to Console by default
         * @param name: std::string
         */
        Logger(std::string name)
            : m_name(name), m_output(log_output::Console), m_output_file(""), m_level(log_level::Debug) {}

        /*
         * Logger file constructor - m_level set to debug and m_output set to File by default
         * @param name: std::string
         */
        Logger(std::string name, std::string output_file)
                : m_name(name), m_output(log_output::File), m_output_file(output_file), m_level(log_level::Debug)
        {
            m_ofs.open(output_file);
            if(!m_ofs.good())
            {
                std::cerr << "Could not open output file" << std::endl;
                m_output = log_output::Console;
            }
        }

        void set_level(log_level lvl);

        void debug(const std::string& msg, ...);
        void info(const std::string& msg, ...);
        void warn(const std::string& msg, ...);
        void error(const std::string& msg, ...);
        void log(const std::string& msg);

        log_level get_level();
        log_output get_output();
    private:
        std::string format(const std::string& msg, va_list args);
    };
}

#endif //SMPLOG_LOGGER_H
