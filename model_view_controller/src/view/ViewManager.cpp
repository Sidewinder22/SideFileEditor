/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#include "ViewManager.hpp"

namespace view
{
    
ViewManager::ViewManager( view::CommandHandler* commandHandler )
    : log_( "ViewManager" )
    , dock_ ( new Dock() )
    , textEdit_( new TextEdit() )
    , window_( new view::Window( commandHandler, dock_, textEdit_ ) )
{
    connect( textEdit_, &QTextEdit::textChanged, this, &ViewManager::textChanged );
}
    
void ViewManager::bufferCreated( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;

    dock_->addName( bufferName );
}

void ViewManager::textChanged()
{
    auto bufferName = dock_->getCurrent();

    log_ << MY_FUNC << "Buff: " << bufferName << log::END;

    auto text = textEdit_->text();
    emit textChangedNotif( bufferName, text );
}

} // ::view
