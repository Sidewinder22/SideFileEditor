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
    : fileMenu_( new QMenu("File"))
    , newAction_( new QAction( "&New", this ) )
    , quitAction_( new QAction( "&Quit", this ) )
{
    addMenu( fileMenu_ );

    fileMenu_->addAction( newAction_ );
    fileMenu_->addAction( quitAction_ );

    newAction_->setShortcuts( QKeySequence::New );
    quitAction_->setShortcuts( QKeySequence::Quit );

    connect( newAction_,
        &QAction::triggered,
        this,
        &Menu::newActionTriggered );

    connect( quitAction_,
        &QAction::triggered,
        this,
        &Menu::quitActionTriggered );
}

void Menu::newActionTriggered()
{
    emit newFileNotif();
}

void Menu::quitActionTriggered()
{
    emit quitNotif();
}

} // ::view
