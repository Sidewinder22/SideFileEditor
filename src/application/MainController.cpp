/**
 * @author  {\_{\_Sidewinder22_/}_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "file/FileManager.hpp"
#include "window/Window.hpp"
#include "MainController.hpp"

//---------------------------------------------------------
//                  Class implementation
//---------------------------------------------------------
MainController::MainController()
    : log_("MainController")
    , window_(std::make_unique<Window>())
    , fileManager_(std::make_unique<FileManager>())
{
    // TODO: Connect slots and signals
}

void MainController::start()
{
	window_->init();
}
