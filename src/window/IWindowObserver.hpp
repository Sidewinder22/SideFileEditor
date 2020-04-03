/**
 * @author  {\_Sidewinder22_/}
 * @date    11.10.2019
 *
 * @brief   Main window observer interface
 */

#ifndef SRC_WINDOW_IWINDOWOBSERVER_HPP_
#define SRC_WINDOW_IWINDOWOBSERVER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IWindowObserver
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	virtual ~IWindowObserver() = default;

    /**
     * @brief Open file
     * @param fileName path for file
     */
    virtual void openFile(const QString& fileName) = 0;

    /**
     * @brief Create new file
     * @param fileName path for file
     */
    virtual void createFile(const QString& fileName) = 0;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     */
    virtual void textChanged(const QString& fileName, const QString &content) = 0;

    /**
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read(const QString& fileName) = 0;

    /**
     * @brief Write data to file
     * @param fileName file name
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    virtual bool write(const QString& fileName, const QString& text) = 0;

    /**
     * @brief Close open file
     * @param fileName file name
     */
    virtual void close(const QString& fileName) = 0;

    /**
     * @brief Remove file
     * @param fileName file name
     */
    virtual void remove(const QString& fileName) = 0;
};

} // ::window

#endif /* SRC_WINDOW_IWINDOWOBSERVER_HPP_ */
