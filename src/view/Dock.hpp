/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Dock for open files.
 */

#ifndef SRC_VIEW_DOCK_HPP_
#define SRC_VIEW_DOCK_HPP_

#include <QDockWidget>
#include <QListWidget>
#include "log/Logger.hpp"

namespace view
{

class Dock 
    : public QDockWidget
{
    Q_OBJECT

public:
    Dock();
    virtual ~Dock() = default;

    void addName( const QString& bufferName );
    void setNewName( const QString& newName );
    void removeCurrentFileName();
    QString getCurrent();

public slots:
    void itemClicked( QListWidgetItem *item );

signals:
    void bufferSelectionChangedNotif( const QString& bufferName );

private:
    log::Logger log_;
    QListWidget* names_;
};

} // ::view

#endif /* SRC_VIEW_DOCK_HPP_ */
