/**
 * @author  {\_Sidewinder22_/}
 * @date    02.01.2019
 *
 * @brief   Class responsible for application logging.
 */

#ifndef SRC_LOG_LOGGER_H_
#define SRC_LOG_LOGGER_H_

#include <string>
#include <iostream>
#include <QString>

#define MY_FUNC std::string( __FUNCTION__ + std::string( "() " ) )

namespace log
{
static std::string END( "\n" );

class Logger
{
    public:
        Logger( std::string prefix );
        virtual ~Logger() = default;

        Logger( const Logger& ) = delete;
        Logger &operator=( const Logger& ) = delete;


        /**
         * @brief Template function used to write value of type T to the stdout.
         * @param log Reference to logger instance
         * @param value Data to log
        */
        template < typename T >
        friend Logger& operator<<( Logger& log, T value )
        {
			log.writeIndex();

			std::cout << value;

			return log;
        }

    private:
        void writeIndex();

        std::string prefix_;
        bool beginLine_;
};

template < typename T >
Logger& operator<<( Logger& log, T value );

template<>
Logger& operator<<( Logger& log, std::string str );

template<>
Logger& operator<<( Logger& log, QString info );

template<>
Logger& operator<<( Logger& log, const char* str );

} // ::log

#endif // SRC_LOG_LOGGER_H_
