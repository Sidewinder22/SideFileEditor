/**
 * @author  {\_Sidewinder22_/}
 * @date    20.09.2016
 *
 * @brief   Main Window class
 */

#ifndef SRC_WINDOW_WINDOW_HPP_
#define SRC_WINDOW_WINDOW_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QMenu>
#include <QLabel>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMainWindow>
#include <QVBoxLayout>
#include "file/FileManager.hpp"
#include "utils/Logger.hpp"
#include "utils/Utils.hpp"
#include "IOpenFilesDockObserver.hpp"
#include "IWindow.hpp"
#include "IWindowObserver.hpp"
#include "OpenFilesDock.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Window
    : public QMainWindow
    , public IWindow
    , public IOpenFilesDockObserver
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	Window(IWindowObserver* observer, QWidget *parent = 0);
	virtual ~Window() = default;

    //-----------------------------------------------------
    //                  IWindow
    //-----------------------------------------------------
    /**
     * @brief Prepare class behaviour
     */
	void init() override;

    /**
     * @brief openFile() response
     * @param status Status of operation
     */
    void fileOpened(bool status, const QString& fileName) override;

    /**
     * @brief createFile() response
     * @param status Status of operation
     * @param fileName fileName of the created file
     */
    void fileCreated(bool status, const QString& fileName) override;

    //-----------------------------------------------------
    //              IOpenFilesDockObserver
    //-----------------------------------------------------
    /**
     * @brief Notification that another file has been selected
     * @param fileName fileName of the created file
     */
    void anotherFileSelected(const QString& fileName) override;


//---------------------------------------------------------
//              Public slots
//---------------------------------------------------------
public slots:
    /**
     * @brief Open file and add it to the container
     */
	void openFile();

    /**
     * @brief Select file name for new file
     */
	void newFile();

    /**
     * @brief Save file
     */
    void saveFile();

    /**
     * @brief Close file
     */
    void closeFile();

    /**
     * @brief Remove file
     */
    void removeFile();

    /**
     * @brief Clear screen
     */
    void clearScreen();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    /**
     * @brief Connect signals to the proper slots
     */
	void connectSignalsToSlots();

    /**
     * @brief Prepare tool bar
     */
	void buildToolBar();

    /**
     * @brief Show window with about description
     */
    void showAboutWindow();

    log::Logger log_;                                   //!< Logger object
	QMenu *fileMenu_;                                   //!< Pointer to file menu object
	QMenu *helpMenu_;                                   //!< Pointer to help menu object

	QAction *toolBNew_;                                 //!< Pointer to the tool bar new file command
	QAction *toolBOpen_;                                //!< Pointer to the tool bar open file command
	QAction *toolBSave_;                                //!< Pointer to the tool bar save file command
	QAction *toolBClear_;                               //!< Pointer to the tool bar clear screen command
	QAction *toolBClose_;                               //!< Pointer to the tool bar close file command
	QAction *toolBTrash_;                               //!< Pointer to the tool bar trash file command
	QAction *toolBQuit_;                                //!< Pointer to the tool bar quit command
	QToolBar *toolBar_;                                 //!< Pointer to the tool bar

	QTextEdit *textEdit_;                               //!< Pointer to the text edit field
	QFileDialog *fileDialog_;                           //!< Pointer to the file dialog field

    OpenFilesDock *openFileDock_;                       //!< Open files dock

    std::unique_ptr<utils::Utils> utils_;               //!< Pointer to utils object
    IWindowObserver* observer_;                         //!< Pointer to the observer
};

#endif /* SRC_WINDOW_WINDOW_HPP_ */
