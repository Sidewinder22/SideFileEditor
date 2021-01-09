/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#ifndef SRC_CTRL_CONTROLLER_HPP_
#define SRC_CTRL_CONTROLLER_HPP_

#include "log/Logger.hpp"
#include "cmd/ICommandFactory.hpp"
#include "view/ViewManager.hpp"
#include <memory>
#include <QObject>

namespace ctrl
{

class Controller
    : public QObject
{
    Q_OBJECT

public:
    explicit Controller();
    virtual ~Controller() = default;

public slots:
    void create();
    void quit();
    void open( const QString& fileName );
    void save( const QString& bufferName, const QString& text );
	void close( const QString& bufferName );

    void created( const QString& bufferName );
    void opened( const QString& fileName, const QString& text );
    void saved( const QString& bufferName, bool success );
    void closed( const QString& bufferName );
    void read( const QString& text );
    void textChanged( const QString& bufferName, const QString& text );
    void bufferSelectionChanged( const QString& bufferName );
    void getSavePath( const QString& bufferName );
    void savePath( const QString& bufferName, const QString& path );
	void newBufferName( const QString& newBufferName );
    void bufferNotSaved( const QString& bufferName );

signals:
	void createRequest();
	void openRequest( const QString& fileName );
	void readRequest( const QString& bufferName );
	void saveRequest( const QString& bufferName, const QString& text );
	void closeRequest( const QString& bufferName );

    void createdNotif( const QString& bufferName );
    void openedNotif( const QString& fileName, const QString& text );
    void savedNotif( const QString& bufferName, bool success );
    void closedNotif( const QString& bufferName );
    void loadNotif( const QString& text );
    void textChangedNotif( const QString& bufferName, const QString& text );
    void getSavePathRequest( const QString& bufferName );
    void savePathNotif( const QString& bufferName, const QString& path );
	void newBufferNameNotif( const QString& newBufferName );
    void bufferNotSavedNotif( const QString& bufferName );

private:
    log::Logger log_;
    std::unique_ptr< cmd::ICommandFactory > commandFactory_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
