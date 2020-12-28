/**
 * @author  {\_Sidewinder22_/}
 * @date    19.12.2020
 *
 * @brief   File manager
 */

#include "FileManager.hpp"
#include "file/File.hpp"
#include <string>

namespace model
{

FileManager::FileManager( const QString& fileName )
	: log_( std::string("FileManager{ " + fileName.toStdString() + " }") )
{
	try
	{
		file_ = std::make_unique< file::File >( fileName );
	}
	catch ( const std::runtime_error& exception )
	{
		log_ << "Cannot open file! Exception: " << exception.what() << log::END;
	}
}

QString FileManager::name()
{
	return file_->name();
}

QString FileManager::read()
{
	return file_->read();
}

void FileManager::write( const QString& text )
{
	file_->write( text );
}

} // ::model
