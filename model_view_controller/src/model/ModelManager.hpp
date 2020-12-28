/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#ifndef SRC_MODEL_MODELMANAGER_HPP_
#define SRC_MODEL_MODELMANAGER_HPP_

#include "log/Logger.hpp"
#include "BufferManager.hpp"
#include "FileManager.hpp"
#include <QObject>
#include <QString>
#include <memory>
#include <vector>
#include <map>

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
    void save( const QString& bufferName, const QString& text );
    void textChanged( const QString& bufferName, const QString& text );
    void savePath( const QString& bufferName, const QString& path );

signals:
	void createdNotif( const QString& bufferName );
	void openedNotif( const QString& fileName, const QString& text );
	void savedNotif( const QString& bufferName, bool success );
	void readNotif( const QString& text );
	void getSavePathRequest( const QString& bufferName );
	void newBufferNameNotif( const QString& newBufferName );

private:
	void addBuffer( const QString& bufferName );
    std::vector< std::shared_ptr< BufferManager > >::iterator getBufferIterator(
    	const QString& name );
    std::vector< std::shared_ptr< FileManager > >::iterator getFileIterator(
    	const QString& name );

    log::Logger log_;
    static int nextBufferNumber_;
    static const QString BUFFER_STR;

    std::vector< std::shared_ptr< BufferManager > > buffers_;
    std::vector< std::shared_ptr< FileManager > > files_;
    std::map< QString, QString > textsToSave_;
};

} // ::model

#endif /* SRC_MODEL_MODELMANAGER_HPP_ */
