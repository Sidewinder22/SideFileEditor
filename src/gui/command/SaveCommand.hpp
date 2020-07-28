/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    SaveCommand.hpp
 *
 * @brief   Class handles save command
 */
#ifndef SRC_GUI_COMMAND_SAVECOMMAND_HPP_
#define SRC_GUI_COMMAND_SAVECOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
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
class SaveCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	SaveCommand(QWidget *parent, QStatusBar* statusBar,
		app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock);
    virtual ~SaveCommand() = default;

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
    QStatusBar* statusBar_;
    app::IMainController* mainController_;
    gui::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_SAVECOMMAND_HPP_ */
