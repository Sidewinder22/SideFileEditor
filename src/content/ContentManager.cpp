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

void ContentManager::loadFileContentIntoBuffer(const QString& fileName)
{
	bufferManager_->create(fileName);

	auto content = fileManager_->read(fileName);
	bufferManager_->write(fileName, content);
}

} // ::content
