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
#include "CommandUtils.hpp"
#include "SaveCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

SaveCommand::SaveCommand(QWidget* parent, app::IMainController* mainController,
	window::OpenFilesDock* openFileDock)
	: log_("SaveCommand")
	, parent_(parent)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

void SaveCommand::execute()
{
    log_ << MY_FUNC << log::END;

//    bool success = false;
//
//    if (fileName.contains("Buffer"))
//    {
//    	auto bufferName = fileName;
//    	fileName = utils::askUserForFileLocation(parent_);
//
//    	if (!fileName.isEmpty())
//    	{
//    		int row = openFileDock_->getCurrentRow();
//    		if (mainController_->saveBufferIntoFile(bufferName, fileName))
//    		{
//    			success = true;
//
//    		    openFileDock_->removeFileName(row);
//    		}
//    	}
//    }
//    else
//    {
//		if (mainController_->save(fileName))
//		{
//    		success = true;
//		}
//    }

    if (utils::saveFile(parent_, mainController_, openFileDock_))
    {
    	auto fileName = openFileDock_->getCurrentFileName();

    	// Cast is necessary because statuBar() method is from
    	// the QMainWindow class not from the QWidget class
		static_cast<QMainWindow>(parent_).statusBar()->showMessage(
			"[File saved]: " + fileName);
		openFileDock_->markCurrentFileAsSaved();
    }
    else
    {
		static_cast<QMainWindow>(parent_).statusBar()->showMessage(
			"Can't save file!");
		QMessageBox::warning(parent_, "INFO", "Cannot save file!");
    }
}

} // ::command
