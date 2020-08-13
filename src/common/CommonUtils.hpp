/**
 * @author  {\_Sidewinder22_/}
 * @date    02.10.2019
 *
 * @brief   Set of useful utils
 */
#ifndef SRC_COMMON_COMMONUTILS_H_
#define SRC_COMMON_COMMONUTILS_H_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace common
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class CommonUtils
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
    public:
        CommonUtils() = default;
        virtual ~CommonUtils() = default;

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

} // ::common

#endif /* SRC_COMMON_COMMONUTILS_H_ */
