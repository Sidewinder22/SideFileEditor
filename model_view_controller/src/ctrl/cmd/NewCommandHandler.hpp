/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   New command handler.
 */

#ifndef SRC_CTRL_CMD_NEWCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_NEWCOMMANDHANDLER_HPP_

#include "ctrl/ModelController.hpp"
#include "ICommandHandler.hpp"

namespace ctrl
{
namespace cmd
{

class NewCommandHandler
    : public ICommandHandler
{
public:
    explicit NewCommandHandler( ctrl::ModelController* modelController );
    virtual ~NewCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;

private:
    ctrl::ModelController* modelController_;
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_NEWCOMMANDHANDLER_HPP_ */
