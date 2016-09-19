/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#ifndef SRC_WINDOW_HPP_
#define SRC_WINDOW_HPP_

#include <QMainWindow>

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window(QMainWindow *parent = 0);
	~Window() = default;
};

#endif /* SRC_WINDOW_HPP_ */
