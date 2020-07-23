#ifndef SRC_WINDOW_OPENFILESDOCK_HPP_
#define SRC_WINDOW_OPENFILESDOCK_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    01.10.2019
 *
 * @brief   Dock class for open files
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include <QDockWidget>
#include <QListWidget>
#include "log/Logger.hpp"
#include "IOpenFilesDockObserver.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

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
    OpenFilesDock(IOpenFilesDockObserver* observer, QWidget *parent);
    virtual ~OpenFilesDock() = default;

    /**
     * @brief Create the dock
     */
    void createDock();

    /**
     * @brief Add filename to the dock
     * @param fileName File name
     * @return Current row number
     */
    void addFileName(const QString& fileName);

    /**
     * @brief Remove filename from the dock
     * @param row Row to remove filename
     */
    void removeFileName(int row);

    /**
     * @brief Get fileName of currently selected file
     * @return FileName
     */
    QString getCurrentFileName();

    /**
     * @brief Get row of the currently selected file
     * @return Row number
     */
    int getCurrentRow();

    /**
     * @brief Mark current file as unsaved
     */
    void markCurrentFileAsUnsaved();

    /**
     * @brief Mark current file as saved
     */
    void markCurrentFileAsSaved();
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
    IOpenFilesDockObserver* observer_;                  //!< Pointer to the observer
};

} // ::window

#endif /* SRC_WINDOW_OPENFILESDOCK_HPP_ */
