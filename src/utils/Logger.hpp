/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_

#include <string>

#define MY_FUNC std::string(__FUNCTION__ + std::string("()"))

namespace log
{

/**
 * @brief Static defines controlling the operation of the logger
 */
static std::string END("\n");

class Logger
{
    public:
        Logger(std::string prefix);

        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;

        friend Logger& operator<<(Logger& log, std::string str);

    private:
        std::string prefix_;    //!< Prefix contains class name
        bool beginLine_;        //!< Flag determining whether the line has been started
};

} // ::log

#endif // SRC_UTILS_LOGGER_H_
