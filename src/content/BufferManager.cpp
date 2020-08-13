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
    auto buffer = std::make_shared<Buffer>(fileName);
    buffers_.push_back(buffer);
}

bool BufferManager::write(const QString& fileName,
	const std::vector<QString> &content)
{
	bool success = false;

	auto it = getIterator(fileName);
	if (it != buffers_.end())
	{
		(*it)->write(content);
		(*it)->setSaved(true);
		success = true;
	}
	else
	{
    	log_ << MY_FUNC << "buffer not found!" << log::END;
	}

	return success;
}

std::vector<QString> BufferManager::read(const QString& fileName)
{
    auto it = getIterator(fileName);
    if (it != buffers_.end())
    {
        return (*it)->read();
    }
    else
    {
    	log_ << MY_FUNC << "buffer not found!" << log::END;
    	return {};
    }
}

void BufferManager::close(const QString& fileName)
{
    auto it = getIterator(fileName);
    if (it != buffers_.end())
    {
        (*it).reset();
        buffers_.erase(it);
    }
}

void BufferManager::setSaved(const QString& fileName, bool saved)
{
    auto it = getIterator(fileName);
    if (it != buffers_.end())
    {
        (*it)->setSaved(saved);
    }
    else
    {
    	log_ << MY_FUNC << "buffer not found!" << log::END;
    }
}

bool BufferManager::isSaved(const QString& fileName)
{
	bool isSaved = false;

	auto it = getIterator(fileName);
    if (it != buffers_.end())
    {
        isSaved = (*it)->isSaved();
    }

    return isSaved;
}

std::vector<std::shared_ptr<IBuffer>>::iterator
	BufferManager::getIterator(const QString& fileName)
{
    return contentUtils_->getVectorIterator<IBuffer>(
        fileName,
        buffers_.begin(),
        buffers_.end());
}

} // ::content
