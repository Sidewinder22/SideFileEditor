/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Menu class.
 */

#include "QKeySequence"
#include "Menu.hpp"

namespace view
{

Menu::Menu()
    : fileMenu_( new QMenu("&File"))
    , helpMenu_( new QMenu("&Help"))
    , newAction_( new QAction( "&New", this ) )
    , aboutAction_( new QAction( "&About", this ) )
    , openAction_( new QAction( "&Open", this ) )
    , saveAction_( new QAction( "&Save", this ) )
    , quitAction_( new QAction( "&Quit", this ) )
{
    addMenu( fileMenu_ );
    addMenu( helpMenu_ );

    fileMenu_->addAction( newAction_ );
    fileMenu_->addAction( openAction_ );
    fileMenu_->addAction( saveAction_ );
    fileMenu_->addSeparator();
    fileMenu_->addAction( quitAction_ );

    helpMenu_->addAction( aboutAction_ );

    newAction_->setShortcuts( QKeySequence::New );
    openAction_->setShortcuts( QKeySequence::Open );
    saveAction_->setShortcuts( QKeySequence::Save );
    aboutAction_->setShortcuts( QKeySequence::WhatsThis );
    quitAction_->setShortcuts( QKeySequence::Quit );

    connect( newAction_,
        &QAction::triggered,
        this,
        &Menu::newActionTriggered );

    connect( aboutAction_,
        &QAction::triggered,
        this,
        &Menu::aboutActionTriggered );

    connect( openAction_,
        &QAction::triggered,
        this,
        &Menu::openActionTriggered );

    connect( saveAction_,
        &QAction::triggered,
        this,
        &Menu::saveActionTriggered );

    connect( quitAction_,
        &QAction::triggered,
        this,
        &Menu::quitActionTriggered );
}

void Menu::newActionTriggered()
{
    emit newFileNotif();
}

void Menu::aboutActionTriggered()
{
    emit aboutNotif();
}

void Menu::openActionTriggered()
{
    emit openNotif();
}

void Menu::saveActionTriggered()
{
	emit saveNotif();
}

void Menu::quitActionTriggered()
{
    emit quitNotif();
}

} // ::view
