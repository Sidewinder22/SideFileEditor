/**
 * @author  {\_Sidewinder22_/}
 * @date    24.01.2020
 *
 * @brief   Window class interface
 */

#ifndef SRC_WINDOW_IWINDOW_HPP_
#define SRC_WINDOW_IWINDOW_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

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
    virtual void fileOpened(bool status, const QString& fileName) = 0;

    /**
     * @brief createFile() response
     * @param status Status of operation
     * @param fileName fileName of the created file
     */
    virtual void fileCreated(bool status, const QString& fileName) = 0;
};

#endif /* SRC_WINDOW_IWINDOW_HPP_ */
