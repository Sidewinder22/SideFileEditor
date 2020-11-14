/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handlers factory class.
 */

#ifndef SRC_CTRL_CMD_COMMANDFACTORY_HPP_
#define SRC_CTRL_CMD_COMMANDFACTORY_HPP_

#include "ctrl/ModelController.hpp"
#include "ICommandFactory.hpp"

namespace ctrl
{
namespace cmd
{

class CommandFactory
    : public ICommandFactory
{
public:
    CommandFactory( std::shared_ptr< ModelController > modelController );
    virtual ~CommandFactory() = default;

    /**********************************************
     *              ICommandFactory
    **********************************************/
    ICommandHandler& getNewCommandHandler() override;

private:
    std::shared_ptr< ModelController > modelController_;
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ICOMMANDFACTORY_HPP_ */