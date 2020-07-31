/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    FileManager.cpp
 *
 * @brief   File manager
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "File.hpp"
#include "FileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

FileManager::FileManager()
    : log_("FileManager")
	, contentUtils_(std::make_unique<ContentUtils>())
{
	// Nothing
}

bool FileManager::open(const QString& fileName)
{
    bool success = false;

    auto file = create(fileName);
    if (file)
    {
        files_.push_back(file);
        success = true;
    }
    else
    {
        log_ << MY_FUNC << "Cannot create File class object!!!" << log::END;
    }

    return success;
}

std::vector<QString> FileManager::read(const QString& fileName)
{
    auto it = getIterator(fileName);
    if (it != files_.end())
    {
        return (*it)->read();
    }
    else
    {
    	log_ << MY_FUNC << "file not found!" << log::END;
    }

    return {};
}

std::shared_ptr<IFile> FileManager::create(const QString& fileName)
{
    std::shared_ptr<IFile> file;
    try
    {
        file = std::make_shared<File>(fileName);
    }
    catch (const std::runtime_error& e)
    {
        log_ << MY_FUNC << "Cannot open file, error = " << e.what() << log::END;
    }

    return file;
}

std::vector<std::shared_ptr<IFile>>::iterator
	FileManager::getIterator(const QString& fileName)
{
    return contentUtils_->getVectorIterator<IFile>(
        fileName,
        files_.begin(),
        files_.end());
}

} // ::content


