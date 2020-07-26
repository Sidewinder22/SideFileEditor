/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CommandUtils.cpp
 *
 * @brief  	Class contains useful free functions for commands handling
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QFileDialog>
#include <QMessageBox>
#include "CommandUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

namespace utils
{

QString askUserForFileLocation(QWidget* parent)
{
	return QFileDialog::getSaveFileName(
		parent,
		QObject::tr("Select location for a file"),
		QDir::homePath(),
		QObject::tr("Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json)"));
}

bool askForSaveBuffer(const QString& name)
{
	QMessageBox msgBox;

	msgBox.setText("The file: " + name + " has been modified.");
	msgBox.setInformativeText("Do you want to save your changes?");
	msgBox.setStandardButtons( QMessageBox::Cancel |
		QMessageBox::Discard |
		QMessageBox::Save);
	msgBox.setDefaultButton(QMessageBox::Save);

	int ret = msgBox.exec();
	return ret == QMessageBox::Save;
}

bool saveFile(QWidget* parent, app::IMainController* mainController,
		window::OpenFilesDock* openFileDock)
{
	auto fileName = openFileDock->getCurrentFileName();
	bool success = false;

    if (fileName.contains("Buffer"))
    {
    	auto bufferName = fileName;
    	fileName = askUserForFileLocation(parent);

    	if (!fileName.isEmpty())
    	{
    		int row = openFileDock->getCurrentRow();
    		if (mainController->saveBufferIntoFile(bufferName, fileName))
    		{
    			success = true;

    		    openFileDock->removeFileName(row);
    		}
    	}
    }
    else
    {
    	if (askForSaveBuffer(fileName))
    	{
			if (mainController->save(fileName))
			{
				success = true;
			}
    	}
    }

    return success;
}

} // :: utils

} // ::comand


