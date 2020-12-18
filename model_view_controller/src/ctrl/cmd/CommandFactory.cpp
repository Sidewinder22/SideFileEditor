/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#include "NewCommandHandler.hpp"
#include "OpenCommandHandler.hpp"
#include "QuitCommandHandler.hpp"
#include "CommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

CommandFactory::CommandFactory( ctrl::ModelController* modelController,
		ctrl::ViewController* viewController )
    : modelController_( modelController )
	, viewController_( viewController )
{ }

ICommandHandler& CommandFactory::getNewCommandHandler()
{
    static NewCommandHandler handler( modelController_ );
    return handler;
}

ICommandHandler& CommandFactory::getOpenCommandHandler()
{
    static OpenCommandHandler handler( modelController_, viewController_ );
    return handler;
}
    
ICommandHandler& CommandFactory::getQuitCommandHandler()
{
    static QuitCommandHandler handler;
    return handler;
}

} // ::cmd
} // ::ctrl
