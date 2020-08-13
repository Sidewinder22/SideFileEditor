/**
 * @author  {\_Sidewinder22_/}
 * @date    11.02.2019
 *
 * @brief   FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "FileMgr.hpp"

#include <algorithm>
#include "Buffer.hpp"
#include "File.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

FileMgr::FileMgr()
    : log_("FileManager")
    , commonUtils_(std::make_unique<common::CommonUtils>())
	, utils_(std::make_unique<ContentUtils>())
{ }

void FileMgr::createBuffer(const QString& fileName)
{
//    log_ << MY_FUNC << "fileName = " << fileName << log::END;
//
//    auto buffer = std::make_shared<Buffer>(fileName);
//    openBuffers_.push_back(buffer);
}

bool FileMgr::saveBufferIntoFile(const QString& bufferName,
	const QString& fileName)
{
    log_ << MY_FUNC << "bufferName = " << bufferName
    	<< ", fileName = " << fileName << log::END;

    auto buffIt = getBufferIterator(bufferName);
    bool success = false;

    auto file = createFile(fileName);
    if (file)
    {
		openFiles_.push_back(file);
		auto fileIt = getFileIterator(commonUtils_->extractFileName(fileName));

		saveFile(fileIt, buffIt);
		success = true;

		(*buffIt)->setFileName(fileName);
		(*buffIt)->setSaved(true);
    }

    return success;
}
    
bool FileMgr::textChanged(const QString &fileName, const QString &content)
{
//    auto it = getBufferIterator(fileName);
//    if (it != openBuffers_.end())
//    {
//        (*it)->write({ content });
//    }
//
//    return !(*it)->isSaved();
	return {};
}

bool FileMgr::openFile(const QString& fileName)
{
//    log_ << MY_FUNC << "fileName = " << fileName << log::END;
//    bool result = false;
//
//    auto file = createFile(fileName);
//    if (file)
//    {
//        openFiles_.push_back(file);
//        loadFileContentToNewBuffer(file);
//
//        result = true;
//    }
//    else
//    {
//        log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
//    }
//
//    return result;
	return {};
}

std::vector<QString> FileMgr::read(const QString& fileName)
{
//    auto buffIt = getBufferIterator(fileName);
//    if (buffIt != openBuffers_.end())
//    {
//        return (*buffIt)->getContent();
//    }
    
    return {};
}

bool FileMgr::save(const QString &fileName) 
{
    log_ << MY_FUNC << "fileName: " << fileName << log::END;
    bool result = false;

//    auto buffIt = getBufferIterator(fileName);
//    if (buffIt != openBuffers_.end())
//    {
//        auto fileIt = getFileIterator(fileName);
//        if (fileIt != openFiles_.end())
//        {
//            saveFile(fileIt, buffIt);
//
//            (*buffIt)->setSaved(true);
//            result = true;
//        }
//        else
//        {
//            auto file = createFile((*buffIt)->fileName());
//            if (file)
//            {
//                openFiles_.push_back(file);
//                file->write((*buffIt)->read());
//
//                (*buffIt)->setSaved(true);
//                result = true;
//            }
//            else
//            {
//                log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
//            }
//        }
//    }
//
    return result;
}

void FileMgr::close(const QString& fileName)
{
//    closeBuffer(fileName);
//
//    auto fileIt = getFileIterator(fileName);
//    if (fileIt != openFiles_.end())
//    {
//        (*fileIt).reset();
//        openFiles_.erase(fileIt);
//    }
}

void FileMgr::remove(const QString& fileName)
{
    closeBuffer(fileName);

    auto fileIt = getFileIterator(fileName);
    if (fileIt != openFiles_.end())
    {
        (*fileIt)->remove();
        (*fileIt).reset();
        openFiles_.erase(fileIt);
    }
}

std::vector<std::shared_ptr<IFile>>::iterator FileMgr::getFileIterator(
	const QString& fileName)
{
//    return utils_->getVectorIterator<IFile>(
//        fileName,
//        openFiles_.begin(),
//        openFiles_.end());
	return {};
}

std::vector<std::shared_ptr<IBuffer>>::iterator FileMgr::getBufferIterator(
	const QString& fileName)
{
//    return utils_->getVectorIterator<IBuffer>(
//        fileName,
//        openBuffers_.begin(),
//        openBuffers_.end());
	return {};
}

void FileMgr::loadFileContentToNewBuffer(std::shared_ptr<IFile> file)
{
//    auto buffer = std::make_shared<Buffer>(file->fileName());
//    openBuffers_.push_back(buffer);
//
//    auto content = file->read();
//    buffer->write(content);
//
//    // Set saved as true because content of file has been read from file
//    // and it is not modified at this point
//    buffer->setSaved(true);
}

std::shared_ptr<IFile> FileMgr::createFile(const QString& fileName)
{
//    std::shared_ptr<IFile> file;
//    try
//    {
//        file = std::make_shared<File>(fileName);
//    }
//    catch (const std::runtime_error& e)
//    {
//        log_ << MY_FUNC << "Cannot open file, error = " << e.what() << log::END;
//    }
//
//    return file;
	return {};
}

void FileMgr::closeBuffer(const QString& fileName)
{
//    auto buffIt = getBufferIterator(fileName);
//    if (buffIt != openBuffers_.end())
//    {
//        (*buffIt).reset();
//        openBuffers_.erase(buffIt);
//    }
}

// -> save()
void FileMgr::saveFile(
    std::vector<std::shared_ptr<IFile>>::iterator fileIt,
    std::vector<std::shared_ptr<IBuffer>>::iterator buffIt)
{
//    auto currentFilePath = (*fileIt)->fileName();
//    auto tempFile = std::make_shared<File>(currentFilePath + ".bcp");
//
//    tempFile->write((*buffIt)->read());
//
//    if ((*fileIt)->remove())
//    {
//        (*fileIt).reset();
//        (*fileIt) = tempFile;
//    }
//    else
//    {
//        log_ << MY_FUNC << "Cannot remove file: " << (*fileIt)->fileName() << log::END;
//    }
//
//    if (!(*fileIt)->rename(currentFilePath))
//    {
//        log_ << MY_FUNC << "Cannot changed fileName!" << log::END;
//    }
}

size_t FileMgr::numberOfOpenBuffers() const
{
	return openBuffers_.size();
}

size_t FileMgr::numberOfUnsavedBuffers() const
{
	return std::count_if(
		openBuffers_.begin(),
		openBuffers_.end(),
		[](auto && buffer) {
			return !buffer->empty() && !buffer->isSaved();
		} );
}

std::vector<QString> FileMgr::unsavedBufferNames() const
{
	std::vector<QString> names;

	for (auto && buffer : openBuffers_)
	{
		if (!buffer->empty() && !buffer->isSaved())
		{
			names.push_back(buffer->fileName());
		}
	}

	return names;
}

bool FileMgr::isFileSaved(const QString& fileName)
{
	bool saved = false;
    auto buffIt = getBufferIterator(fileName);
    if (buffIt != openBuffers_.end())
    {
    	saved = (*buffIt)->isSaved();
    }

    return saved;
}

bool FileMgr::isFileEmpty(const QString& fileName)
{
	bool empty = false;
    auto buffIt = getBufferIterator(fileName);
    if (buffIt != openBuffers_.end())
    {
    	empty = (*buffIt)->empty();
    }

    return empty;
}

} // ::content
