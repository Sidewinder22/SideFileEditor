/**
 * @author  {\_Sidewinder22_/}
 * @date    11.11.2020
 * 
 * @brief   Main app file.
 */

#include <QApplication>
#include "SideFileEditor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SideFileEditor sfe;

    return app.exec();
}