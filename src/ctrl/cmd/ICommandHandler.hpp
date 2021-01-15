/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers interface.
 */

#ifndef SRC_CTRL_CMD_ICOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_ICOMMANDHANDLER_HPP_

namespace ctrl
{
namespace cmd
{

class ICommandHandler
{
public:
    virtual ~ICommandHandler() = default;

    virtual void execute() = 0;    
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ICOMMANDHANDLER_HPP_ */
