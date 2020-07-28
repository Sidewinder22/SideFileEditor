/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CloseCommand.cpp
 *
 * @brief   Class handles close command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QStatusBar>
#include <QMainWindow>
#include "common/Constants.hpp"
#include "CommandUtils.hpp"
#include "CloseCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

CloseCommand::CloseCommand(QWidget *parent, QTextEdit* textEdit,
	QStatusBar* statusBar, app::IMainController* mainController,
	window::OpenFilesDock *openFileDock)
	: log_("CloseCommand")
	, parent_(parent)
	, textEdit_(textEdit)
	, statusBar_(statusBar)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

void CloseCommand::execute()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    auto fileName = openFileDock_->getCurrentFileName();
    if (!mainController_->isFileSaved(fileName) &&
    	!mainController_->isFileEmpty(fileName))
    {
    	utils::saveFile(parent_, mainController_, openFileDock_);
    }

    int row = openFileDock_->getCurrentRow();
    openFileDock_->removeFileName(row);

    if (!fileName.isEmpty())
    {
    	statusBar_->showMessage("File: " + fileName + " closed.",
    			common::constants::STATUS_BAR_MSG_TIMEOUT);
        mainController_->close(fileName);
    }
    else
    {
    	statusBar_->clearMessage();
    }
}

} // ::command
} // ::window
