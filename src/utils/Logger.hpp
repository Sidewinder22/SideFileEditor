/**
 * @author Damian Stepień
 * @date 02.01.2019
 *
 * @brief Class responsible for application logging.
 */

#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>

//---------------------------------------------------------
//                  Global context
//---------------------------------------------------------
#define MY_FUNC std::string(__FUNCTION__ + std::string("()"))

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace log
{
/**
 * @brief Static defines controlling the operation of the logger
 */
static std::string END("\n");

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Logger
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
    public:
        Logger(std::string prefix);

        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;

        /**
         * @brief Function used to write data to stdout.
         * @param log Reference to logger instance
         * @param str Data to log
        */
        friend Logger& operator<<(Logger& log, std::string str);

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
    protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
    private:
        std::string prefix_;    //!< Prefix contains class name
        bool beginLine_;        //!< Flag determining whether the line has been started
};

} // ::log

#endif // SRC_UTILS_LOGGER_H_
