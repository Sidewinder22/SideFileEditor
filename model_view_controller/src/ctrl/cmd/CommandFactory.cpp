/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#include "NewCommandHandler.hpp"
#include "CommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

ICommandHandler& CommandFactory::getNewCommandHandler()
{
    static NewCommandHandler handler;
    return handler;
}

} // ::cmd
} // ::ctrl
