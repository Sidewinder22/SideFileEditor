/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

#ifndef SRC_APPLICATION_MAINCONTROLLER_HPP_
#define SRC_APPLICATION_MAINCONTROLLER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QObject>
#include "file/IFileManager.hpp"
#include "utils/Logger.hpp"
#include "window/IWindow.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class MainController : QObject
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    MainController();

    /**
     * @brief Start app
     */
    void start();

//---------------------------------------------------------
//              Public slots
//---------------------------------------------------------
public slots:

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                                   //!< Logger object
    std::unique_ptr<IWindow> window_;                   //!< Window unique pointer
    std::unique_ptr<IFileManager> fileManager_;         //!< File manager unique pointer
};

#endif /* SRC_APPLICATION_MAINCONTROLLER_HPP_ */
