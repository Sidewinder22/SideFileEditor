/**
 * @author  {\_Sidewinder22_/}
 * @date    19.11.2020
 * 
 * @brief   Buffer State Machine class
 */

#ifndef SRC_MODEL_BUFFERSTATEMACHINE_HPP_
#define SRC_MODEL_BUFFERSTATEMACHINE_HPP_

#include <memory>
#include <QString>
#include "buff/IBuffer.hpp"
#include "log/Logger.hpp"

namespace model 
{

class BufferStateMachine 
{
public:
    BufferStateMachine( QString name );

    QString name();

private:
    enum class STATE {
        EMPTY_BUFFER,
        WAIT_FOR_DATA,
        READ,
        REMOVE
    };

    log::Logger log_;
    QString name_;
    STATE state_;
    bool saved_;
    std::unique_ptr< buff::IBuffer > buffer_;
};

} // ::model

#endif /* SRC_MODEL_BUFFERSTATEMACHINE_HPP_ */
