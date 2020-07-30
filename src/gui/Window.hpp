#ifndef SRC_GUI_WINDOW_HPP_
#define SRC_GUI_WINDOW_HPP_
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
#include <QStatusBar>
#include <QMainWindow>
#include "app/IMainController.hpp"
#include "log/Logger.hpp"
#include "command/ICommandFactory.hpp"
#include "IOpenFilesDockObserver.hpp"
#include "IWindow.hpp"
#include "Menu.hpp"
#include "NotificationHandler.hpp"
#include "OpenFilesDock.hpp"
#include "ToolBar.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
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
    log::Logger log_;
	QTextEdit* textEdit_;
	QStatusBar* statusBar_;
    OpenFilesDock* openFileDock_;
    app::IMainController* mainController_;
    std::unique_ptr<Menu> menu_;
    std::unique_ptr<ToolBar> toolBar_;
    std::unique_ptr<gui::NotificationHandler> notificationHandler_;
    std::shared_ptr<command::ICommandFactory> commandFactory_;
};

} // ::gui

#endif /* SRC_GUI_WINDOW_HPP_ */
