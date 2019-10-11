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
     * @brief Read data from file
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read() = 0;

    /**
     * @brief Write data to file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    virtual bool write(const QString& text) = 0;

    /**
     * @brief Close open file
     */
    virtual void close() = 0;

    /**
     * @brief Remove file
     */
    virtual void remove() = 0;
};

#endif /* SRC_WINDOW_IWINDOWOBSERVER_HPP_ */
