/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#ifndef SRC_SIDEFILEEDITOR_HPP_
#define SRC_SIDEFILEEDITOR_HPP_

#include "view/ViewManager.hpp"
#include "model/ModelManager.hpp"
#include "ctrl/Controller.hpp"
#include <QObject>

class SideFileEditor
    : public QObject
{
    Q_OBJECT
public:
    SideFileEditor();
    virtual ~SideFileEditor() = default;
    
private:
    view::ViewManager* viewManager_;
    model::ModelManager* modelManager_;
    ctrl::Controller* controller_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */
