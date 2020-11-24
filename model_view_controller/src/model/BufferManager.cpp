/**
 * @author  {\_Sidewinder22_/}
 * @date    19.11.2020
 * 
 * @brief   Buffer State Machine class
 */

#include <memory>
#include "buff/Buffer.hpp"
#include "BufferManager.hpp"

namespace model
{

BufferManager::BufferManager( QString name )
    : log_( "BufferManager" )
    , name_( name )
    , saved_( false )
    , buffer_( std::make_unique< buff::Buffer> () )
{
    log_ << MY_FUNC << log::END;
}

QString BufferManager::name()
{
    return name_;
}
    
void BufferManager::write( const QString& text )
{
    log_ << MY_FUNC << name_ << ": " << text << log::END;
    buffer_->write( text );
}

QString BufferManager::read()
{
    return buffer_->read();
}

bool BufferManager::saved()
{
    return saved_;
}
void BufferManager::setSaved( bool saved )
{
    saved_ = saved;
}

} // ::model
