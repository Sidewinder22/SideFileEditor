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
    , window_( new view::Window( commandHandler, dock_ ) )
{
    connect( window_, &view::Window::textChangedSignal, this, &ViewManager::textChanged );
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
}

} // ::view
