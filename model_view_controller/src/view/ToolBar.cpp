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
    : new_( addAction( QIcon( "../../icons/new.png" ), "New File" ) )
{
    new_->setStatusTip( "New File" );
}

} // ::view
