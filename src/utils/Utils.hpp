#ifndef SRC_UTILS_UTILS_H_
#define SRC_UTILS_UTILS_H_
/**
 * @author  {\_Sidewinder22_/}
 * @date    02.10.2019
 *
 * @brief   Set of useful utils
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

//---------------------------------------------------------
//                  Global context
//---------------------------------------------------------

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace utils
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Utils
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
    public:
        Utils() = default;
        virtual ~Utils() = default;

        /**
         * @brief Extract filename from the given path
         * @param filePath Path to the file
         * @return File name
         */
        QString extractFileName(QString filePath);

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
    protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
    private:
};

} // ::utils

#endif /* SRC_UTILS_UTILS_H_ */
