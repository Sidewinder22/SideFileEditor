/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Toolbar class
 */

#include "ToolBar.hpp"

namespace view
{

ToolBar::ToolBar()
    : newAction_( addAction( QIcon( "../../icons/new.png" ), "New File" ) )
    , openAction_( addAction( QIcon( "../../icons/open.png" ), "Open File" ) )
{
    newAction_->setStatusTip( "New File" );
    openAction_->setStatusTip( "Open File" );

    connect( newAction_,
        &QAction::triggered,
        this,
        &ToolBar::newFile );

    connect( openAction_,
        &QAction::triggered,
        this,
        &ToolBar::open );
}

void ToolBar::newFile()
{
    emit newFileNotif();
}

void ToolBar::open()
{
    emit openNotif();
}

} // ::view
