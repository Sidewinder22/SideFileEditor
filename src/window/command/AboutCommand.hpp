/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    AboutCommand.hpp
 *
 * @brief   Class handles about command
 */
#ifndef SRC_WINDOW_COMMAND_ABOUTCOMMAND_HPP_
#define SRC_WINDOW_COMMAND_ABOUTCOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QWidget>
#include "log/Logger.hpp"
#include "Command.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class AboutCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	AboutCommand(QWidget *parent);
    virtual ~AboutCommand() = default;

	//-----------------------------------------------------
	//               Command
	//-----------------------------------------------------
    void execute() override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;
    QWidget* parent_;

    constexpr static const char* ABOUT = "     About     \n";
    constexpr static const char* APP = "     SideFileEditor\n";
    constexpr static const char* BY = "             by\n";
    constexpr static const char* AUTHOR = "{\\_Sidewinder22_/}";
};

} // ::command
} // ::window

#endif /* SRC_WINDOW_COMMAND_ABOUTCOMMAND_HPP_ */
