/*
 * @author	{\_Sidewinder22_/}
 * @date	9 gru 2020
 * 
 * @brief   Open command handler.
 */

#ifndef SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_

#include "ICommandHandler.hpp"

namespace ctrl {
namespace cmd {

class OpenCommandHandler
    : public ICommandHandler
{
public:
    OpenCommandHandler( );
    virtual ~OpenCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;
};

} // ::cmd
} // ::ctrl


#endif /* SRC_CTRL_CMD_OPENCOMMANDHANDLER_HPP_ */
