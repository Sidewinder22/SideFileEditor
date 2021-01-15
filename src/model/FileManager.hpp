/**
 * @author  {\_Sidewinder22_/}
 * @date    19.12.2020
 *
 * @brief   File manager
 */

#ifndef SRC_MODEL_FILEMANAGER_HPP_
#define SRC_MODEL_FILEMANAGER_HPP_

#include "file/IFile.hpp"
#include "log/Logger.hpp"
#include <QString>
#include <memory>

namespace model
{

class FileManager
{
public:
	FileManager( const QString& fileName );
	QString name();
    bool rename( const QString& newName );
	QString read();
    void write( const QString& text );
    bool remove();

private:
	log::Logger log_;
	std::unique_ptr< file::IFile > file_;
};

} // ::model

#endif /* SRC_MODEL_FILEMANAGER_HPP_ */
