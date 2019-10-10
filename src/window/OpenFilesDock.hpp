/**
 * @author Sidewinder22
 * @date   01.10.2019
 *
 * @brief Dock class for open files
 */

#ifndef SRC_WINDOW_OPENFILESDOCK_HPP_
#define SRC_WINDOW_OPENFILESDOCK_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include <QDockWidget>
#include <QListWidget>
#include "utils/Logger.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class OpenFilesDock : public QDockWidget
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    OpenFilesDock(QWidget *parent);
    virtual ~OpenFilesDock() = default;

    /**
     * @brief Create the dock
     */
    void createDock();

    /**
     * @brief Add filename to the dock
     * @param fileName File name
     */
    void addFileName(QString fileName);

    /**
     * @brief Remove filename from the dock
     * @param row Row to remove filename
     */
    void removeFileName(int row);

//---------------------------------------------------------
//              Public slots
//---------------------------------------------------------
public slots:
    /**
     * @brief Current row changed
     * @param currentRow row number
     */
    void rowChanged(int currentRow);

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                                   //!< Logger object
    QListWidget *fileList_;                             //!< List widget for open files
};

#endif /* SRC_WINDOW_OPENFILESDOCK_HPP_ */
