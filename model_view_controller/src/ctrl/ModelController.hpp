/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model controller class.
 */

#ifndef SRC_CTRL_MODELCONTROLLER_HPP_
#define SRC_CTRL_MODELCONTROLLER_HPP_

#include <memory>
#include <QObject>
#include "model/ModelManager.hpp"

namespace ctrl
{

class ModelController
    : public QObject
{
    Q_OBJECT

public:
    ModelController();

    void create();

signals:
    void created( const QString& bufferName );

private:
    std::unique_ptr< model::ModelManager > modelManager_;

};

} // ::ctrl

#endif /* SRC_CTRL_MODELCONTROLLER_HPP_ */
