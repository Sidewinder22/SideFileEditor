/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Command handler class.
 */

#ifndef SRC_VIEW_COMMANDHANDLER_HPP_
#define SRC_VIEW_COMMANDHANDLER_HPP_

#include <QObject>
#include "log/Logger.hpp"

namespace view
{

class CommandHandler
    : public QObject
{
    Q_OBJECT

public:
    CommandHandler();
    virtual ~CommandHandler() = default;

    /*********************************************************
     *              ICommandHandler
    *********************************************************/
    void newFile();
    void quit();

signals:
    void newFileRequest();
    void quitRequest();

private:
    log::Logger log_;
};

} // ::view

#endif /* SRC_VIEW_COMMANDHANDLER_HPP_ */
