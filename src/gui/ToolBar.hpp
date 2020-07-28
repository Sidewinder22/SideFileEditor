/**
 * @author  {\_Sidewinder22_/}
 * @date    27 lip 2020
 * @file    ToolBar.hpp
 *
 * @brief   Class creates tool bar functionality
 */
#ifndef SRC_GUI_TOOLBAR_HPP_
#define SRC_GUI_TOOLBAR_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QObject>
#include <QAction>
#include <QToolBar>
#include "log/Logger.hpp"
#include "command/ICommandFactory.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class ToolBar
	: public QObject
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	ToolBar(std::shared_ptr<command::ICommandFactory> commandFactory,
		QToolBar* toolBar);

    virtual ~ToolBar() = default;

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

	QToolBar* toolBar_;

	QAction *newAction_;
	QAction *openAction_;
	QAction *saveAction_;
	QAction *clearScreenAction_;
	QAction *closeAction_;
	QAction *quitAction_;
};

} // ::gui

#endif /* SRC_GUI_TOOLBAR_HPP_ */
