#ifndef IMAGE_PARAMETERS_WIDGET_HPP
#define IMAGE_PARAMETERS_WIDGET_HPP

#include <QWidget>
#include <opencv2/opencv.hpp>

class QLineEdit;

class ImageParametersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageParametersWidget(QWidget *t_parent = nullptr);
    virtual ~ImageParametersWidget();

public slots:
    void setMat(const cv::Mat &t_mat);

private:
    QLineEdit *m_mean_line_edit;
    QLineEdit *m_median_line_edit;
    QLineEdit *m_min_line_edit;
    QLineEdit *m_max_line_edit;

    void setupUi();
};

#endif // IMAGE_PARAMETERS_WIDGET_HPP
