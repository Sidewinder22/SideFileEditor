/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    RemoveCommand.cpp
 *
 * @brief   Class handles remove command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QStatusBar>
#include <QMainWindow>
#include "common/Constants.hpp"
#include "CommandUtils.hpp"
#include "RemoveCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

RemoveCommand::RemoveCommand(QTextEdit* textEdit, QStatusBar* statusBar,
		app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock)
	: log_("RemoveCommand")
	, textEdit_(textEdit)
	, statusBar_(statusBar)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

void RemoveCommand::execute()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    int row = openFileDock_->getCurrentRow();
    auto fileName = openFileDock_->getCurrentFileName();

    openFileDock_->removeFileName(row);

    if (!fileName.isEmpty())
    {
    	statusBar_->showMessage("File: " + fileName + " removed.",
    		common::constants::STATUS_BAR_MSG_TIMEOUT);
        mainController_->remove(fileName);
    }
    else
    {
    	statusBar_->clearMessage();
    }
}

} // ::command
} // ::gui
