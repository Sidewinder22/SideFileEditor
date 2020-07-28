/** * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    CommandFactory.hpp
 *
 * @brief   Factory class reponsible for creating of the command objects
 */
#ifndef SRC_GUI_COMMAND_COMMANDFACTORY_HPP_
#define SRC_GUI_COMMAND_COMMANDFACTORY_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
#include <QTextEdit>
#include <QStatusBar>
#include "app/IMainController.hpp"
#include "gui/OpenFilesDock.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"
#include "ICommandFactory.hpp"
//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class CommandFactory final
	: public ICommandFactory
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	CommandFactory(QWidget *parent, QTextEdit* textEdit, QStatusBar* statusBar,
		app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock);

	virtual ~CommandFactory() = default;

	Command& getNewCommand() override;
	Command& getOpenCommand() override;
	Command& getSaveCommand() override;
	Command& getClearCommand() override;
	Command& getCloseCommand() override;
	Command& getRemoveCommand() override;
	Command& getAboutCommand() override;
	Command& getQuitCommand() override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;
    QWidget* parent_;
    QTextEdit* textEdit_;
    QStatusBar* statusBar_;
    app::IMainController* mainController_;
    gui::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_COMMANDFACTORY_HPP_ */
