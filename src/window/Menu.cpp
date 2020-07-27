/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    Menu.cpp
 *
 * @brief   Class creating menu functionality
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QMainWindow>
#include "Menu.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

Menu::Menu(std::shared_ptr<command::ICommandFactory> commandFactory,
		QMenuBar* menuBar)
	: log_("Menu")
	, commandFactory_(commandFactory)
	, fileMenu_(new QMenu("File"))
	, helpMenu_(new QMenu("Help"))
 	, newAction_(new QAction("&New", this))
	, openAction_(new QAction("&Open", this))
	, saveAction_(new QAction("&Save", this))
	, menuClearScreen_(new QAction("&Clear screen", this))
	, menuCloseFile_(new QAction("&Close", this))
	, menuRemoveFile_(new QAction("&Remove", this))
	, aboutAction_(new QAction("&About", this))
	, quitAction_(new QAction("&Quit", this))
{
	menuBar->addMenu(fileMenu_);
	menuBar->addMenu(helpMenu_);
}

void Menu::init()
{
	fileMenu_->addAction(newAction_);
	fileMenu_->addAction(openAction_);
	fileMenu_->addAction(saveAction_);
	fileMenu_->addAction(menuClearScreen_);
	fileMenu_->addAction(menuCloseFile_);
	fileMenu_->addAction(menuRemoveFile_);
    fileMenu_->addSeparator();
	fileMenu_->addAction(quitAction_);

    helpMenu_->addAction(aboutAction_);

    QKeySequence newShortcut("Ctrl+N");
    QKeySequence openShortcut("Ctrl+O");
    QKeySequence saveShortcut("Ctrl+S");
    QKeySequence clearScreenShortcut("Ctrl+L");
    QKeySequence closeShortcut("Ctrl+W");
    QKeySequence removeShortcut("Ctrl+R");
    QKeySequence quitShortcut("Ctrl+Q");

    newAction_->setShortcut(newShortcut);
    openAction_->setShortcut(openShortcut);
    saveAction_->setShortcut(saveShortcut);
    menuClearScreen_->setShortcut(clearScreenShortcut);
    menuCloseFile_->setShortcut(closeShortcut);
    menuRemoveFile_->setShortcut(removeShortcut);
    quitAction_->setShortcut(quitShortcut);

	connectSignalsToSlots();
}

void Menu::connectSignalsToSlots()
{
	connect(newAction_, &QAction::triggered, this, &Menu::newFile);
	connect(openAction_, &QAction::triggered, this, &Menu::openFile);
	connect(saveAction_, &QAction::triggered, this, &Menu::saveFile);
	connect(menuClearScreen_, &QAction::triggered, this, &Menu::clearScreen);
	connect(menuCloseFile_, &QAction::triggered, this, &Menu::closeFile);
	connect(menuRemoveFile_, &QAction::triggered, this, &Menu::removeFile);
	connect(aboutAction_, &QAction::triggered, this, &Menu::showAboutMessage);
	connect(quitAction_, &QAction::triggered, this, &Menu::quitApplication);
}

void Menu::newFile()
{
	commandFactory_->getNewCommand().execute();
}

void Menu::openFile()
{
	commandFactory_->getOpenCommand().execute();
}

void Menu::saveFile()
{
	commandFactory_->getSaveCommand().execute();
}

void Menu::clearScreen()
{
	commandFactory_->getClearCommand().execute();
}

void Menu::closeFile()
{
	commandFactory_->getCloseCommand().execute();
}

void Menu::removeFile()
{
	commandFactory_->getRemoveCommand().execute();
}

void Menu::showAboutMessage()
{
	commandFactory_->getAboutCommand().execute();
}

void Menu::quitApplication()
{
	commandFactory_->getQuitCommand().execute();
}

} // ::window
