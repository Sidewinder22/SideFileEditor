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
#include "view/Window.hpp"
#include "view/CommandHandler.hpp"
//#include "view/ICommandHandler.hpp"

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
    std::unique_ptr< view::Window > window_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */