#ifndef SRC_GUI_IWINDOW_HPP_
#define SRC_GUI_IWINDOW_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    24.01.2020
 *
 * @brief   Window observer interface
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
class IWindow
{
public:
	virtual ~IWindow() = default;

    //-----------------------------------------------------
    //                  IWindow
    //-----------------------------------------------------
    /**
     * @brief Prepare class behaviour
     */
	virtual void init() = 0;

    /**
     * @brief openFile() response
     * @param status Status of operation
     */
    virtual void opened(bool status, const QString& fileName) = 0;

    /**
     * @brief createBuffer() response
     * @param status Status of operation
     * @param bufferName name of the created buffer
     */
    virtual void created(const QString& bufferName) = 0;
};

} // ::gui

#endif /* SRC_GUI_IWINDOW_HPP_ */
