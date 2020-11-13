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
#include "Dock.hpp"
#include "Menu.hpp"
#include "StatusBar.hpp"
#include "TextEdit.hpp"
#include "ToolBar.hpp"

namespace view
{

class Window
    : public QMainWindow
{
public:
    Window();

private:
    std::unique_ptr< view::Menu > menu_;
    std::unique_ptr< view::Dock > dock_;
    std::unique_ptr< view::ToolBar > toolBar_;
    std::unique_ptr< view::StatusBar > statusBar_;
    std::unique_ptr< view::TextEdit > textEdit_;
};

} // ::view

#endif /* SRC_VIEW_WINDOW_HPP_ */