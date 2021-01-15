/**
 * @author  {\_Sidewinder22_/}
 * @date    22.11.2020
 * 
 * @brief   Quit command handler.
 */

#ifndef SRC_CTRL_CMD_QUITCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_QUITCOMMANDHANDLER_HPP_

#include "log/Logger.hpp"
#include "ICommandHandler.hpp"

namespace ctrl
{
namespace cmd
{

class QuitCommandHandler
    : public ICommandHandler
{
public:
    QuitCommandHandler();
    virtual ~QuitCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;

private:
    log::Logger log_;
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_QUITCOMMANDHANDLER_HPP_ */
