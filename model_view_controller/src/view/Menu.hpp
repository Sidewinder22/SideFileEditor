/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Menu class.
 */

#ifndef SRC_VIEW_MENU_HPP_
#define SRC_VIEW_MENU_HPP_

#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include "CommandHandler.hpp"

namespace view
{

class Menu
    : public QMenuBar
{
    Q_OBJECT

public:
    Menu( CommandHandler* commandHandler );

private:
    CommandHandler* commandHandler_;

    QMenu* fileMenu_;

	QAction *newAction_;
    QAction *quitAction_;
};

} // ::view

#endif /* SRC_VIEW_MENU_HPP_ */
