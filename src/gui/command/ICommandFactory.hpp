/**
 * @author  {\_Sidewinder22_/}
 * @date    27 lip 2020
 * @file    ICommandFactory.hpp
 *
 * @brief   Interface for command factory
 */
#ifndef SRC_GUI_COMMAND_ICOMMANDFACTORY_HPP_
#define SRC_GUI_COMMAND_ICOMMANDFACTORY_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
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
class ICommandFactory
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	virtual ~ICommandFactory() = default;

	virtual Command& getNewCommand() = 0;
	virtual Command& getOpenCommand() = 0;
	virtual Command& getSaveCommand() = 0;
	virtual Command& getClearCommand() = 0;
	virtual Command& getCloseCommand() = 0;
	virtual Command& getRemoveCommand() = 0;
	virtual Command& getAboutCommand() = 0;
	virtual Command& getQuitCommand() = 0;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
};

} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_ICOMMANDFACTORY_HPP_ */
