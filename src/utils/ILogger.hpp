/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Interface for Logger class
 */

#ifndef SRC_UTILS_ILOGGER_H_
#define SRC_UTILS_ILOGGER_H_

#include <string>

namespace log
{

class ILogger
{
    public:
        /**
         * @brief Info level logs
         * @param log
         */
        virtual void info(std::string log) = 0;

        /**
         * @brief Info level logs
         * @param log
         */
        virtual void debug(std::string log) = 0;

        /**
         * @brief Info level logs
         * @param log
         */
        virtual void error(std::string log) = 0;
};

} // ::log

#endif // SRC_UTILS_ILOGGER_H_
