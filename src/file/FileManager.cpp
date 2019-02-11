/**
 * @author Damian Stępień
 * @date 11.02.2019
 *
 * @brief FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "FileManager.hpp"

FileManager::FileManager()
    : log_("FileManager")
{ }

bool FileManager::openFile(const std::string& fileName)
{
    log_ << MY_FUNC << "fileName = " << fileName << log::END;
    bool result = false;

    if (file_)
    {
        // TODO: Currently class can operate only on one file at a time
        file_.reset();
    }

    file_ = std::make_shared<File>(fileName);
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

QString FileManager::getFileName()
{
    QString fileName;

    if (file_)
    {
        fileName = file_->getFileName().c_str();
    }

    return fileName;
}
