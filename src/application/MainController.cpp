/**
 * @author  {\_{\_Sidewinder22_/}_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "window/Window.hpp"
#include "MainController.hpp"

//---------------------------------------------------------
//                  Class implementation
//---------------------------------------------------------
MainController::MainController()
    : log_("MainController")
    , window_(std::make_shared<Window>(this))
    , fileManager_(std::make_shared<FileManager>())
{
    // Nothing
}

void MainController::start()
{
	window_->init();
}

//-----------------------------------------------------
//                  IWindowObserver
//-----------------------------------------------------
void MainController::openFile(const QString& fileName)
{
    bool status = fileManager_->openFile(fileName);

    window_->fileOpened(status, fileName);
}

void MainController::createFile(const QString& fileName)
{
    bool status = fileManager_->openFile(fileName);

    window_->fileCreated(status, fileName);
}
std::vector<QString> MainController::read()
{
    return fileManager_->read();
}

bool MainController::write(const QString& text)
{
    return fileManager_->write(text);
}

void MainController::close()
{
    fileManager_->close();
}

void MainController::remove()
{
    fileManager_->remove();
}
