/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#ifndef SRC_CTRL_CONTROLLER_HPP_
#define SRC_CTRL_CONTROLLER_HPP_

#include <memory>
#include "view/Window.hpp"

namespace ctrl
{

class Controller
{
public:
    Controller();

private:
    std::unique_ptr< view::Window > window_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
