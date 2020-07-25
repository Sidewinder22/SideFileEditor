#ifndef SRC_WINDOW_WINDOW_HPP_
#define SRC_WINDOW_WINDOW_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    20.09.2016
 *
 * @brief   Main Window class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QMenu>
#include <QLabel>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QMainWindow>

#include "command/Command.hpp"

#include "app/IMainController.hpp"
#include "file/FileManager.hpp"
#include "log/Logger.hpp"
#include "utils/Utils.hpp"
#include "IOpenFilesDockObserver.hpp"
#include "IWindow.hpp"
#include "OpenFilesDock.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

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
	Window(app::IMainController* mainController, QWidget *parent = 0);
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
     * @param fileName fileName of the created file
     */
    void fileCreated(const QString& fileName) override;

    /**
     * @brief createBuffer() response
     * @param bufferName name of the created buffer
     */
    void bufferCreated(const QString& bufferName) override;

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

    /**
     * @brief Text changed
     */
    void textChanged();

    /**
     * @brief Quit from the application
     */
    void quitApplication();

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
     * @brief Prepare Menu
     */
	void prepareMenu();

    /**
     * @brief Prepare tool bar
     */
	void prepareToolBar();

    /**
     * @brief Show window with about description
     */
    void showAboutWindow();

    /**
     * @brief Verify which unsaved buffers should be saved.
     */
    void verifyUnsavedBuffers();

    bool askForSaveBuffer(const QString& name);
    QString askUserForFileLocation();

    log::Logger log_;                                   //!< Logger object
	QMenu *fileMenu_;                                   //!< Pointer to file menu object
	QMenu *helpMenu_;                                   //!< Pointer to help menu object

	QAction *toolBNew_;                                 //!< Pointer to the tool bar new file command
	QAction *toolBOpen_;                                //!< Pointer to the tool bar open file command
	QAction *toolBSave_;                                //!< Pointer to the tool bar save file command
	QAction *toolBClear_;                               //!< Pointer to the tool bar clear screen command
	QAction *toolBClose_;                               //!< Pointer to the tool bar close file command
	QAction *toolBQuit_;                                //!< Pointer to the tool bar quit command
	QToolBar *toolBar_;                                 //!< Pointer to the tool bar

	QAction *menuNewFile_;								//!< Pointer to the menu new file command
	QAction *menuOpenFile_;								//!< Pointer to the menu open file command
	QAction *menuSaveFile_;								//!< Pointer to the menu save file command
	QAction *menuClearScreen_;							//!< Pointer to the menu clear screen command
	QAction *menuCloseFile_;							//!< Pointer to the menu close file command
	QAction *menuRemoveFile_;							//!< Pointer to the menu remove file command
	QAction *menuQuit_;									//!< Pointer to the menu quit command
    QAction *menuAbout_;								//!< Pointer to the menu about command

	QTextEdit *textEdit_;                               //!< Pointer to the text edit field

    OpenFilesDock *openFileDock_;                       //!< Open files dock

    std::unique_ptr<utils::Utils> utils_;               //!< Pointer to utils object
    app::IMainController* mainController_;              //!< Pointer to the observer

    std::unique_ptr<command::Command> clearCommand_;
    std::unique_ptr<command::Command> openCommand_;
    std::unique_ptr<command::Command> aboutCommand_;
    std::unique_ptr<command::Command> newCommand_;
};

} // ::window

#endif /* SRC_WINDOW_WINDOW_HPP_ */
