/**
 * @author  {\_Sidewinder22_/}
 * @date    11.02.2019
 *
 * @brief   FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "File.hpp"
#include "FileManager.hpp"

FileManager::FileManager()
    : log_("FileManager")
    , utils_(std::make_unique<utils::Utils>())
{ }

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
    for (auto& file : openFiles_)
    {
        if (file->fileName() == fileName)
        {
            return file->read();
        }
    }

    return {};
}

bool FileManager::write(const QString& fileName, const QString& text)
{
    bool result = false;
    auto it = getCurrentFile(fileName);

    if (it != openFiles_.end())
    {
        if (utils_->extractFileName((*it)->fileName()) == fileName)
        {
            auto currentFileName = (*it)->fileName();
            auto tempFile = std::make_shared<File>(currentFileName + ".bcp");

            tempFile->write(text);

            if ((*it)->remove())
            {
                (*it).reset();
                (*it) = tempFile;
            }
            else
            {
                log_ << MY_FUNC << "Cannot remove file: " << (*it)->fileName() << log::END;
            }

            if (!(*it)->rename(currentFileName))
            {
                log_ << MY_FUNC << "Cannot changed fileName!" << log::END;
            }

            result = true;
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
