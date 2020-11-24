/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#include <QString>
#include "ViewManager.hpp"

namespace view
{
    
ViewManager::ViewManager()
    : log_( "ViewManager" )
    , dock_( new Dock() )
    , textEdit_( new TextEdit() )
    , menu_( new Menu( ) )
    , toolBar_( new ToolBar( ) )
    , statusBar_( new StatusBar() )
    , window_( new view::Window(
         dock_,
         textEdit_,
         menu_,
         toolBar_,
         statusBar_ ) )
{
    connect( textEdit_,
        &QTextEdit::textChanged,
        this,
        &ViewManager::textChanged );

    connect( dock_,
        &Dock::bufferSelectionChangedNotif,
        this,
        &ViewManager::bufferSelectionChanged );

    connect( menu_,
        &Menu::newFileNotif,
        this,
        &ViewManager::newFile );

    connect( menu_,
        &Menu::quitNotif,
        this,
        &ViewManager::quit );

    connect( toolBar_,
        &ToolBar::newFileNotif,
        this,
        &ViewManager::newFile );
}

void ViewManager::load( const QString& text )
{
    textEdit_->clear();
    textEdit_->setText( text );
}
    
void ViewManager::created( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;

    dock_->addName( bufferName );
    textEdit_->clear();
    window_->setWindowTitle( bufferName );
}

void ViewManager::newFile()
{
    emit newFileNotif();
}

void ViewManager::quit()
{
    emit quitNotif();
}

void ViewManager::textChanged()
{
    auto bufferName = dock_->getCurrent();

    log_ << MY_FUNC << "Buff: " << bufferName << log::END;

    auto text = textEdit_->text();
    emit textChangedNotif( bufferName, text );
}

void ViewManager::bufferSelectionChanged( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;
    emit bufferSelectionChangedNotif( bufferName );
    window_->setWindowTitle( bufferName );
}

} // ::view
