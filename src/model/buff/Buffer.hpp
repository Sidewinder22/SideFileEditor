/**
 * @author  {\_Sidewinder22_/}
 * @date    20.11.2020
 * 
 * @brief   Buffer class
 */

#ifndef SRC_MODEL_BUFF_BUFFER_HPP_
#define SRC_MODEL_BUFF_BUFFER_HPP_

#include "IBuffer.hpp"

namespace model
{
namespace buff
{

class Buffer
    : public IBuffer
{
public:
    Buffer();
    virtual ~Buffer() = default;

    /******************************************************
     *                      IBuffer
    ******************************************************/
    void write( const QString &text ) override;
    QString read() const override;

private:
    QString text_;
};

} // ::buff
} // ::model

#endif /* SRC_MODEL_BUFF_BUFFER_HPP_ */
