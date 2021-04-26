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

	void showAboutInfo() const;
	void showSaveWarning() const;
	QString getFileNameForOpen();
	QString getFileNameForSave( const QString& bufferName );

private:
	QWidget* parent_;

    constexpr static auto ABOUT = "     About     \n";
    constexpr static auto APP = "     SideFileEditor\n";
    constexpr static auto BY = "             by\n";
    constexpr static auto AUTHOR = "{\\_Sidewinder22_/}";

    constexpr static auto SAVE_QUESTION = "Select location for a buffer: ";
    constexpr static auto OPEN_QUESTION = "Select file to open...";
    constexpr static auto SAVE_WARNING = "Can't save file!";

    constexpr static auto FILE_TYPES = "Text files: *.txt *.h *.hpp *.c"
    	"*.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp"
    	"*.py *.js *.ccs *.json)";

};

} // ::view

#endif /* MODEL_VIEW_CONTROLLER_SRC_VIEW_USERINTERACTION_HPP_ */
