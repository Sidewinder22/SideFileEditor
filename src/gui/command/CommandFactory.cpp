/**
 * @author  {\_Sidewinder22_/}
 * @date    27 lip 2020
 * @file    CommandFactory.cpp
 *
 * @brief   Factory class reponsible for creating of the command objects
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------

#include "AboutCommand.hpp"
#include "ClearCommand.hpp"
#include "CloseCommand.hpp"
#include "NewCommand.hpp"
#include "OpenCommand.hpp"
#include "QuitCommand.hpp"
#include "RemoveCommand.hpp"
#include "SaveCommand.hpp"
#include "CommandFactory.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

CommandFactory::CommandFactory(QWidget *parent, QTextEdit* textEdit,
		QStatusBar* statusBar, app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock)
	: log_("CommandFactory")
	, parent_(parent)
	, textEdit_(textEdit)
	, statusBar_(statusBar)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

Command& CommandFactory::getNewCommand()
{
	static NewCommand newCommmand(mainController_);
	return newCommmand;
}

Command& CommandFactory::getOpenCommand()
{
	static OpenCommand openCommand(parent_, mainController_, openFileDock_);
	return openCommand;
}

Command& CommandFactory::getSaveCommand()
{
	static SaveCommand saveCommand(parent_, statusBar_, mainController_,
		openFileDock_);
	return saveCommand;
}

Command& CommandFactory::getClearCommand()
{
	static ClearCommand clearCommand(textEdit_);
	return clearCommand;
}

Command& CommandFactory::getCloseCommand()
{
	static CloseCommand closeCommand(parent_, textEdit_, statusBar_,
		mainController_, openFileDock_);
	return closeCommand;
}

Command& CommandFactory::getRemoveCommand()
{
	static RemoveCommand removeCommand(textEdit_, statusBar_, mainController_,
		openFileDock_);
	return removeCommand;
}

Command& CommandFactory::getAboutCommand()
{

	static AboutCommand aboutCommand(parent_);
	return aboutCommand;
}

Command& CommandFactory::getQuitCommand()
{
	static QuitCommand quitCommand(parent_, mainController_);
	return quitCommand;
}

} // ::command
} // ::gui