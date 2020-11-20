/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Toolbar class
 */

#include "ToolBar.hpp"

namespace view
{

ToolBar::ToolBar( CommandHandler* commandHandler )
    : commandHandler_ ( commandHandler )
    , newAction_( addAction( QIcon( "../../icons/new.png" ), "New File" ) )
{
    newAction_->setStatusTip( "New File" );

    connect( newAction_, &QAction::triggered, this, &ToolBar::newFile );
}

void ToolBar::newFile()
{
    commandHandler_->newFile();
}

} // ::view
