/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    Menu.hpp
 *
 * @brief   Class creating menu functionality
 */
#ifndef SRC_WINDOW_MENU_HPP_
#define SRC_WINDOW_MENU_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QMenu>
#include <QObject>
#include <QAction>
#include <QMenuBar>
#include "app/IMainController.hpp"
#include "log/Logger.hpp"
#include "command/ICommandFactory.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Menu
	: public QObject
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	Menu(std::shared_ptr<command::ICommandFactory> commandFactory,
		QMenuBar* menuBar);

    virtual ~Menu() = default;

    void init();

//---------------------------------------------------------
//              Public slots
//---------------------------------------------------------
public slots:
	void newFile();
	void openFile();
	void saveFile();
	void clearScreen();
	void closeFile();
	void removeFile();
	void showAboutMessage();
	void quitApplication();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    void connectSignalsToSlots();

    log::Logger log_;
	std::shared_ptr<command::ICommandFactory> commandFactory_;

	QMenu *fileMenu_;
	QMenu *helpMenu_;

	QAction *newAction_;
	QAction *openAction_;
	QAction *saveAction_;
	QAction *menuClearScreen_;
	QAction *menuCloseFile_;
	QAction *menuRemoveFile_;
    QAction *aboutAction_;
	QAction *quitAction_;
};

} // ::window

#endif /* SRC_WINDOW_MENU_HPP_ */
