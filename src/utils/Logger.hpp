/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_

#include <iostream>
#include <string>
#include "ILogger.hpp"

namespace log
{

class Logger
    : public ILogger
{
    public:
        Logger(std::string prefix);

        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;

        /******************************************************
         *                  ILogger
         *****************************************************/
        /**
         * @brief Info level logs
         * @param log
         */
        void info(std::string log) override;

        /**
         * @brief Info level logs
         * @param log
         */
        void debug(std::string log) override;

        /**
         * @brief Info level logs
         * @param log
         */
        void error(std::string log) override;

    private:
        std::string prefix_;
};

} // ::log

#endif // SRC_UTILS_LOGGER_H_
