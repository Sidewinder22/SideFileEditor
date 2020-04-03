/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

#ifndef SRC_FILE_IBUFFER_HPP_
#define SRC_FILE_IBUFFER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IBuffer
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IBuffer() = default;

    virtual QString fileName() const = 0;

    virtual void setContent(const QString &content) = 0;

    virtual std::vector<QString> getContent() = 0;
};

} // ::file

#endif /* SRC_FILE_IBUFFER_HPP_ */
