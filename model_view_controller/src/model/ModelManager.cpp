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
    log_ << MY_FUNC << "Created." << log::END;
}

void ModelManager::addBuffer( const QString& bufferName)
{
	log_ << MY_FUNC << ": " << bufferName << log::END;

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
    log_ << MY_FUNC << bufferName <<  ": " << text << log::END;

    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        (*it)->write( text );
    }
}
    
void ModelManager::read( const QString& bufferName )
{
    log_ << MY_FUNC << bufferName << log::END;

    QString text;
    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        text = (*it)->read();
    }
    else
    {
    	log_ << MY_FUNC << "Buffer not found!" << log::END;
    }

    emit readNotif( text );
}

void ModelManager::open( const QString& fileName )
{
    log_ << MY_FUNC << fileName << log::END;

    auto file = std::make_shared< FileManager >( fileName );
    files_.push_back( file );

    const auto text = file->read();

    addBuffer( fileName );
    textChanged( fileName, text );

    emit openedNotif( fileName, text );
}

void ModelManager::save( const QString& bufferName, const QString& text )
{
    log_ << MY_FUNC << bufferName << log::END;

    bool success = false;

    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
    	auto fileIt = getFileIterator( bufferName );
    	if ( fileIt != files_.end() )
    	{
    		log_ << MY_FUNC << bufferName
    			<< ", saving file: " << text << log::END;
    		( *fileIt )->save( text );
    	}
    	else
    	{
    		// TODO: create new file and save content

    		log_ << MY_FUNC << bufferName
    			<< ", create new file and save" << log::END;
    	}
    }

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
