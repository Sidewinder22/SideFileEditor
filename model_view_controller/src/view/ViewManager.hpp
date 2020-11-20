/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#ifndef SRC_VIEW_VIEWMANAGER_HPP_
#define SRC_VIEW_VIEWMANAGER_HPP_

#include <QObject>
#include "log/Logger.hpp"
#include "view/Window.hpp"
#include "Dock.hpp"

namespace view
{

class ViewManager
    : public QObject
{
    Q_OBJECT

public:
    ViewManager( CommandHandler* commandHandler );
    virtual ~ViewManager() = default;

public slots:
    void bufferCreated( const QString& bufferName );
    void textChanged();

private:
    log::Logger log_;
    Dock* dock_;
    view::Window* window_;
};

} // ::view

#endif /* SRC_VIEW_VIEWMANAGER_HPP_ */
