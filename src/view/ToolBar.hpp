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
    Q_OBJECT

public:
    ToolBar();

public slots:
    void create();
    void open();
    void save();
    void close();

signals:
    void createNotif();
    void openNotif();
    void saveNotif();
    void closeNOtif();

private:
    QAction* newAction_;
    QAction* openAction_;
    QAction* saveAction_;
    QAction* closeAction_;
};

} // ::view

#endif /* SRC_VIEW_TOOLBAR_HPP_ */
