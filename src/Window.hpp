/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#ifndef SRC_WINDOW_HPP_
#define SRC_WINDOW_HPP_

#include <memory>
#include <QMenu>
//#include <QString>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QMainWindow>

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window(QWidget *parent = 0);
	~Window() = default;
	void init();

private:
	void connectSignalsToSlots();
	void buildToolBar();
	void openFile();
	void selectFileName();

	QMenu *menu_;
//	QString *fileName_;
	QAction *toolBNew_;
	QAction *toolBOpen_;
	QAction *toolBQuit_;
	QToolBar *toolBar_;
	QTextEdit *textEdit_;
	QFileDialog *fileDialog_;
};

#endif /* SRC_WINDOW_HPP_ */
