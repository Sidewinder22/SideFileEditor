/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#ifndef SRC_CTRL_CONTROLLER_HPP_
#define SRC_CTRL_CONTROLLER_HPP_

#include "log/Logger.hpp"
#include "cmd/ICommandFactory.hpp"
#include "ModelController.hpp"
#include "view/ViewManager.hpp"
#include <memory>
#include <QObject>

namespace ctrl
{

class Controller
    : public QObject
{
    Q_OBJECT

public:
    explicit Controller();
    virtual ~Controller() = default;

public slots:
    void newFile();
    void quit();
    void open( const QString& fileName );
    void save( const QString& fileName );

    void created( const QString& bufferName );
    void opened( const QString& fileName, const QString& text );
    void textChanged( const QString& bufferName, const QString& text );
    void bufferSelectionChanged( const QString& bufferName );

signals:
    void createdNotif( const QString& bufferName );
    void openedNotif( const QString& fileName, const QString& text );
    void loadNotif( const QString& text );

private:
    log::Logger log_;
    ModelController* modelController_;
    std::unique_ptr< cmd::ICommandFactory > commandFactory_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
