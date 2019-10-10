/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Window interface
 */

#ifndef SRC_WINDOW_IWINDOW_HPP_
#define SRC_WINDOW_IWINDOW_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IWindow
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	virtual ~IWindow() = default;

    /**
     * @brief Init Window
     */
    virtual void init() = 0;
};

#endif /* SRC_WINDOW_IWINDOW_HPP_ */
