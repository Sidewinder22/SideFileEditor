/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    ContentManager.cpp
 *
 * @brief   Manager for buffer and files
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "BufferManager.hpp"
#include "FileManager.hpp"
#include "ContentManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

ContentManager::ContentManager()
    : log_("ContentManager")
	, bufferManager_(std::make_unique<BufferManager>())
	, fileManager_(std::make_unique<FileManager>())
{
	// Nothing
}

bool ContentManager::open(const QString& fileName)
{
	bool success = false;

	if (fileManager_->open(fileName))
	{
		loadFileContentIntoBuffer(fileName);
		success = true;
	}

	return success;
}

std::vector<QString> ContentManager::read(const QString& fileName)
{
	return bufferManager_->read(fileName);
}

bool ContentManager::save(const QString &fileName)
{
	log_ << MY_FUNC << "Filename = " << fileName << log::END;

	if (!fileManager_->isOpen(fileName))
	{
		log_ << MY_FUNC << "Content is empty, create new file" << log::END;
		if (!fileManager_->open(fileName))
		{
			log_ << MY_FUNC << "Cannot create new file" << log::END;
			return false;
		}
	}

	fileManager_->save(fileName, bufferManager_->read(fileName));
	bufferManager_->setSaved(fileName, true);

	return true;
}

void ContentManager::close(const QString& fileName)
{
	log_ << MY_FUNC << "Filename = " << fileName << log::END;

	bufferManager_->close(fileName);
	fileManager_->close(fileName);
}

bool ContentManager::contentChanged(const QString &fileName,
	const QString &content)
{
	// TODO: Change to the vector of lines
	return bufferManager_->write(fileName, { content });
}

void ContentManager::loadFileContentIntoBuffer(const QString& fileName)
{
	bufferManager_->create(fileName);

	auto content = fileManager_->read(fileName);
	bufferManager_->write(fileName, content);
}

} // ::content
