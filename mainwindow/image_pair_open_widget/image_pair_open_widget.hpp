#ifndef IMAGE_PAIR_OPEN_WIDGET_HPP
#define IMAGE_PAIR_OPEN_WIDGET_HPP

#include <QWidget>
#include <opencv2/core.hpp>

class ImageOpenWidget;

class ImagePairOpenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImagePairOpenWidget(QWidget *t_parent = nullptr);
    virtual ~ImagePairOpenWidget();

    const cv::Mat &getFirstMat();
    const cv::Mat &getSecondMat();
    const bool getFirstStatus();
    const bool getSecondStatus();
    const bool getStatus();

private:
    ImageOpenWidget *m_first_open_widget;
    ImageOpenWidget *m_second_open_widget;
    bool m_status{false};

    void setupUi();
    void initializationOfConnection();

private slots:
    void updateStatus();

signals:
    void prepared();
    void firstOpened();
    void firstFailed();
    void secondOpened();
    void secondFailed();
    void firstShow();
    void secondShow();
};

#endif // IMAGE_PAIR_OPEN_WIDGET_HPP
