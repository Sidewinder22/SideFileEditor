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
#include "log/Logger.hpp"
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
    QString read( const QString& bufferName );
    void textChanged( const QString& bufferName, const QString& text );

signals:
    void created( const QString& bufferName );

private:
    log::Logger log_;
    std::unique_ptr< model::ModelManager > modelManager_;

};

} // ::ctrl

#endif /* SRC_CTRL_MODELCONTROLLER_HPP_ */
