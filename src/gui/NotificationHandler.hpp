/**
 * @author  {\_Sidewinder22_/}
 * @date    28 lip 2020
 * @file    NotificationHandler.hpp
 *
 * @brief   Class handles notifications
 */
#ifndef SRC_GUI_NOTIFICATIONHANDLER_HPP_
#define SRC_GUI_NOTIFICATIONHANDLER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QWidget>
#include <QTextEdit>
#include <QStatusBar>
#include "app/IMainController.hpp"
#include "common/CommonUtils.hpp"
#include "log/Logger.hpp"
#include "OpenFilesDock.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class NotificationHandler
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	NotificationHandler(QWidget *parent, QTextEdit* textEdit,
		QStatusBar* statusBar, app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock);

	QString opened(bool status, const QString& filePath);
	QString created(const QString& filePath);
	void textChanged();
	QString anotherFileSelected(const QString& fileName);

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

    QTextEdit* textEdit_;
    QStatusBar* statusBar_;
    app::IMainController* mainController_;
    gui::OpenFilesDock *openFileDock_;
    std::unique_ptr<::common::CommonUtils> commonUtils_;
};

} // ::gui

#endif /* SRC_GUI_NOTIFICATIONHANDLER_HPP_ */
