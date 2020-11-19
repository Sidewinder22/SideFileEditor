/**
 * @author  {\_Sidewinder22_/}
 * @date    20.11.2020
 * 
 * @brief   Buffer class
 */

#include <iostream>
#include "Buffer.hpp"

namespace model
{
namespace buff
{
    
Buffer::Buffer()
    : text_( "" )
{ }

void Buffer::write( const QString &text )
{
    text_ = text;
}

QString Buffer::read() const
{
    return text_;
}

} // ::buff
} // ::model