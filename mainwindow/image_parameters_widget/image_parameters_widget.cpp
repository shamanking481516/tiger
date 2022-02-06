#include "image_parameters_widget.hpp"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

ImageParametersWidget::ImageParametersWidget(QWidget *t_parent) :
    QWidget(t_parent),
    m_mean_line_edit{new QLineEdit},
    m_stddev_line_edit{new QLineEdit},
    m_min_line_edit{new QLineEdit},
    m_max_line_edit{new QLineEdit}
{
    setupUi();
}

ImageParametersWidget::~ImageParametersWidget()
{

}

void ImageParametersWidget::setParametersFromPixmap(const QPixmap t_pixmap)
{
    cv::Mat mat = getMatFromPixmap(t_pixmap);
    cv::Scalar mean;
    cv::Scalar deviation;
    cv::meanStdDev(mat, mean, deviation);
    m_mean_line_edit->setText(QString::number(mean[0]));
    m_stddev_line_edit->setText(QString::number(deviation[0]));
    double min = 0;
    cv::Point min_point;
    double max = 0;
    cv::Point max_point;
    cv::minMaxLoc(mat, &min, &max, &min_point, &max_point);
    m_min_line_edit->setText(QString::number(min));
    m_max_line_edit->setText(QString::number(max));
}

void ImageParametersWidget::setupUi()
{
    auto *layout{new QVBoxLayout};
    auto *form_layout{new QFormLayout};
    addRowInFormLayout(form_layout, m_mean_line_edit, tr("Mean:"));
    addRowInFormLayout(form_layout, m_stddev_line_edit, tr("Deviation:"));
    addRowInFormLayout(form_layout, m_min_line_edit, tr("Minimum:"));
    addRowInFormLayout(form_layout, m_max_line_edit, tr("Maximum"));
    layout->addLayout(form_layout);
    layout->addStretch(10);
    setLayout(layout);
}

void ImageParametersWidget::addRowInFormLayout(QFormLayout *t_layout, QLineEdit *t_line_edit, const QString &t_text)
{
    auto label = new QLabel(t_text);
    t_line_edit->setReadOnly(true);
    t_layout->addRow(label, t_line_edit);
}

cv::Mat ImageParametersWidget::getMatFromPixmap(const QPixmap &t_pixmap) const
{
    QImage image = t_pixmap.toImage();
    image.convertTo(QImage::Format_Grayscale8);
    cv::Mat result = cv::Mat(image.height(), image.width(), CV_8UC1, (void *)image.constBits(), image.bytesPerLine()).clone();
    return result;
}
