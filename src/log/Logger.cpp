/**
 * @author  {\_Sidewinder22_/}
 * @date    02.01.2019
 *
 * @brief   Class responsible for application logging.
 */

#include <cstring>
#include "Logger.hpp"

namespace log
{

Logger::Logger( std::string prefix )
    : prefix_( prefix )
    , beginLine_( true )
{ }

template<>
Logger& operator<<( Logger& log, std::string str )
{
	log.writeIndex();

	std::cout << str;

	if ( str == "\n" )
	{
		log.beginLine_ = true;
	}

	return log;
}

template<>
Logger& operator<<( Logger& log, QString info )
{
    log.writeIndex();

    std::string str = info.toStdString();
    std::cout << str;

    if ( str == "\n" )
    {
        log.beginLine_ = true;
    }

    return log;
}

template<>
Logger& operator<<( Logger& log, const char* str )
{
    log.writeIndex();

    std::cout << str;

    int result = std::strcmp( str, "\n" );
    if ( result == 0 )
    {
        log.beginLine_ = true;
    }

    return log;
}

void Logger::writeIndex()
{
    if ( beginLine_ )
    {
        std::cout << "[" << prefix_ << "] ";
        beginLine_ = false;
    }
}

} // ::log
