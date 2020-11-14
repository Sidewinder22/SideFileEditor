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

Window::Window( std::shared_ptr< CommandHandler > commandHandler )
    : QMainWindow()
    , log_( "Window" )
    , menu_( std::make_unique< view::Menu >( commandHandler ) )
    , dock_( std::make_unique< view::Dock >() )
    , toolBar_( std::make_unique< view::ToolBar >( commandHandler ) )
    , statusBar_( std::make_unique< view::StatusBar >() )
    , textEdit_( std::make_unique< view::TextEdit >() )
{
    setMenuBar( menu_.get() );
    addToolBar( toolBar_.get() );
    addDockWidget( Qt::TopDockWidgetArea, dock_.get() );
    setStatusBar( statusBar_.get() );

    setCentralWidget( textEdit_.get() );

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