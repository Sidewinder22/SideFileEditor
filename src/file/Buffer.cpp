/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "Buffer.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

Buffer::Buffer(QString fileName)
    : log_("Buffer")
    , fileName_(fileName)
{ 
    // Empty
}
    
QString Buffer::fileName() const
{
    return fileName_;
}

void Buffer::setContent(const QString &content)
{
    if (!content.isEmpty())
    {
        log_ << MY_FUNC << "[" << fileName_ << "] content: " << content << log::END;
        content_ = content;
    }
}

std::vector<QString> Buffer::getContent()
{
    log_ << MY_FUNC << log::END;
    return { content_ };
}

} // ::file
