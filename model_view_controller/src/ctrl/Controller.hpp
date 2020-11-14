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

private:
    log::Logger log_;
    std::unique_ptr< ModelController > modelController_;
};

}; // ::ctrl

#endif /* SRC_CTRL_CONTROLLER_HPP_ */
