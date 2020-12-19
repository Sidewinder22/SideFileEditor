/**
 * @author  {\_Sidewinder22_/}
 * @date    19.11.2020
 * 
 * @brief   Buffer interface
 */

#ifndef SRC_MODEL_BUFF_IBUFFER_HPP_
#define SRC_MODEL_BUFF_IBUFFER_HPP_

#include <QString>

namespace model
{
namespace buff
{

class IBuffer
{
public:
    virtual ~IBuffer() = default;

    virtual void write( const QString &text ) = 0;
    virtual QString read() const = 0;
};

} // ::buff
} // ::model

#endif /* SRC_MODEL_BUFF_IBUFFER_HPP_ */
