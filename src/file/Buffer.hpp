/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

#ifndef SRC_FILE_BUFFER_HPP_
#define SRC_FILE_BUFFER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include "utils/Logger.hpp"
#include "IBuffer.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Buffer
    : public IBuffer
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    Buffer(QString fileName);
    virtual ~Buffer() = default;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                       //!< Logger object
    QString fileName_;                      //!< Filename
    QString content_;                       //!< Buffer's content
};

} // ::file

#endif /* SRC_FILE_BUFFER_HPP_ */
