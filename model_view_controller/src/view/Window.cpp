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

Window::Window( Dock* dock,
        TextEdit* textEdit,
        Menu* menu,
        ToolBar* toolBar,
        StatusBar* statusBar )
    : QMainWindow()
    , log_( "Window" )
    , dock_( dock )
    , textEdit_( textEdit )
    , menu_( menu )
    , toolBar_( toolBar )
    , statusBar_( statusBar )
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
