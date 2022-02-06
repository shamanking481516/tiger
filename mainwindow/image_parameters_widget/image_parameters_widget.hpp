#ifndef IMAGE_PARAMETERS_WIDGET_HPP
#define IMAGE_PARAMETERS_WIDGET_HPP

#include <QWidget>
#include <opencv2/opencv.hpp>

class QLineEdit;
class QFormLayout;

class ImageParametersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageParametersWidget(QWidget *t_parent = nullptr);
    virtual ~ImageParametersWidget();

public slots:
    void setParametersFromPixmap(const QPixmap t_pixmap);

private:
    QLineEdit *m_mean_line_edit;
    QLineEdit *m_stddev_line_edit;
    QLineEdit *m_min_line_edit;
    QLineEdit *m_max_line_edit;

    void setupUi();
    void addRowInFormLayout(QFormLayout *t_layout, QLineEdit *t_line_edit, const QString &t_text);
    cv::Mat getMatFromPixmap(const QPixmap &t_pixmap) const;
};

#endif // IMAGE_PARAMETERS_WIDGET_HPP
