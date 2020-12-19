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
#include "FileManager.hpp"

namespace model
{

class ModelManager
{
public:
    ModelManager();

    QString create();
    QString read( const QString& bufferName );
    QString open( const QString& fileName );

    void textChanged( const QString& bufferName, const QString& text );

private:
	void addBuffer( const QString& bufferName );
    std::vector< std::shared_ptr< BufferManager > >::iterator getBufferIterator(
    	const QString& name );
    std::vector< std::shared_ptr< FileManager > >::iterator getFileIterator(
    	const QString& name );

    log::Logger log_;
    static int nextBufferNumber_;

    std::vector< std::shared_ptr< BufferManager > > buffers_;
    std::vector< std::shared_ptr< FileManager > > files_;
};

} // ::model

#endif /* SRC_MODEL_MODELMANAGER_HPP_ */
