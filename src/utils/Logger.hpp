/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_

#include <string>

namespace log
{

static std::string END_LOG("\n");
#define MY_FUNC std::string(__FUNCTION__)

class Logger
{
    public:
        Logger(std::string prefix);

        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;

        friend Logger& operator<<(Logger& log, std::string str);

        std::string endLog();

    private:
        std::string prefix_;
};

} // ::log

#endif // SRC_UTILS_LOGGER_H_
