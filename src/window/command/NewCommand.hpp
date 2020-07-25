/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    NewCommand.hpp
 *
 * @brief   Class handles new command
 */
#ifndef SRC_WINDOW_COMMAND_NEWCOMMAND_HPP_
#define SRC_WINDOW_COMMAND_NEWCOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "app/IMainController.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class NewCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	NewCommand(app::IMainController* mainController);
    virtual ~NewCommand() = default;

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
    app::IMainController* mainController_;
    static int bufferNumber_;	//!< Number for next buffer to create
};

} // ::command

#endif /* SRC_WINDOW_COMMAND_NEWCOMMAND_HPP_ */
