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
#include "ViewController.hpp"

namespace ctrl
{

class Controller
    : public QObject
{
    Q_OBJECT

public:
    Controller( view::ViewManager* viewManager );
    virtual ~Controller() = default;

public slots:
    /***
     * View slots
     ***/
    void newFile();
    void quit();
    void textChanged( const QString& bufferName, const QString& text );

    /***
     * Model slots
     ***/
    void bufferCreated( const QString& bufferName );

signals:
    void created( const QString& bufferName );

private:
    log::Logger log_;
    ModelController* modelController_;
    ViewController* viewController_;
    std::unique_ptr< cmd::ICommandFactory > commandFactory_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
