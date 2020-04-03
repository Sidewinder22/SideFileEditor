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
    // Nothing
}
    
QString Buffer::fileName() const
{
    return fileName_;
}

void Buffer::setContent(const std::vector<QString> &content)
{
    content_ = content;
}

std::vector<QString> Buffer::getContent()
{
    return content_;
}
    
void Buffer::clear()
{
    content_.clear();
}

} // ::file
