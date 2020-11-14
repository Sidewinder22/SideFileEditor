/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handler interface.
 */

#ifndef SRC_VIEW_ICOMMANDHANDLER_HPP_
#define SRC_VIEW_ICOMMANDHANDLER_HPP_

namespace view
{

class ICommandHandler
{
public:
    virtual ~ICommandHandler() = default;

    virtual void newFile() = 0;
};

} // ::view

#endif /* SRC_VIEW_ICOMMANDHANDLER_HPP_ */
