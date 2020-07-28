/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    SaveCommand.cpp
 *
 * @brief   Class handles save command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QString>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include "common/Constants.hpp"
#include "CommandUtils.hpp"
#include "SaveCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

SaveCommand::SaveCommand(QWidget* parent, QStatusBar* statusBar,
		app::IMainController* mainController,
		window::OpenFilesDock* openFileDock)
	: log_("SaveCommand")
	, parent_(parent)
	, statusBar_(statusBar)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

void SaveCommand::execute()
{
    log_ << MY_FUNC << log::END;

    if (utils::saveFile(parent_, mainController_, openFileDock_))
    {
    	auto fileName = openFileDock_->getCurrentFileName();

    	statusBar_->showMessage("[File saved]: " + fileName,
    			common::constants::STATUS_BAR_MSG_TIMEOUT);
		openFileDock_->markCurrentFileAsSaved();
    }
    else
    {
    	statusBar_->showMessage("Can't save file!",
    		common::constants::STATUS_BAR_MSG_TIMEOUT);
		QMessageBox::warning(parent_, "INFO", "Cannot save file!");
    }
}

} // ::command
} // ::window
