/**
 * @author  {\_Sidewinder22_/}
 * @date    11.02.2019
 *
 * @brief   FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "Buffer.hpp"
#include "File.hpp"
#include "FileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

FileManager::FileManager()
    : log_("FileManager")
    , utils_(std::make_unique<utils::Utils>())
{ }

void FileManager::createBuffer(const QString& fileName)
{
    log_ << MY_FUNC << "fileName = " << fileName << log::END;

    auto buffer = std::make_shared<Buffer>(fileName);
    openBuffers_.push_back(buffer);
}
    
void FileManager::textChanged(const QString &fileName, const QString &content)
{
    auto it = getCurrentBuffer(fileName);
    if (it != openBuffers_.end())
    {
        (*it)->setContent({ content });
    }
}

bool FileManager::openFile(const QString& fileName)
{
    log_ << MY_FUNC << "fileName = " << fileName << log::END;
    bool result = false;

    std::shared_ptr<IFile> file;
    try
    {
        file = std::make_shared<File>(fileName);
    }
    catch (const std::runtime_error& e)
    {
        log_ << MY_FUNC << "Cannot open file, error = " << e.what() << log::END;
    }

    if (file)
    {
        openFiles_.push_back(file);
        loadFileContentToNewBuffer(file);
        
        result = true;
    }
    else
    {
        log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
    }

    return result;
}

std::vector<QString> FileManager::read(const QString& fileName)
{
    auto buffIt = getCurrentBuffer(fileName);
    if (buffIt != openBuffers_.end())
    {
        return (*buffIt)->getContent();
    }
    
    return {};
}

bool FileManager::save(const QString &fileName) 
{
    log_ << MY_FUNC << "fileName: " << fileName << log::END;
    bool result = false;

    auto buffIt = getCurrentBuffer(fileName);
    if (buffIt != openBuffers_.end())
    {
        auto fileIt = getCurrentFile(fileName);
        if (fileIt != openFiles_.end())
        {
            auto currentFilePath = (*fileIt)->fileName();
            auto tempFile = std::make_shared<File>(currentFilePath + ".bcp");

            tempFile->write((*buffIt)->getContent());

            if ((*fileIt)->remove())
            {
                (*fileIt).reset();
                (*fileIt) = tempFile;
            }
            else
            {
                log_ << MY_FUNC << "Cannot remove file: " << (*fileIt)->fileName() << log::END;
            }

            if (!(*fileIt)->rename(currentFilePath))
            {
                log_ << MY_FUNC << "Cannot changed fileName!" << log::END;
            }

            result = true;
        }
        else
        {
            std::shared_ptr<IFile> file;
            try
            {
                file = std::make_shared<File>((*buffIt)->fileName());
            }
            catch (const std::runtime_error& e)
            {
                log_ << MY_FUNC << "Cannot open file, error = " << e.what() << log::END;
            }

            if (file)
            {
                openFiles_.push_back(file);
                file->write((*buffIt)->getContent());
                result = true;
            }
            else
            {
                log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
            }
        }
    }
    
    return result;
}

void FileManager::close(const QString& fileName)
{
    auto it = getCurrentFile(fileName);

    if (it != openFiles_.end())
    {
        (*it).reset();
        openFiles_.erase(it);
    }
}

void FileManager::remove(const QString& fileName)
{
    auto it = getCurrentFile(fileName);

    if (it != openFiles_.end())
    {
        (*it)->remove();
        (*it).reset();
        openFiles_.erase(it);
    }
}

std::vector<std::shared_ptr<IFile>>::iterator FileManager::getCurrentFile(const QString& fileName)
{
    return std::find_if(
        openFiles_.begin(),
        openFiles_.end(),
        [&fileName, this](auto file) {
            return utils_->extractFileName(file->fileName()) == fileName;
        });
}

std::vector<std::shared_ptr<IBuffer>>::iterator FileManager::getCurrentBuffer(const QString& fileName)
{
    return std::find_if(
        openBuffers_.begin(),
        openBuffers_.end(),
        [&fileName, this](auto buffer) {
            return utils_->extractFileName(buffer->fileName()) == fileName;
        });
}

void FileManager::loadFileContentToNewBuffer(std::shared_ptr<IFile> file)
{
    auto buffer = std::make_shared<Buffer>(file->fileName());
    openBuffers_.push_back(buffer);

    auto content = file->read();
    buffer->setContent(content);
}

} // ::file
