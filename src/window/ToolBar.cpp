/**
 * @author  {\_Sidewinder22_/}
 * @date    27 lip 2020
 * @file    ToolBar.cpp
 *
 * @brief   Class creates tool bar functionality
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include "ToolBar.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

ToolBar::ToolBar(std::shared_ptr<command::ICommandFactory> commandFactory,
		QToolBar* toolBar)
	: log_("ToolBar")
	, commandFactory_(commandFactory)
	, toolBar_(toolBar)
	, newAction_(nullptr)
	, openAction_(nullptr)
	, saveAction_(nullptr)
	, clearScreenAction_(nullptr)
	, closeAction_(nullptr)
	, quitAction_(nullptr)
{
	// Nothing
}

void ToolBar::init()
{
	newAction_ = toolBar_->addAction(QIcon("icons/new.png"), "New File");
	openAction_ = toolBar_->addAction(QIcon("icons/open.png"), "Open File");
	saveAction_ = toolBar_->addAction(QIcon("icons/save.png"), "Save File");
	clearScreenAction_ = toolBar_->addAction(QIcon("icons/clear.png"),
		"Clear Screen");
	closeAction_ = toolBar_->addAction(QIcon("icons/close.png"), "Close File");

	toolBar_->addSeparator();

	quitAction_ = toolBar_->addAction(QIcon("icons/quit.png"),
		"Quit Application");

	newAction_->setStatusTip("New File");
	openAction_->setStatusTip("Open File");
	saveAction_->setStatusTip("Save File");
	clearScreenAction_->setStatusTip("Clear Screen");
	closeAction_->setStatusTip("Close File");
	quitAction_->setStatusTip("Quit Application");

	connectSignalsToSlots();
}

void ToolBar::connectSignalsToSlots()
{
	connect(newAction_, &QAction::triggered, this, &ToolBar::newFile);
	connect(openAction_, &QAction::triggered, this, &ToolBar::openFile);
	connect(saveAction_, &QAction::triggered, this, &ToolBar::saveFile);
	connect(clearScreenAction_, &QAction::triggered, this, &ToolBar::clearScreen);
	connect(closeAction_, &QAction::triggered, this, &ToolBar::closeFile);
	connect(quitAction_, &QAction::triggered, this, &ToolBar::quitApplication);
}

void ToolBar::newFile()
{
	commandFactory_->getNewCommand().execute();
}

void ToolBar::openFile()
{
	commandFactory_->getOpenCommand().execute();
}

void ToolBar::saveFile()
{
	commandFactory_->getSaveCommand().execute();
}

void ToolBar::clearScreen()
{
	commandFactory_->getClearCommand().execute();
}

void ToolBar::closeFile()
{
	commandFactory_->getCloseCommand().execute();
}

void ToolBar::quitApplication()
{
	commandFactory_->getQuitCommand().execute();
}

} // ::window
