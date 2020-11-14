/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#include "Controller.hpp"

namespace ctrl
{

Controller::Controller()
    : log_( "Controller" )
    , modelController_( std::make_unique< ModelController >() )
{ }

void Controller::newFile()
{
    log_ << MY_FUNC << log::END;
}

} // ::ctrl
