/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#include "Logger.hpp"

namespace log
{

Logger::Logger(std::string prefix)
    : prefix_(prefix)
{ }

void Logger::info(std::string log)
{
    std::cout << "[" << prefix_ << "] " << log << std::endl;
}

void Logger::debug(std::string log)
{
#ifdef DEBUG
    std::cout << "[" << prefix_ << "] " << log << std::endl;
#endif
}

void Logger::error(std::string log)
{
    std::cout << "[" << prefix_ << "] " << log << "!!!" << std::endl;
}

} // ::log
