/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    CommandFactory.hpp
 *
 * @brief   Factory class reponsible for creating of the command objects
 */
#ifndef SRC_WINDOW_COMMAND_COMMANDFACTORY_HPP_
#define SRC_WINDOW_COMMAND_COMMANDFACTORY_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
#include <QTextEdit>
#include "app/IMainController.hpp"
#include "window/OpenFilesDock.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"
#include "ICommandFactory.hpp"
//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
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
	CommandFactory(QWidget *parent, QTextEdit* textEdit,
		app::IMainController* mainController,
		window::OpenFilesDock *openFileDock);

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
    app::IMainController* mainController_;
    window::OpenFilesDock *openFileDock_;
};

} // ::command
} // ::window

#endif /* SRC_WINDOW_COMMAND_COMMANDFACTORY_HPP_ */
