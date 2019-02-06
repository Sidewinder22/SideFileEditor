/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#include <iostream>
#include "Logger.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace log
{

Logger::Logger(std::string prefix)
    : prefix_(prefix)
    , beginLine_(true)
{ }

Logger& operator<<(Logger& log, std::string str)
{
    if (log.beginLine_)
    {
        std::cout << "[" << log.prefix_ << "] ";
        log.beginLine_ = false;
    }

    std::cout << str;

    if (str == "\n")
    {
        log.beginLine_ = true;
    }

    return log;
}

} // ::log
