/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   New command handler.
 */

#include "NewCommandHandler.hpp"

namespace ctrl
{
namespace cmd
{

NewCommandHandler::NewCommandHandler()
    : log_( "NewCommandHandler" )
{ }

void NewCommandHandler::execute()
{
    log_ << MY_FUNC << log::END;
}

} // ::cmd
} // ::ctrl
