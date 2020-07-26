#ifndef SRC_WINDOW_COMMAND_CLEARCOMMAND_HPP_
#define SRC_WINDOW_COMMAND_CLEARCOMMAND_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    25.07.2020
 *
 * @brief   Class handles clear command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QTextEdit>
#include "log/Logger.hpp"
#include "Command.hpp"

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
class ClearCommand
	: public Command
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	ClearCommand(QTextEdit* textEdit);
    virtual ~ClearCommand() = default;

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
    QTextEdit* textEdit_;
};

} // ::command
} // ::window

#endif /* SRC_WINDOW_COMMAND_CLEARCOMMAND_HPP_ */
