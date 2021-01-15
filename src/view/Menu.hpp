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
    void createNotif();
    void aboutNotif();
    void openNotif();
    void saveNotif();
    void closeNotif();
    void quitNotif();

private:
    void createActionTriggered();
    void aboutActionTriggered();
    void openActionTriggered();
    void saveActionTriggered();
	void closeActionTriggered();
    void quitActionTriggered();

    QMenu* fileMenu_;
    QMenu* helpMenu_;

	QAction *newAction_;
	QAction *aboutAction_;
	QAction *openAction_;
	QAction *saveAction_;
	QAction *closeAction_;
    QAction *quitAction_;
};

} // ::view

#endif /* SRC_VIEW_MENU_HPP_ */
