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
    : saved_(false)
    , log_("Buffer")
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

std::vector<QString> Buffer::getContent() const
{
    return content_;
}

bool Buffer::empty() const
{
	return content_.empty();
}
    
void Buffer::clear()
{
    content_.clear();
}

bool Buffer::isSaved() const
{
	return saved_;
}

void Buffer::setSaved(bool saved)
{
	saved_ = saved;
}

} // ::file
