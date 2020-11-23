/**
 * @author  {\_Sidewinder22_/}
 * @date    19.11.2020
 * 
 * @brief   Buffer State Machine class
 */

#include <memory>
#include "buff/Buffer.hpp"
#include "BufferStateMachine.hpp"

namespace model
{

BufferStateMachine::BufferStateMachine( QString name )
    : log_( "BufferStateMachine" )
    , name_( name )
    , state_( STATE::EMPTY_BUFFER )
    , saved_( false )
    , buffer_( std::make_unique< buff::Buffer> () )
{
    log_ << MY_FUNC << log::END;
}
    
QString BufferStateMachine::name()
{
    return name_;
}

} // ::model
