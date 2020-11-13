/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#include <QScreen>
#include <QGuiApplication>
#include "SideFileEditor.hpp"

SideFileEditor::SideFileEditor()
    : controller_( std::make_unique< ctrl::Controller >() )
{ }
