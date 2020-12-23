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
#include <QObject>
#include <QString> 
#include "log/Logger.hpp"
#include "BufferManager.hpp"
#include "FileManager.hpp"

namespace model
{

class ModelManager
	: public QObject
{
	Q_OBJECT

public:
    ModelManager();
    virtual ~ModelManager() = default;

public slots:
    void create();
    void open( const QString& fileName );
    void read( const QString& bufferName );
    void textChanged( const QString& bufferName, const QString& text );

signals:
	void createdNotif( const QString& bufferName );
	void openedNotif( const QString& fileName, const QString& text );
	void readNotif( const QString& text );

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
