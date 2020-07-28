/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CloseCommand.hpp
 *
 * @brief   Class handles close command
 */

#ifndef SRC_GUI_COMMAND_CLOSECOMMAND_HPP_
#define SRC_GUI_COMMAND_CLOSECOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
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
class CloseCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	CloseCommand(QWidget *parent, QTextEdit* textEdit,
		QStatusBar* statusBar,
		app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock);

    virtual ~CloseCommand() = default;

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
    QTextEdit* textEdit_;
	QStatusBar* statusBar_;
    app::IMainController* mainController_;
    gui::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_CLOSECOMMAND_HPP_ */
