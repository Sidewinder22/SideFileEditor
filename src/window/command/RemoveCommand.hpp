/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    RemoveCommand.hpp
 *
 * @brief   Class handles remove command
 */
#ifndef SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_
#define SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QTextEdit>
#include <QStatusBar>
#include "app/IMainController.hpp"
#include "window/OpenFilesDock.hpp"
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
class RemoveCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	RemoveCommand(QTextEdit* textEdit, QStatusBar* statusBar,
		app::IMainController* mainController,
		window::OpenFilesDock *openFileDock);
    virtual ~RemoveCommand() = default;

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
    QTextEdit* textEdit_;
    QStatusBar* statusBar_;
    app::IMainController* mainController_;
    window::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::window

#endif /* SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_ */
