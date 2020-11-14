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
#include "CommandHandler.hpp"

namespace view
{

class ToolBar
    : public QToolBar
{
    Q_OBJECT

public:
    ToolBar( std::shared_ptr< CommandHandler > commandHandler );

public slots:
    void newFile();

private:
    std::shared_ptr< CommandHandler > commandHandler_;

    QAction* newAction_;
};

} // ::view

#endif /* SRC_VIEW_TOOLBAR_HPP_ */
