#ifndef IMAGE_PAIR_OPEN_WIDGET_HPP
#define IMAGE_PAIR_OPEN_WIDGET_HPP

#include <QWidget>
#include <opencv2/core.hpp>
#include "image_open_widget/image_open_widget.hpp"

class ImagePairOpenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImagePairOpenWidget(QWidget *t_parent = nullptr);
    virtual ~ImagePairOpenWidget();

    const cv::Mat &getFirstMat();
    const cv::Mat &getSecondMat();

private:
    ImageOpenWidget *m_first_open_widget;
    ImageOpenWidget *m_second_open_widget;
    bool m_status{false};

    void setupUi();
    void initializationOfConnection();

signals:
    void prepared();
    void firstOpened();
    void firstFailed();
    void secondOpened();
    void secondFailed();
};

#endif // IMAGE_PAIR_OPEN_WIDGET_HPP
