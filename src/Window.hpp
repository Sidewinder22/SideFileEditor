/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#ifndef SRC_WINDOW_HPP_
#define SRC_WINDOW_HPP_

#include <memory>
#include <QMenu>
#include <QWidget>
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

	QMenu *menu_;
};

#endif /* SRC_WINDOW_HPP_ */
