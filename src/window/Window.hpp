/**
 * @author Damian Stępień
 * @date 20.09.2016
 *
 * @brief Main Window class
 */

#ifndef SRC_WINDOW_HPP_
#define SRC_WINDOW_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QMenu>
#include <QLabel>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QMainWindow>
#include "file/FileManager.hpp"
#include "utils/Logger.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Window : public QMainWindow
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	Window(QWidget *parent = 0);
	virtual ~Window() = default;

    /**
     * @brief Prepare class behaviour
     */
	void init();

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
     * @note TODO: To implement!!!
     */
    void saveFile();

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

    /**
     * @brief Set fileName on the fileName label on the tool bar
     * @param filePath Path to the file
     */
    void fillFileNameLabel(QString filePath);

    log::Logger log_;                                   //!< Logger object
	QMenu *fileMenu_;                                   //!< Pointer to file menu object
	QMenu *helpMenu_;                                   //!< Pointer to help menu object

	QAction *toolBNew_;                                 //!< Pointer to the tool bar new file command
	QAction *toolBOpen_;                                //!< Pointer to the tool bar open file command
	QAction *toolBSave_;                                //!< Pointer to the tool bar save file command
	QAction *toolBQuit_;                                //!< Pointer to the tool bar quit command
    QLabel *fileNameLabel_;                             //!< Pointer to the tool bar fileName label
	QToolBar *toolBar_;                                 //!< Pointer to the tool bar

	QTextEdit *textEdit_;                               //!< Pointer to the text edit field
	QFileDialog *fileDialog_;                           //!< Pointer to the file dialog field

    FileManager fileManager_;                           //!< FileManager object
};

#endif /* SRC_WINDOW_HPP_ */
