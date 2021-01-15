/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main window class.
 */

#ifndef SRC_VIEW_WINDOW_HPP_
#define SRC_VIEW_WINDOW_HPP_

#include <memory>
#include <QMainWindow>
#include "log/Logger.hpp"
#include "Menu.hpp"
#include "Dock.hpp"
#include "StatusBar.hpp"
#include "TextEdit.hpp"
#include "ToolBar.hpp"

namespace view
{

class Window
    : public QMainWindow
{
    Q_OBJECT

public:
    Window( Dock* dock,
        TextEdit* textEdit,
        Menu* menu,
        ToolBar* toolBar,
        StatusBar* statusBar );

private:
    log::Logger log_;
    Dock* dock_;
    TextEdit* textEdit_;
    Menu* menu_;
    ToolBar* toolBar_;
    StatusBar* statusBar_;
};

} // ::view

#endif /* SRC_VIEW_WINDOW_HPP_ */
