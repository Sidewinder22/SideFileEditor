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
    : window_( std::make_unique< view::Window >() )
    , modelController_( std::make_unique< ModelController >() )
{ }

} // ::ctrl
