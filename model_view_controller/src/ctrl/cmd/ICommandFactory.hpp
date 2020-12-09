/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory interface.
 */

#ifndef SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_
#define SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_

#include "ICommandHandler.hpp"

namespace ctrl
{
namespace cmd
{

class ICommandFactory
{
public:
    virtual ~ICommandFactory() = default;

    virtual ICommandHandler& getNewCommandHandler() = 0;    
    virtual ICommandHandler& getOpenCommandHandler() = 0;
    virtual ICommandHandler& getAboutCommandHandler() = 0;
    virtual ICommandHandler& getQuitCommandHandler() = 0;    
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_ */
