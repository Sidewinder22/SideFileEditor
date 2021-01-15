/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Text edit class
 */

#include "TextEdit.hpp"

namespace view
{

TextEdit::TextEdit()
{
//    setStatusTip( "Text editor field" );
}
    
QString TextEdit::text()
{
    return toPlainText();
}

} // ::view
