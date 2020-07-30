#ifndef SRC_CONTENT_BUFFER_HPP_
#define SRC_CONTENT_BUFFER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>
#include "log/Logger.hpp"
#include "IBuffer.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class Buffer
    : public IBuffer
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    Buffer(QString fileName);

    virtual ~Buffer() = default;

    QString fileName() const override;

    void setFileName(const QString& fileName) override;

    void write(const std::vector<QString> &content) override;
    std::vector<QString> read() const override;

    bool empty() const override;
    void clear() override;

    bool isSaved() const override;
    void setSaved(bool saved) override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    /**
     * True if buffer is saved to the file, false otherwise
     */
    bool saved_;

    log::Logger log_;                       //!< Logger object
    QString fileName_;                      //!< Filename
    std::vector<QString> content_;			//!< Buffer's content
};

} // ::content

#endif /* SRC_CONTENT_BUFFER_HPP_ */
