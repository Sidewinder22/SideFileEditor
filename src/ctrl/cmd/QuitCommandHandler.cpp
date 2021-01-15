/**
 * @author  {\_Sidewinder22_/}
 * @date    22.11.2020
 * 
 * @brief   Quit command handler.
 */

#include <QApplication>
#include "QuitCommandHandler.hpp"

namespace ctrl
{
namespace cmd
{

QuitCommandHandler::QuitCommandHandler()
    : log_( "QuitCommandHandler" )
{ }

void QuitCommandHandler::execute()
{
    log_ << FUNC << "Bye..." << log::END;

    QApplication::quit();
}

} // ::cmd
} // ::ctrl
