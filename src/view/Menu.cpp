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
    : fileMenu_( new QMenu( "&File" ))
    , viewMenu_( new QMenu( "&View" ))
    , helpMenu_( new QMenu( "&Help" ))
    , newAction_( new QAction( "&New", this ) )
    , aboutAction_( new QAction( "&About", this ) )
    , openAction_( new QAction( "&Open", this ) )
    , saveAction_( new QAction( "&Save", this ) )
	, closeAction_( new QAction( "&Close", this ))
    , quitAction_( new QAction( "&Quit", this ) )
    , changeToolBarShowAction_( new QAction( "&Show toolbar", this ))
{
    addMenu( fileMenu_ );
    addMenu( viewMenu_ );
    addMenu( helpMenu_ );

    fileMenu_->addAction( newAction_ );
    fileMenu_->addAction( openAction_ );
    fileMenu_->addAction( saveAction_ );
    fileMenu_->addAction( closeAction_ );
    fileMenu_->addSeparator();
    fileMenu_->addAction( quitAction_ );

    viewMenu_->addAction( changeToolBarShowAction_ );

    helpMenu_->addAction( aboutAction_ );

    newAction_->setShortcuts( QKeySequence::New );
    openAction_->setShortcuts( QKeySequence::Open );
    saveAction_->setShortcuts( QKeySequence::Save );
    closeAction_->setShortcut( QKeySequence::Close );
    aboutAction_->setShortcuts( QKeySequence::WhatsThis );
    quitAction_->setShortcuts( QKeySequence::Quit );

    changeToolBarShowAction_->setCheckable( true );
    changeToolBarShowAction_->setChecked( true );

    connect( newAction_,
        &QAction::triggered,
        this,
        &Menu::createActionTriggered );

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

    connect( closeAction_,
        &QAction::triggered,
        this,
        &Menu::closeActionTriggered );

    connect( quitAction_,
        &QAction::triggered,
        this,
        &Menu::quitActionTriggered );

    connect( changeToolBarShowAction_,
        &QAction::toggled,
        this,
        &Menu::changeToolBarShowTriggered );
}

void Menu::createActionTriggered()
{
    emit createNotif();
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

void Menu::closeActionTriggered()
{
	emit closeNotif();
}

void Menu::quitActionTriggered()
{
    emit quitNotif();
}

void Menu::changeToolBarShowTriggered( bool checked )
{
    emit changeToolBarShowNotif( checked );
}

} // ::view
