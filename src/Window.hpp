/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#ifndef SRC_WINDOW_HPP_
#define SRC_WINDOW_HPP_

#include <memory>
#include <QMenu>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QMainWindow>
#include "FileContainer.hpp"
#include "utils/Logger.hpp"

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window(std::shared_ptr<FileContainer> fileContainger, QWidget *parent = 0);
	~Window() = default;
	void init();

public slots:
	void openFile();
	void selectFileName();

private:
	void connectSignalsToSlots();
	void buildToolBar();

    log::Logger log_;

	QMenu *menu_;
	QAction *toolBNew_;
	QAction *toolBOpen_;
	QAction *toolBQuit_;
	QToolBar *toolBar_;
	QTextEdit *textEdit_;
	QFileDialog *fileDialog_;
	std::shared_ptr<FileContainer> fileContainer_;
};

#endif /* SRC_WINDOW_HPP_ */
