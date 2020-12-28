/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#include <QString>
#include "common/Constants.hpp"
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
    , window_( new Window(
         dock_,
         textEdit_,
         menu_,
         toolBar_,
         statusBar_ ) )
	, userInteraction_( new UserInteraction( window_ ) )
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
        &Menu::createNotif,
        this,
        &ViewManager::create );

    connect( menu_,
        &Menu::aboutNotif,
        this,
        &ViewManager::about );

    connect( menu_,
        &Menu::openNotif,
        this,
        &ViewManager::open );

    connect( menu_,
        &Menu::saveNotif,
        this,
        &ViewManager::save );

    connect( menu_,
        &Menu::quitNotif,
        this,
        &ViewManager::quit );

    connect( toolBar_,
        &ToolBar::createNotif,
        this,
        &ViewManager::create );

    connect( toolBar_,
        &ToolBar::openNotif,
        this,
        &ViewManager::open );

    connect( toolBar_,
        &ToolBar::saveNotif,
        this,
        &ViewManager::save );
}

void ViewManager::load( const QString& text )
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();
    textEdit_->setText( text );
}
    
void ViewManager::created( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;

    dock_->addName( bufferName );
    textEdit_->clear();
    window_->setWindowTitle( bufferName );
    statusBar_->showMessage("[New buffer created]: " + bufferName,
        common::constants::STATUS_BAR_MSG_TIMEOUT);
}

void ViewManager::opened( const QString& fileName, const QString& text )
{
    log_ << MY_FUNC << ": " << fileName << log::END;

    dock_->addName( fileName );
    textEdit_->clear();
    textEdit_->setText( text );
    window_->setWindowTitle( fileName );
    statusBar_->showMessage("[File opened]: " + fileName,
        common::constants::STATUS_BAR_MSG_TIMEOUT);
}

void ViewManager::saved( const QString& bufferName, bool success )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;

    statusBar_->showMessage("[File saved]: " + bufferName,
        common::constants::STATUS_BAR_MSG_TIMEOUT);

    window_->setWindowTitle( bufferName );
}

void ViewManager::create()
{
    emit createNotif();
}

void ViewManager::about()
{
	userInteraction_->showAboutInfo();
}

void ViewManager::open()
{
    log_ << MY_FUNC << log::END;

    const auto fileName = userInteraction_->getFileNameForOpen();
    if ( !fileName.isEmpty() )
    {
    	emit openNotif( fileName );
    }
}

void ViewManager::save()
{
    const auto bufferName = dock_->getCurrent();
    log_ << MY_FUNC << "Buff: " << bufferName << log::END;

    const auto text = textEdit_->text();

    emit saveNotif( bufferName, text );
}

void ViewManager::quit()
{
    emit quitNotif();
}

void ViewManager::textChanged()
{
    const auto bufferName = dock_->getCurrent();

    log_ << MY_FUNC << "Buff: " << bufferName << log::END;


    window_->setWindowTitle( "* " + bufferName );

    const auto text = textEdit_->text();
    emit textChangedNotif( bufferName, text );
}

void ViewManager::bufferSelectionChanged( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;

    emit bufferSelectionChangedNotif( bufferName );
    window_->setWindowTitle( bufferName );
    statusBar_->showMessage("[Current buffer]: " + bufferName,
        common::constants::STATUS_BAR_MSG_TIMEOUT);
}

} // ::view
