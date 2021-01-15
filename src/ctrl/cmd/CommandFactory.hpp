/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#ifndef SRC_CTRL_CMD_COMMANDFACTORY_HPP_
#define SRC_CTRL_CMD_COMMANDFACTORY_HPP_

#include "ICommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

class CommandFactory
    : public ICommandFactory
{
public:
    CommandFactory();
    virtual ~CommandFactory() = default;

    /**********************************************
     *              ICommandFactory
    **********************************************/
    ICommandHandler& getQuitCommandHandler() override;
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_ */
