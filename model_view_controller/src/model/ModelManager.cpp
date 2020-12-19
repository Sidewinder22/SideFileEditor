/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#include "ModelManager.hpp"
#include "BufferManager.hpp"
#include "Utils.hpp"

namespace model
{

int ModelManager::nextBufferNumber_ = 1;

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

QString ModelManager::create()
{
    auto bufferName = QString( "Buffer[" );
    bufferName.append( QString::number( nextBufferNumber_++ ) );
    bufferName.append( "]");

	addBuffer(bufferName);
    return bufferName;
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
    
QString ModelManager::read( const QString& bufferName )
{
    log_ << MY_FUNC << bufferName << log::END;

    auto it = getBufferIterator( bufferName );
    if ( it != buffers_.end() )
    {
        return (*it)->read();
    }

    log_ << MY_FUNC << "Buffer not found!" << log::END;
    return {};
}

QString ModelManager::open( const QString& fileName )
{
    log_ << MY_FUNC << fileName << log::END;

    auto file = std::make_shared< FileManager >( fileName );
    auto text = file->read();

    addBuffer( fileName );
    textChanged( fileName, text );

    return text;
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
