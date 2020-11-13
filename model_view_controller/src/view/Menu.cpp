/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Menu class.
 */

#include "Menu.hpp"

namespace view
{

Menu::Menu()
    : fileMenu_( new QMenu("File"))
{
    addMenu( fileMenu_ );
}

} // ::view
