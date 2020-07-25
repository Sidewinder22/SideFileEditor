/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    RemoveCommand.hpp
 *
 * @brief   Class handles remove command
 */
#ifndef SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_
#define SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
#include <QTextEdit>
#include "app/IMainController.hpp"
#include "window/OpenFilesDock.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class RemoveCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	RemoveCommand(QWidget *parent, QTextEdit* textEdit,
		app::IMainController* mainController,
		window::OpenFilesDock *openFileDock);
    virtual ~RemoveCommand() = default;

	//-----------------------------------------------------
	//               Command
	//-----------------------------------------------------
    void execute() override;

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

#endif /* SRC_WINDOW_COMMAND_REMOVECOMMAND_HPP_ */
