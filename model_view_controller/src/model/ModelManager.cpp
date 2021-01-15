/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#include "ModelManager.hpp"
#include "BufferManager.hpp"
#include "Utils.hpp"
#include <memory>

namespace model
{

int ModelManager::nextBufferNumber_ = 1;
const QString ModelManager::BUFFER_STR = "Buffer";

ModelManager::ModelManager()
    : log_( "ModelManager" )
{
    log_ << FUNC << "Created." << log::END;
}

void ModelManager::addBuffer( const QString& bufferName)
{
	log_ << FUNC << ": " << bufferName << log::END;

	auto buffer = std::make_shared< BufferManager >( bufferName );
	buffers_.push_back(buffer);
}

void ModelManager::create()
{
    auto bufferName = QString( "Buffer[" );
    bufferName.append( QString::number( nextBufferNumber_++ ) );
    bufferName.append( "]");

	addBuffer( bufferName );
	emit createdNotif( bufferName );
}
    
void ModelManager::textChanged( const QString& bufferName,
    const QString& text )
{
    log_ << FUNC << bufferName <<  ": " << text << log::END;

    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        (*it)->write( text );
    }
}
    
void ModelManager::read( const QString& bufferName )
{
    log_ << FUNC << bufferName << log::END;

    QString text;
    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        text = (*it)->read();
    }
    else
    {
    	log_ << FUNC << "Buffer not found!" << log::END;
    }

    emit readNotif( text );
}

void ModelManager::open( const QString& fileName )
{
    log_ << FUNC << fileName << log::END;

    auto file = std::make_shared< FileManager >( fileName );
    files_.push_back( file );

    const auto text = file->read();

    addBuffer( fileName );
    textChanged( fileName, text );

    emit openedNotif( fileName, text );
}

void ModelManager::save( const QString& bufferName, const QString& text )
{
    log_ << FUNC << bufferName << log::END;

    const auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
    	auto fileIt = getFileIterator( bufferName );
    	if ( fileIt != files_.end() )
    	{
    		log_ << FUNC << bufferName
    			<< ", file exists in the files_ container, saving file: "
				<< text << log::END;

            const auto currentFileName = ( *fileIt )->name();
            const auto tempFileMgr =
                std::make_shared< FileManager >( currentFileName + ".bcp" );

            tempFileMgr->write( text );

            if ( ( *fileIt )->remove() )
            {
                ( *fileIt ).reset();
                ( *fileIt ) = tempFileMgr;
            }
            else
            {
                log_ << FUNC << "Can't remove file: "
                    << ( *fileIt )->name() << log::END;
            }

            if ( !( *fileIt )->rename( currentFileName) )
            {
                log_ << FUNC << "Cannot changed fileName!" << log::END;
            }

            log_ << FUNC << bufferName << ", file saved +" << log::END;
    		emit savedNotif( bufferName, true );
    	}
    	else
    	{
    		log_ << FUNC << bufferName
    			<< ", file doesn't exists, request new file path" << log::END;
    		textsToSave_.insert( { bufferName, text } );
    		emit getSavePathRequest( bufferName );
    	}
    }
    else
    {
        log_ << FUNC << bufferName
            << " buffer doesn't exists!" << log::END;
        // TODO: emit error
    }
}

void ModelManager::close( const QString& bufferName )
{
	log_ << FUNC << bufferName << log::END;

    const auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        (*it).reset();
        buffers_.erase(it);
    }
    const auto fileIt = getFileIterator( bufferName );
    if ( fileIt != files_.end() )
    {
        ( *fileIt ).reset();
        files_.erase( fileIt );
    }

    emit closedNotif( bufferName );
}

void ModelManager::savePath( const QString& bufferName, const QString& path )
{
	log_ << FUNC << path << log::END;
	bool success = true;

	std::shared_ptr< FileManager > fileManager;
	try
	{
		fileManager = std::make_shared< FileManager >( path );
	}
	catch ( const std::runtime_error& e )
	{
		success = false;
		log_ << FUNC << "Can't create file, error: "
			<< e.what() << log::END;
	}

	const auto textIt = textsToSave_.find( bufferName );
	if ( textIt != textsToSave_.end() )
	{
		fileManager->write( textIt->second );
		textsToSave_.erase( textIt );
	}
	else
	{
		success = false;
		log_ << FUNC << "Can't find text for buffer: "
			<< bufferName << log::END;
	}

	const auto bufferIt = getBufferIterator( bufferName );
	if ( bufferIt != buffers_.end() )
	{
		( *bufferIt )->setName( path );
	}
	else
	{
		success = false;
		log_ << FUNC << "Can't find buffer: "
			<< bufferName << log::END;
	}

	files_.push_back( fileManager );

	emit newBufferNameNotif( path );
    emit savedNotif( bufferName, success );
}

std::vector< std::shared_ptr< BufferManager > >::iterator 
    ModelManager::getBufferIterator( const QString& name )
{
    return utils::getVectorIterator< BufferManager >(
        name,
        buffers_.begin(),
        buffers_.end() );
}

std::vector< std::shared_ptr< FileManager > >::iterator
	ModelManager::getFileIterator( const QString& name )
{
	return utils::getVectorIterator< FileManager >(
        name,
        files_.begin(),
        files_.end() );
}

} // ::model
