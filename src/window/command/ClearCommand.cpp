/**
 * @author  {\_Sidewinder22_/}
 * @date    25.07.2020
 *
 * @brief   Class handles clear command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "ClearCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

ClearCommand::ClearCommand(QTextEdit* textEdit)
	: log_("ClearCommand")
	, textEdit_(textEdit)
{
	// Nothing
}

void ClearCommand::execute()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();
}

} // ::command
} // ::window
