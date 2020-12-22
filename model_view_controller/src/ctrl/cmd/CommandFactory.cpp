/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#include "NewCommandHandler.hpp"
#include "QuitCommandHandler.hpp"
#include "CommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

CommandFactory::CommandFactory( ctrl::ModelController* modelController)
    : modelController_( modelController )
{ }

ICommandHandler& CommandFactory::getNewCommandHandler()
{
    static NewCommandHandler handler( modelController_ );
    return handler;
}

ICommandHandler& CommandFactory::getQuitCommandHandler()
{
    static QuitCommandHandler handler;
    return handler;
}

} // ::cmd
} // ::ctrl
