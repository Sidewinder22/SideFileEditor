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

Controller::Controller()
    : log_( "Controller" )
    , modelController_( std::make_shared< ModelController >() )
    , commandFactory_( std::make_unique< cmd::CommandFactory> (
        modelController_ ) )
{
    connect( modelController_.get(),
        &ModelController::created,
        this,
        &Controller::bufferCreated);
}

void Controller::newFile()
{
    log_ << MY_FUNC << log::END;

    commandFactory_->getNewCommandHandler().execute();
}
    
void Controller::bufferCreated( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;
    emit created( bufferName );
}

} // ::ctrl
