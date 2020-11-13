/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Toolbar class
 */

#ifndef SRC_VIEW_TOOLBAR_HPP_
#define SRC_VIEW_TOOLBAR_HPP_

#include <QAction>
#include <QToolBar>

namespace view
{

class ToolBar
    : public QToolBar
{
public:
    ToolBar();

private:
    QAction* new_;
};

} // ::view

#endif /* SRC_VIEW_TOOLBAR_HPP_ */
