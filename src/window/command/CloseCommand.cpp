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
	app::IMainController* mainController, window::OpenFilesDock *openFileDock)
	: log_("CloseCommand")
	, parent_(parent)
	, textEdit_(textEdit)
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
        static_cast<QMainWindow>(parent_).statusBar()->showMessage(
        	"File: " + fileName + " closed.");
        mainController_->close(fileName);
    }
    else
    {
        static_cast<QMainWindow>(parent_).statusBar()->clearMessage();
    }
}

} // ::command
} // ::window
