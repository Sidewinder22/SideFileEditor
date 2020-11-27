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

namespace view
{

class Menu
    : public QMenuBar
{
    Q_OBJECT

public:
    Menu();

signals:
    void newFileNotif();
    void aboutNotif();
    void openNotif();
    void quitNotif();

private:
    void newActionTriggered();
    void aboutActionTriggered();
    void openActionTriggered();
    void quitActionTriggered();

    QMenu* fileMenu_;
    QMenu* helpMenu_;

	QAction *newAction_;
	QAction *aboutAction_;
	QAction *openAction_;
    QAction *quitAction_;
};

} // ::view

#endif /* SRC_VIEW_MENU_HPP_ */
