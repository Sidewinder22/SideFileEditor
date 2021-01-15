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
    : newAction_( addAction( QIcon( "../icons/new.png" ), "New File" ) )
    , openAction_( addAction( QIcon( "../icons/open.png" ), "Open File" ) )
    , saveAction_( addAction( QIcon( "../icons/save.png" ), "Save File" ) )
    , closeAction_( addAction( QIcon( "../icons/close.png" ), "Close File" ) )
{
    newAction_->setStatusTip( "New File" );
    openAction_->setStatusTip( "Open File" );
    saveAction_->setStatusTip( "Save File" );
    closeAction_->setStatusTip( "Close File" );

    connect( newAction_,
        &QAction::triggered,
        this,
        &ToolBar::create );

    connect( openAction_,
        &QAction::triggered,
        this,
        &ToolBar::open );

    connect( saveAction_,
        &QAction::triggered,
        this,
        &ToolBar::save );

    connect( closeAction_,
        &QAction::triggered,
        this,
        &ToolBar::close );
}

void ToolBar::create()
{
    emit createNotif();
}

void ToolBar::open()
{
    emit openNotif();
}

void ToolBar::save()
{
	emit saveNotif();
}

void ToolBar::close()
{
	emit closeNOtif();
}

} // ::view
