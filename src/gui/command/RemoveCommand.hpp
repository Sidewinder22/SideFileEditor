/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    RemoveCommand.hpp
 *
 * @brief   Class handles remove command
 */
#ifndef SRC_GUI_COMMAND_REMOVECOMMAND_HPP_
#define SRC_GUI_COMMAND_REMOVECOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QTextEdit>
#include <QStatusBar>
#include "app/IMainController.hpp"
#include "gui/OpenFilesDock.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
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
		gui::OpenFilesDock *openFileDock);
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
    gui::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_REMOVECOMMAND_HPP_ */
