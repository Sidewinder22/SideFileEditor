/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main window class.
 */

#include <QScreen>
#include <QGuiApplication>
#include "Window.hpp"

namespace view
{

Window::Window( CommandHandler* commandHandler, Dock* dock, TextEdit* textEdit )
    : QMainWindow()
    , log_( "Window" )
    , menu_( new Menu( commandHandler ) )
    , toolBar_( new ToolBar( commandHandler ) )
    , statusBar_(new StatusBar() )
    , textEdit_( textEdit )
{
    setMenuBar( menu_ );
    addToolBar( toolBar_ );
    addDockWidget( Qt::TopDockWidgetArea, dock );
    setStatusBar( statusBar_ );

    setCentralWidget( textEdit_ );

    setWindowTitle( "{\\_SideFileEditor_/}" );

    // Display center window
	QScreen *screen = QGuiApplication::primaryScreen();
	move(screen->geometry().center() - frameGeometry().center());

    resize( 900, 600 );
    show();

    statusBar_->showMessage( "Ready!" );

    log_ << MY_FUNC << "Window created" << log::END;
}

} // ::view