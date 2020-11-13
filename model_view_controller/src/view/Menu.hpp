/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Menu class.
 */

#ifndef SRC_VIEW_MENU_HPP_
#define SRC_VIEW_MENU_HPP_

#include <QMenu>
#include <QMenuBar>

namespace view
{

class Menu
    : public QMenuBar
{
public:
    Menu();

private:
    QMenu* fileMenu_;
};

} // ::view

#endif /* SRC_VIEW_MENU_HPP_ */
