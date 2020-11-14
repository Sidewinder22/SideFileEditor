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
    ViewManager( std::shared_ptr< view::CommandHandler > commandHandler );
    virtual ~ViewManager() = default;

public slots:
    void bufferCreated( const QString& bufferName );

private:
    log::Logger log_;
    Dock* dock_;
    std::unique_ptr< view::Window > window_;
};

} // ::view

#endif /* SRC_VIEW_VIEWMANAGER_HPP_ */
