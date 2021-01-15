/**
 * @author  {\_Sidewinder22_/}
 * @date    11.11.2020
 * 
 * @brief   Main app file.
 */

#include "SideFileEditor.hpp"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    const SideFileEditor sfe;

    return app.exec();
}
