/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#ifndef SRC_SIDEFILEEDITOR_HPP_
#define SRC_SIDEFILEEDITOR_HPP_

#include <QObject>
#include <memory>
#include "ctrl/Controller.hpp"
#include "view/ViewManager.hpp"
#include "view/CommandHandler.hpp"

class SideFileEditor
    : public QObject
{
    Q_OBJECT
public:
    SideFileEditor();
    virtual ~SideFileEditor() = default;
    
private:
    std::unique_ptr< ctrl::Controller > controller_;
    std::shared_ptr< view::CommandHandler > commandHandler_;
    std::unique_ptr< view::ViewManager > viewManager_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */