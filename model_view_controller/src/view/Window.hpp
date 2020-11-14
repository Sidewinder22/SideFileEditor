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
#include "Dock.hpp"
#include "Menu.hpp"
#include "StatusBar.hpp"
#include "TextEdit.hpp"
#include "ToolBar.hpp"
#include "CommandHandler.hpp"

namespace view
{

class Window
    : public QMainWindow
{
public:
    Window( std::shared_ptr< CommandHandler > commandHandler );

private:
    log::Logger log_;
    std::unique_ptr< Menu > menu_;
    std::unique_ptr< Dock > dock_;
    std::unique_ptr< ToolBar > toolBar_;
    std::unique_ptr< StatusBar > statusBar_;
    std::unique_ptr< TextEdit > textEdit_;
};

} // ::view

#endif /* SRC_VIEW_WINDOW_HPP_ */