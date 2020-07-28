#ifndef SRC_GUI_IOPENFILESDOCKOBSERVER_HPP_
#define SRC_GUI_IOPENFILESDOCKOBSERVER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    28.02.2020
 *
 * @brief   OpenFilesDock observer interface
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IOpenFilesDockObserver
{
public:
	virtual ~IOpenFilesDockObserver() = default;

    //-----------------------------------------------------
    //              IOpenFilesDockObserver
    //-----------------------------------------------------

    /**
     * @brief Notification that another file has been selected
     * @param fileName fileName of the created file
     */
    virtual void anotherFileSelected(const QString& fileName) = 0;
};

} // ::gui

#endif /* SRC_GUI_IOPENFILESDOCKOBSERVER_HPP_ */
