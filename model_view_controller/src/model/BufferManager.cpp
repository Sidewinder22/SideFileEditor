/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#include "BufferManager.hpp"
#include "BufferStateMachine.hpp"

namespace model
{

int BufferManager::nextBufferNumber_ = 1;

BufferManager::BufferManager()
    : log_( "BufferManager" )
{ }

QString BufferManager::create()
{
    auto bufferName = QString( "Buffer[" );
    bufferName.append( QString::number( nextBufferNumber_++ ) );
    bufferName.append( "]");

    log_ << MY_FUNC << ": " << bufferName << log::END;

    auto buffer = std::make_unique< BufferStateMachine >( bufferName );
    buffers_.push_back( std::move( buffer ) );

    return bufferName;
}

} // ::model
