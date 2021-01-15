/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#include "QuitCommandHandler.hpp"
#include "CommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

CommandFactory::CommandFactory()
{ }

ICommandHandler& CommandFactory::getQuitCommandHandler()
{
    static QuitCommandHandler handler;
    return handler;
}

} // ::cmd
} // ::ctrl
