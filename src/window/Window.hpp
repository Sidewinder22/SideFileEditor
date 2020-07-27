#ifndef SRC_WINDOW_WINDOW_HPP_
#define SRC_WINDOW_WINDOW_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    20.09.2016
 *
 * @brief   Main Window class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QWidget>
#include <QTextEdit>
#include <QMainWindow>
#include "app/IMainController.hpp"
#include "command/ICommandFactory.hpp"
#include "file/FileManager.hpp"
#include "log/Logger.hpp"
#include "utils/Utils.hpp"
#include "IOpenFilesDockObserver.hpp"
#include "IWindow.hpp"
#include "OpenFilesDock.hpp"
#include "Menu.hpp"
#include "ToolBar.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Window
    : public QMainWindow
    , public IWindow
    , public IOpenFilesDockObserver
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	Window(app::IMainController* mainController, QWidget *parent = 0);
	virtual ~Window() = default;

    //-----------------------------------------------------
    //                  IWindow
    //-----------------------------------------------------
    /**
     * @brief Prepare class behaviour
     */
	void init() override;

    /**
     * @brief openFile() response
     * @param status Status of operation
     */
    void opened(bool status, const QString& fileName) override;

    /**
     * @brief createBuffer() response
     * @param bufferName name of the created buffer
     */
    void created(const QString& bufferName) override;

    //-----------------------------------------------------
    //              IOpenFilesDockObserver
    //-----------------------------------------------------
    /**
     * @brief Notification that another file has been selected
     * @param fileName fileName of the created file
     */
    void anotherFileSelected(const QString& fileName) override;


//---------------------------------------------------------
//              Public slots
//---------------------------------------------------------
public slots:
    /**
     * @brief Text changed
     */
    void textChanged();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                                   //!< Logger object

	QTextEdit *textEdit_;                               //!< Pointer to the text edit field
    OpenFilesDock *openFileDock_;                       //!< Open files dock

    std::unique_ptr<utils::Utils> utils_;               //!< Pointer to utils object
    app::IMainController* mainController_;              //!< Pointer to the observer

    std::unique_ptr<Menu> menu_;
    std::unique_ptr<ToolBar> toolBar_;

    std::shared_ptr<command::ICommandFactory> commandFactory_;
};

} // ::window

#endif /* SRC_WINDOW_WINDOW_HPP_ */
