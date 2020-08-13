#ifndef SRC_CONTENT_IBUFFER_HPP_
#define SRC_CONTENT_IBUFFER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
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
    virtual void setFileName(const QString& fileName) = 0;

    virtual void write(const std::vector<QString> &content) = 0;
    virtual std::vector<QString> read() const = 0;

    virtual bool empty() const = 0;
    virtual void clear() = 0;

    virtual bool isSaved() const = 0;
    virtual void setSaved(bool saved) = 0;
};

} // ::content

#endif /* SRC_CONTENT_IBUFFER_HPP_ */
