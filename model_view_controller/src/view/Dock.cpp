/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Dock for open files.
 */

#include "Dock.hpp"

namespace view
{

Dock::Dock()
{
    setStatusTip( "Open files list" );
    setFloating( false );
    setAllowedAreas( Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea );
}

} // ::view
