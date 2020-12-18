/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#include "NewCommandHandler.hpp"
#include "OpenCommandHandler.hpp"
#include "AboutCommandHandler.hpp"
#include "QuitCommandHandler.hpp"
#include "CommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

CommandFactory::CommandFactory(  QWidget* parent,
        ModelController* modelController )
    : parent_( parent )
    , modelController_( modelController )
{ }

ICommandHandler& CommandFactory::getNewCommandHandler()
{
    static NewCommandHandler handler( modelController_ );
    return handler;
}

ICommandHandler& CommandFactory::getOpenCommandHandler()
{
    static OpenCommandHandler handler( modelController_ );
    return handler;
}
    
ICommandHandler& CommandFactory::getAboutCommandHandler()
{
    static AboutCommandHandler handler( parent_ );
    return handler;
}

ICommandHandler& CommandFactory::getQuitCommandHandler()
{
    static QuitCommandHandler handler;
    return handler;
}

} // ::cmd
} // ::ctrl
