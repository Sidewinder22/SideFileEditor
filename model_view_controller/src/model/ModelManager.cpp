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
    
QString ModelManager::create()
{
    auto bufferName = QString( "Buffer[" );
    bufferName.append( QString::number( nextBufferNumber_++ ) );
    bufferName.append( "]");

    log_ << MY_FUNC << ": " << bufferName << log::END;

    auto buffer = std::make_shared< BufferManager >( bufferName );
    buffers_.push_back( buffer );

    return bufferName;
}
    
void ModelManager::textChanged( const QString& bufferName,
    const QString& text )
{
    log_ << MY_FUNC << bufferName <<  ": " << text << log::END;

    auto it = getIterator( bufferName );
    if ( it != buffers_.end() )
    {
        (*it)->write( text );
    }
}

std::vector< std::shared_ptr< BufferManager > >::iterator 
    ModelManager:: getIterator( const QString& name )
{
    return utils::getVectorIterator< BufferManager >(
        name,
        buffers_.begin(),
        buffers_.end() );
}

} // ::model
