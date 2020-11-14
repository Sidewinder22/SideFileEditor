/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#include "BufferManager.hpp"

namespace model
{

int BufferManager::nextBufferNumber_ = 1;

BufferManager::BufferManager()
    : log_( "BufferManager" )
{ }

QString BufferManager::create()
{
    auto bufferName = "Buffer[" + std::to_string( nextBufferNumber_++ ) + "]";
    log_ << MY_FUNC << ": " << bufferName << log::END;

    return QString::fromStdString( bufferName.c_str() );
}

} // ::model
