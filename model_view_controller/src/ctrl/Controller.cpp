/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#include "cmd/CommandFactory.hpp"
#include "Controller.hpp"

namespace ctrl
{

Controller::Controller( view::ViewManager* viewManager )
    : log_( "Controller" )
    , modelController_( new ModelController() )
    , viewController_( new ViewController( viewManager ) )
    , commandFactory_( std::make_unique< cmd::CommandFactory> (
        modelController_ ) )
{
    connect( modelController_,
        &ModelController::created,
        this,
        &Controller::bufferCreated);
}

void Controller::newFile()
{
    log_ << MY_FUNC << log::END;

    commandFactory_->getNewCommandHandler().execute();
}

void Controller::quit()
{
    log_ << MY_FUNC << log::END;

    commandFactory_->getQuitCommandHandler().execute();
}
    
void Controller::bufferCreated( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;
    emit created( bufferName );
}

} // ::ctrl
