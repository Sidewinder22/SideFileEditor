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
#include "file/FileManager.hpp"
#include "utils/Logger.hpp"
#include "window/Window.hpp"
#include "window/IWindowObserver.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class MainController
    : public QObject
    , public IWindowObserver
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
//                  Protected
//---------------------------------------------------------
protected:
    //-----------------------------------------------------
    //                  IWindowObserver
    //-----------------------------------------------------
    /**
     * @brief Open file
     * @param fileName path for file
     * @return True if successfull, Fale otherwise
     */
    bool openFile(const QString& fileName) override;

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    std::vector<QString> read() override;

    /**
     * @brief Write data to file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    bool write(const QString& text) override;

    /**
     * @brief Close open file
     */
    void close() override;

    /**
     * @brief Remove file
     */
    void remove() override;

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                                   //!< Logger object
    std::shared_ptr<Window> window_;                    //!< Window unique pointer
    std::shared_ptr<FileManager> fileManager_;          //!< File manager unique pointer

};

#endif /* SRC_APPLICATION_MAINCONTROLLER_HPP_ */
