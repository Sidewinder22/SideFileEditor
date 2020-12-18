/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#ifndef SRC_CTRL_CMD_COMMANDFACTORY_HPP_
#define SRC_CTRL_CMD_COMMANDFACTORY_HPP_

#include "ctrl/ModelController.hpp"
#include "ctrl/ViewController.hpp"
#include "ICommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

class CommandFactory
    : public ICommandFactory
{
public:
    CommandFactory( ctrl::ModelController* modelController,
    	ctrl::ViewController* viewController );
    virtual ~CommandFactory() = default;

    /**********************************************
     *              ICommandFactory
    **********************************************/
    ICommandHandler& getNewCommandHandler() override;
    ICommandHandler& getOpenCommandHandler() override;
    ICommandHandler& getQuitCommandHandler() override;

private:
    ctrl::ModelController* modelController_;
    ctrl::ViewController* viewController_;
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_ */
