#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_
/**
 * @author  {\_Sidewinder22_/}
 * @date    02.01.2019
 *
 * @brief   Class responsible for application logging.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QString>

//---------------------------------------------------------
//                  Global context
//---------------------------------------------------------
#define MY_FUNC std::string(__FUNCTION__ + std::string("() "))

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
        virtual ~Logger() = default;

        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;


        /**
         * @brief Function used to write string to stdout.
         * @param log Reference to logger instance
         * @param str Data to log
        */
        friend Logger& operator<<(Logger& log, std::string str);

        /**
         * @brief Function used to write QString to stdout.
         * @param log Reference to logger instance
         * @param info Data to log
        */
        friend Logger& operator<<(Logger& log, QString info);

        /**
         * @brief Function used to write const char* to stdout.
         * @param log Reference to logger instance
         * @param str Data to log
        */
        friend Logger& operator<<(Logger& log, const char* str);

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
    protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
    private:
        /**
         * @brief Write index at the beggining of the line
         */
        void writeIndex();

        std::string prefix_;    //!< Prefix contains class name
        bool beginLine_;        //!< Flag determining whether the line has been started
};

} // ::log

#endif // SRC_UTILS_LOGGER_H_
