/**
 * @author  {\_Sidewinder22_/}
 * @date    28 lip 2020
 * @file    NotificationHandler.cpp
 *
 * @brief   Class handles notifications
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QStatusBar>
#include <QMessageBox>
#include <QMainWindow>
#include "common/Constants.hpp"
#include "NotificationHandler.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

NotificationHandler::NotificationHandler(QWidget *parent, QTextEdit* textEdit,
	QStatusBar* statusBar,
	app::IMainController* mainController, window::OpenFilesDock *openFileDock)
	: log_("NotificationHandler")
	, parent_(parent)
	, textEdit_(textEdit)
	, statusBar_(statusBar)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
	, utils_(std::make_unique<common::Utils>())
{
	// Nothing
}

QString NotificationHandler::opened(bool status, const QString& filePath)
{
    log_ << MY_FUNC << log::END;
    QString windowTitle;

    if (!filePath.isEmpty())
    {
        if (status)
        {
            auto fileName = utils_->extractFileName(filePath);
            openFileDock_->addFileName(fileName);

            textEdit_->clear();

            auto fileContent = mainController_->read(fileName);
            for (auto&& line : fileContent)
            {
                textEdit_->append(line);
            }

            statusBar_->showMessage("[Open file]: " + filePath,
            	common::constants::STATUS_BAR_MSG_TIMEOUT);
            windowTitle = filePath;
        }
        else
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;

            QMessageBox::information(parent_, "ERROR", "Can't open file!!!");
            statusBar_->showMessage("Cannot open file!!!" + filePath,
            	common::constants::STATUS_BAR_MSG_TIMEOUT);
        }
    }

    return windowTitle;
}

QString NotificationHandler::created(const QString& filePath)
{
    log_ << MY_FUNC << log::END;

	openFileDock_->addFileName(utils_->extractFileName(filePath));

	statusBar_->showMessage("[New]: " + filePath,
		common::constants::STATUS_BAR_MSG_TIMEOUT);
	return filePath;
}

void NotificationHandler::textChanged()
{
    auto fileName = openFileDock_->getCurrentFileName();
    if (!fileName.isEmpty())
    {
		auto text = textEdit_->toPlainText();
		bool fileContentChanged = false;

		if (!text.isEmpty())
		{
			fileContentChanged = mainController_->textChanged(fileName, text);
		}

		if (fileContentChanged)
		{
			openFileDock_->markCurrentFileAsUnsaved();
		}
    }
}

QString NotificationHandler::anotherFileSelected(const QString& fileName)
{
    log_ << MY_FUNC << log::END;

	statusBar_->showMessage("[Current file]: " + fileName,
		common::constants::STATUS_BAR_MSG_TIMEOUT);
	textEdit_->clear();

	auto fileContent = mainController_->read(utils_->extractFileName(fileName));
	for (auto&& line : fileContent)
	{
		textEdit_->append(line);
	}

	return fileName;
}

} // ::window
