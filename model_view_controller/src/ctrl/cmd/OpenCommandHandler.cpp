/*
 * @author	{\_Sidewinder22_/}
 * @date	9 gru 2020
 * 
 * @brief   Open command handler.
 */

#include "OpenCommandHandler.hpp"

namespace ctrl
{
namespace cmd
{
OpenCommandHandler::OpenCommandHandler( ctrl::ModelController* modelController,
		ctrl::ViewController* viewController )
	: modelController_( modelController )
	, viewController_( viewController )
{ }

void OpenCommandHandler::execute()
{
}

} // ::cmd
} // ::ctrl





