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
namespace content
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

void Buffer::setFileName(const QString& fileName)
{
	fileName_ = fileName;
}

void Buffer::setContent(const std::vector<QString> &content)
{
	if (!content_.empty() &&
		content_[0] != content[0])
	{
		saved_ = false;
	}

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

} // ::content
