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

Menu::Menu( std::shared_ptr< CommandHandler > commandHandler )
    : commandHandler_( commandHandler )
    , fileMenu_( new QMenu("File"))
    , newAction_( new QAction( "&New", this ) )
{
    addMenu( fileMenu_ );

    fileMenu_->addAction( newAction_ );

    newAction_->setShortcuts( QKeySequence::New );

    connect( newAction_, &QAction::triggered, this, &Menu::newFile );
}

void Menu::newFile()
{
    commandHandler_->newFile();
}

} // ::view
