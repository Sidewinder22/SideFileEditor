/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#ifndef SRC_VIEW_VIEWMANAGER_HPP_
#define SRC_VIEW_VIEWMANAGER_HPP_

#include <QObject>
#include <QString>
#include "log/Logger.hpp"
#include "view/Window.hpp"
#include "Dock.hpp"
#include "TextEdit.hpp"

namespace view
{

class ViewManager
    : public QObject
{
    Q_OBJECT

public:
    ViewManager();
    virtual ~ViewManager() = default;

    void created( const QString& bufferName );
    void load( const QString& text );

public slots:
    void newFile();
    void quit();
    void textChanged();
    void bufferSelectionChanged( const QString& bufferName );

signals:
    void newFileNotif();
    void quitNotif();
    void textChangedNotif( const QString& bufferName, const QString& text );
    void bufferSelectionChangedNotif( const QString& bufferName );

private:
    log::Logger log_;
    Dock* dock_;
    TextEdit* textEdit_;
    Menu* menu_;
    ToolBar* toolBar_;
    StatusBar* statusBar_;
    view::Window* window_;
};

} // ::view

#endif /* SRC_VIEW_VIEWMANAGER_HPP_ */
