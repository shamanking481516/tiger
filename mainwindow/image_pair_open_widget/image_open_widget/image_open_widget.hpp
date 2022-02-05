#ifndef IMAGE_OPEN_WIDGET_HPP
#define IMAGE_OPEN_WIDGET_HPP

#include <QWidget>
#include <opencv2/core.hpp>

class QPushButton;
class QLineEdit;
class ImageOpenObject;

class ImageOpenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageOpenWidget(const QString &t_label_text, QWidget *t_parent = nullptr);
    virtual ~ImageOpenWidget();

    const cv::Mat &getMat() const;
    const bool getStatus() const;

private:
    QString m_label_text;
    QPushButton *m_browse_button;
    QPushButton *m_show_button;
    QLineEdit *m_filename_lineedit;
    ImageOpenObject *m_image_open_object;

    void setupUi();
    void initializationOfConnection();
    const QString selectFileToOpen();

signals:
    void opened();
    void failed();
    void showImage();
};

#endif // IMAGE_OPEN_WIDGET_HPP
