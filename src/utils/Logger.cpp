/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#include <iostream>
#include "Logger.hpp"

namespace log
{

Logger::Logger(std::string prefix)
    : prefix_(prefix)
{ }

Logger& operator<<(Logger& log, std::string str)
{

    std::cout << str;
    return log;
}

std::string Logger::endLog()
{
    return "\n";
}

} // ::log
