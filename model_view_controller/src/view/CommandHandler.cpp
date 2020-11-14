/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handler class.
 */

#include "CommandHandler.hpp"

namespace view
{
    
CommandHandler::CommandHandler()
    : log_( "CommandHandler" )
{ }

void CommandHandler::newFile()
{
    log_ << MY_FUNC << log::END;

    emit newFileRequested();
}
    
} // ::view
