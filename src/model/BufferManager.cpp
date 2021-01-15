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
    log_ << FUNC << log::END;
}

QString BufferManager::name()
{
    return name_;
}
    
void BufferManager::write( const QString& text )
{
    log_ << FUNC << name_ << ": " << text << log::END;

    const auto currentText = buffer_->read();

    if ( text.isEmpty() &&
         currentText.isEmpty() )
    {
        log_ << FUNC << name_ << ": empty buffer and empty text" << log::END;
        return;
    }

    buffer_->write( text );
    saved_ = false;
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

void BufferManager::setName( const QString& name )
{
	name_ = name;
}

} // ::model
