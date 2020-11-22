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

Controller::Controller( ModelController* modelController,
        ViewController* viewController )
    : log_( "Controller" )
    , modelController_( modelController )
    , viewController_( viewController )
    , commandFactory_( std::make_unique< cmd::CommandFactory> (
        modelController_ ) )
{ }

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
    
} // ::ctrl
