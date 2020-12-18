/**
 * @author  {\_Sidewinder22_/}
 * @date    18.12.2020
 *
 * @brief   User interaction class
 */

#ifndef SRC_VIEW_USERINTERACTION_HPP_
#define SRC_VIEW_USERINTERACTION_HPP_

#include <QWidget>

namespace view
{

class UserInteraction
{
public:
	explicit UserInteraction( QWidget* parent );
	void showAboutInfo();

private:
	QWidget* parent_;

    constexpr static const char* ABOUT = "     About     \n";
    constexpr static const char* APP = "     SideFileEditor\n";
    constexpr static const char* BY = "             by\n";
    constexpr static const char* AUTHOR = "{\\_Sidewinder22_/}";
};

} // ::view

#endif /* MODEL_VIEW_CONTROLLER_SRC_VIEW_USERINTERACTION_HPP_ */
