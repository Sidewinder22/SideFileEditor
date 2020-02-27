/**
 * @author  {\_Sidewinder22_/}
 * @date    28.02.2020
 *
 * @brief   OpenFilesDock observer interface
 */

#ifndef SRC_WINDOW_IOPENFILESDOCKOBSERVER_HPP_
#define SRC_WINDOW_IOPENFILESDOCKOBSERVER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>

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

#endif /* SRC_WINDOW_IOPENFILESDOCKOBSERVER_HPP_ */
