/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    QuitCommand.hpp
 *
 * @brief   Class handles quit command
 */
#ifndef SRC_WINDOW_COMMAND_QUITCOMMAND_HPP_
#define SRC_WINDOW_COMMAND_QUITCOMMAND_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QWidget>
#include "app/IMainController.hpp"
#include "log/Logger.hpp"
#include "utils/Utils.hpp"
#include "Command.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class QuitCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	QuitCommand(QWidget *parent, app::IMainController* mainController);
    virtual ~QuitCommand() = default;

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
    void verifyUnsavedBuffers();

    log::Logger log_;
    QWidget* parent_;
    app::IMainController* mainController_;
    std::unique_ptr<::utils::Utils> commonUtils_;
};

} // ::command

#endif /* SRC_WINDOW_COMMAND_QUITCOMMAND_HPP_ */