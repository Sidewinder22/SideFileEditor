/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#ifndef SRC_MODEL_MODELMANAGER_HPP_
#define SRC_MODEL_MODELMANAGER_HPP_

#include <memory>
#include <vector>
#include <QString> 
#include "log/Logger.hpp"
#include "BufferManager.hpp"

namespace model
{

class ModelManager
{
public:
    ModelManager();

    QString create();
    QString read( const QString& bufferName );

    void textChanged( const QString& bufferName, const QString& text );

private:
    std::vector< std::shared_ptr< BufferManager > >::iterator getIterator(
    	const QString& name );

    log::Logger log_;
    static int nextBufferNumber_;

    std::vector< std::shared_ptr< BufferManager > > buffers_;
};

} // ::model

#endif /* SRC_MODEL_MODELMANAGER_HPP_ */
