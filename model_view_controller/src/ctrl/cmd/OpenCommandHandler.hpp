/*
 * @author	{\_Sidewinder22_/}
 * @date	9 gru 2020
 * 
 * @brief   Open command handler.
 */

#ifndef SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_

#include "ctrl/ModelController.hpp"
#include "ctrl/ViewController.hpp"
#include "ICommandHandler.hpp"

namespace ctrl {
namespace cmd {

class OpenCommandHandler
    : public ICommandHandler
{
public:
    OpenCommandHandler( ctrl::ModelController* modelController,
    	ctrl::ViewController* viewController );
    virtual ~OpenCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;

private:
    ctrl::ModelController* modelController_;
    ctrl::ViewController* viewController_;
};

} // ::cmd
} // ::ctrl


#endif /* SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_ */
