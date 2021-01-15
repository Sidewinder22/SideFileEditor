/**
 * @author  {\_Sidewinder22_/}
 * @date    19.11.2020
 * 
 * @brief   Buffer State Machine class
 */

#ifndef SRC_MODEL_BUFFERMANAGER_HPP_
#define SRC_MODEL_BUFFERMANAGER_HPP_

#include <memory>
#include <QString>
#include "buff/IBuffer.hpp"
#include "log/Logger.hpp"

namespace model 
{

class BufferManager 
{
public:
    BufferManager( QString name );
    virtual ~BufferManager() = default;

    void write( const QString& text );
    QString name();
    QString read();
    bool saved();
    void setSaved( bool saved );
    void setName( const QString& name );

private:
    log::Logger log_;
    QString name_;
    bool saved_;
    std::unique_ptr< buff::IBuffer > buffer_;
};

} // ::model

#endif /* SRC_MODEL_BUFFERMANAGER_HPP_ */
