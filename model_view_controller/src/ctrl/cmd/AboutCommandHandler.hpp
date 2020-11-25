/*
 * @author	{\_Sidewinder22_/}
 * @date	25 lis 2020
 * 
 * @brief   About command handler
 */

#ifndef SRC_CTRL_CMD_ABOUTCOMMANDHANDLER_HPP_
#define SRC_CTRL_CMD_ABOUTCOMMANDHANDLER_HPP_

#include <string>
#include <QWidget>
#include "ICommandHandler.hpp"

namespace ctrl {
namespace cmd {

class AboutCommandHandler
    : public ICommandHandler
{
public:
    AboutCommandHandler( QWidget* parent );
    virtual ~AboutCommandHandler() = default;

    /**********************************************
     *              ICommandHandler
    **********************************************/
    void execute() override;

private:
    QWidget* parent_;

    constexpr static const char* ABOUT = "     About     \n";
    constexpr static const char* APP = "     SideFileEditor\n";
    constexpr static const char* BY = "             by\n";
    constexpr static const char* AUTHOR = "{\\_Sidewinder22_/}";
};

} // ::cmd
} // ::ctrl

#endif /* SRC_CTRL_CMD_ABOUTCOMMANDHANDLER_HPP_ */
