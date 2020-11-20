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

NewCommandHandler::NewCommandHandler( ctrl::ModelController* modelController )
    : modelController_( modelController )
{ }

void NewCommandHandler::execute()
{
    modelController_->create();
}

} // ::cmd
} // ::ctrl
