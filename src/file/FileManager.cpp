/**
 * @author Sidewinder22
 * @date 11.02.2019
 *
 * @brief FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "File.hpp"
#include "FileManager.hpp"

FileManager::FileManager()
    : log_("FileManager")
{ }

bool FileManager::openFile(const QString& fileName)
{
    log_ << MY_FUNC << "fileName = " << fileName << log::END;
    bool result = false;

    if (file_)
    {
        // TODO: Currently class can operate only on one file at a time
        file_.reset();
    }

    try
    {
        file_ = std::make_shared<File>(fileName);
    }
    catch (const std::runtime_error& e)
    {
        log_ << MY_FUNC << "Cannot open file, error = " << e.what() << log::END;
    }

    if (file_)
    {
        result = true;
    }
    else
    {
        log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
    }

    return result;
}

QString FileManager::fileName() const
{
    QString fileName;

    if (file_)
    {
        fileName = file_->fileName();
    }

    return fileName;
}

std::vector<QString> FileManager::read()
{
    if (file_)
    {
        return file_->read();
    }

    return {};
}

bool FileManager::write(const QString& text)
{
    bool result = false;

    if (file_)
    {
        auto currentFileName = file_->fileName();
        auto tempFile = std::make_shared<File>(currentFileName + ".bcp");

        tempFile->write(text);

        if (file_->remove())
        {
            file_.reset();
            file_ = tempFile;
        }
        else
        {
            log_ << MY_FUNC << "Cannot remove file: " << file_->fileName() << log::END;
        }


        if (!tempFile->rename(currentFileName))
        {
            log_ << MY_FUNC << "Cannot changed fileName!" << log::END;
        }

        result = true;
    }

    return result;
}

bool FileManager::exists()
{
    bool result = false;

    if (file_)
    {
        result = true;
    }

    return result;
}

void FileManager::close()
{
    if (file_)
    {
        file_.reset();
    }
}

void FileManager::remove()
{
    if (file_)
    {
        file_->remove();
        file_.reset();
    }
}
