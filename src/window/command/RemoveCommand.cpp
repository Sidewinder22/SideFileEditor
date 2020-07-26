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
#include "CommandUtils.hpp"
#include "RemoveCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

RemoveCommand::RemoveCommand(QWidget *parent, QTextEdit* textEdit,
	app::IMainController* mainController, window::OpenFilesDock *openFileDock)
	: log_("RemoveCommand")
	, parent_(parent)
	, textEdit_(textEdit)
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
        static_cast<QMainWindow>(parent_).statusBar()->showMessage(
        	"File: " + fileName + " removed.");
        mainController_->remove(fileName);
    }
    else
    {
        static_cast<QMainWindow>(parent_).statusBar()->clearMessage();
    }
}

} // ::command
} // ::window
