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
#include "ModelController.hpp"

namespace ctrl
{

class Controller
{
public:
    Controller();

private:
    std::unique_ptr< view::Window > window_;
    std::unique_ptr< ModelController > modelController_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
