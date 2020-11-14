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
    Menu( std::shared_ptr< CommandHandler > commandHandler );

public slots:
    void newFile();

private:
    std::shared_ptr< CommandHandler > commandHandler_;

    QMenu* fileMenu_;

	QAction *newAction_;
};

} // ::view

#endif /* SRC_VIEW_MENU_HPP_ */
