/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#ifndef SRC_VIEW_VIEWMANAGER_HPP_
#define SRC_VIEW_VIEWMANAGER_HPP_

#include "log/Logger.hpp"
#include "view/Window.hpp"
#include "Dock.hpp"
#include "TextEdit.hpp"
#include "UserInteraction.hpp"
#include <QObject>
#include <QString>

namespace view
{

class ViewManager
    : public QObject
{
    Q_OBJECT

public:
    ViewManager();
    virtual ~ViewManager() = default;


public slots:
    void create();
    void about();
    void open();
    void save();
    void close();
    void quit();
    void load( const QString& text );

    void created( const QString& bufferName );
    void opened( const QString& fileName, const QString& text );
    void saved( const QString& bufferName, bool success );
    void closed( const QString& bufferName );
    void textChanged();
    void bufferSelectionChanged( const QString& bufferName );
    void getSavePath( const QString& bufferName );
	void newBufferName( const QString& newBufferName );

signals:
    void createRequest();
    void openRequest( const QString& fileName );
    void saveRequest( const QString& fileName, const QString& text );
    void closeRequest( const QString& bufferName );
    void quitRequest();

    void textChangedNotif( const QString& bufferName, const QString& text );
    void bufferSelectionChangedNotif( const QString& bufferName );
    void savePathNotif( const QString& bufferName, const QString& path );

private:
    log::Logger log_;
    Dock* dock_;
    TextEdit* textEdit_;
    Menu* menu_;
    ToolBar* toolBar_;
    StatusBar* statusBar_;
    view::Window* window_;
    UserInteraction* userInteraction_;
};

} // ::view

#endif /* SRC_VIEW_VIEWMANAGER_HPP_ */
