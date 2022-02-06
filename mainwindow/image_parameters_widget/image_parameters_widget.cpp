#include "image_parameters_widget.hpp"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

ImageParametersWidget::ImageParametersWidget(QWidget *t_parent) :
    QWidget(t_parent)
{
    setupUi();
}

ImageParametersWidget::~ImageParametersWidget()
{

}

void ImageParametersWidget::setParametersFromMat(const cv::Mat &t_mat)
{
    cv::Scalar mean;
    cv::Scalar deviation;
    cv::meanStdDev(t_mat, mean, deviation);
    m_mean_line_edit->setText(QString::number(mean[0]));
    m_stddev_line_edit->setText(QString::number(deviation[0]));
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
    if (!t_line_edit)
        t_line_edit = new QLineEdit;
    t_line_edit->setReadOnly(true);
    t_layout->addRow(label, t_line_edit);
}
