/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    OpenCommand.hpp
 *
 * @brief  	Class handles open command
 */
#ifndef SRC_GUI_COMMAND_OPENCOMMAND_HPP_
#define SRC_GUI_COMMAND_OPENCOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QWidget>
#include "app/IMainController.hpp"
#include "gui/OpenFilesDock.hpp"
#include "log/Logger.hpp"
#include "Command.hpp"

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
class OpenCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	OpenCommand(QWidget *parent, app::IMainController* mainController,
		gui::OpenFilesDock *openFileDock);
    virtual ~OpenCommand() = default;

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
    QString askUserForFileName() const;

    log::Logger log_;
    QWidget* parent_;
    app::IMainController* mainController_;
    gui::OpenFilesDock *openFileDock_;

    constexpr static const int ONE_BUFFER_OPEN = 1;
    constexpr static const int ALL_BUFFERS_SAVED = 0;
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_OPENCOMMAND_HPP_ */
