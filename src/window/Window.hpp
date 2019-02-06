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
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QMainWindow>
#include "file/FileContainer.hpp"
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
	Window(std::shared_ptr<FileContainer> fileContainger, QWidget *parent = 0);
	~Window() = default;

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
     * @brief Select saved file name
     */
	void selectFileName();

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

    log::Logger log_;                                   //!< Logger object
	QMenu *menu_;                                       //!< Pointer to menu object
	QAction *toolBNew_;                                 //!< Pointer to the tool bar new file command
	QAction *toolBOpen_;                                //!< Pointer to the tool bar open file command
	QAction *toolBSave_;                                //!< Pointer to the tool bar save file command
	QAction *toolBQuit_;                                //!< Pointer to the tool bar quit command
	QToolBar *toolBar_;                                 //!< Pointer to the tool bar
	QTextEdit *textEdit_;                               //!< Pointer to the text edit field
	QFileDialog *fileDialog_;                           //!< Pointer to the file dialog field
	std::shared_ptr<FileContainer> fileContainer_;      //!< Pointer to the file container

    QString fileName_;
};

#endif /* SRC_WINDOW_HPP_ */
