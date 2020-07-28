/**
 * @author  {\_Sidewinder22_/}
 * @date    28 lip 2020
 * @file    NotificationHandler.hpp
 *
 * @brief   Class handles notifications
 */
#ifndef SRC_WINDOW_NOTIFICATIONHANDLER_HPP_
#define SRC_WINDOW_NOTIFICATIONHANDLER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
#include <QTextEdit>
#include "common/Utils.hpp"
#include "app/IMainController.hpp"
#include "log/Logger.hpp"
#include "window/OpenFilesDock.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
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
		window::OpenFilesDock *openFileDock);

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
    window::OpenFilesDock *openFileDock_;
    std::unique_ptr<common::Utils> utils_;
};

} // ::window

#endif /* SRC_WINDOW_NOTIFICATIONHANDLER_HPP_ */
