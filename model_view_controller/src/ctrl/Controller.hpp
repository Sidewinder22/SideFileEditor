/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#ifndef SRC_CTRL_CONTROLLER_HPP_
#define SRC_CTRL_CONTROLLER_HPP_

#include <memory>
#include <QObject>
#include "log/Logger.hpp"
#include "cmd/ICommandFactory.hpp"
#include "ModelController.hpp"

namespace ctrl
{

class Controller
    : public QObject
{
    Q_OBJECT

public:
    Controller();
    virtual ~Controller() = default;

public slots:
    void newFile();
    void bufferCreated( const QString& bufferName );

signals:
    void created( const QString& bufferName );

private:
    log::Logger log_;
    std::shared_ptr< ModelController > modelController_;
    std::unique_ptr< cmd::ICommandFactory > commandFactory_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
