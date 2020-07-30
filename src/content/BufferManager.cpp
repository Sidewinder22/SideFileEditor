/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    BufferManager.cpp
 *
 * @brief   Buffer manager
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "Buffer.hpp"
#include "BufferManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

BufferManager::BufferManager()
    : log_("BufferManager")
	, contentUtils_(std::make_unique<ContentUtils>())
{
	// Nothing
}

void BufferManager::create(const QString& fileName)
{
    log_ << MY_FUNC << "fileName = " << fileName << log::END;

    auto buffer = std::make_shared<Buffer>(fileName);
    buffers_.push_back(buffer);
}

void BufferManager::write(const QString& fileName,
	const std::vector<QString> &content)
{
	auto it = getBufferIterator(fileName);
	if (it != buffers_.end())
	{
		(*it)->write(content);
		(*it)->setSaved(true);
	}
}

std::vector<QString> BufferManager::read(const QString& fileName)
{
    auto it = getBufferIterator(fileName);
    if (it != buffers_.end())
    {
        return (*it)->read();
    }

    return {};
}

std::vector<std::shared_ptr<IBuffer>>::iterator
	BufferManager::getBufferIterator(const QString& fileName)
{
    return contentUtils_->getVectorIterator<IBuffer>(
        fileName,
        buffers_.begin(),
        buffers_.end());
}

} // ::content
