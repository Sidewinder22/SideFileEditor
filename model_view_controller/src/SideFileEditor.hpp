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
#include "ctrl/ModelController.hpp"
#include "ctrl/ViewController.hpp"
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
    view::CommandHandler* commandHandler_;
    view::ViewManager* viewManager_;
    ctrl::ModelController* modelController_;
    ctrl::ViewController* viewController_;
    ctrl::Controller* controller_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */