/*
 * @author	{\_Sidewinder22_/}
 * @date	9 gru 2020
 * 
 * @brief   Open command handler.
 */

#ifndef SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_

#include "ctrl/ModelController.hpp"
#include "ICommandHandler.hpp"

namespace ctrl {
namespace cmd {

class OpenCommandHandler
    : public ICommandHandler
{
public:
    explicit OpenCommandHandler( ctrl::ModelController* modelController );
    virtual ~OpenCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;

private:
    ctrl::ModelController* modelController_;
};

} // ::cmd
} // ::ctrl


#endif /* SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_ */
