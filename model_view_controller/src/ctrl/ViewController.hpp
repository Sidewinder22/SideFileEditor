/**
 * @author  {\_Sidewinder22_/}
 * @date    20.11.2020
 * 
 * @brief   View controller class.
 */

#ifndef SRC_CTRL_VIEWCONTROLLER_HPP_
#define SRC_CTRL_VIEWCONTROLLER_HPP_

#include <QObject>
#include "view/ViewManager.hpp"

namespace ctrl
{

class ViewController
    : public QObject
{
    Q_OBJECT

public:
    ViewController( view::ViewManager* ViewManager );

    void load( const QString& text );

public slots:
    void created( const QString& bufferName );
    void opened( const QString& fileName, const QString& text );

private: 
    view::ViewManager* viewManager_;
};

} // ::ctrl

#endif /* SRC_CTRL_VIEWCONTROLLER_HPP_ */
