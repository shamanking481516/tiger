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

void ImageParametersWidget::setMat(const cv::Mat &t_mat)
{

}

void ImageParametersWidget::setupUi()
{
    auto *layout{new QVBoxLayout};
    auto *form_layout{new QFormLayout};
    auto *mean_label = new QLabel(tr("Mean:"));
    m_mean_line_edit = new QLineEdit;
    m_mean_line_edit->setReadOnly(true);
    form_layout->addRow(mean_label, m_mean_line_edit);
    auto *median_label = new QLabel(tr("Median:"));
    m_median_line_edit = new QLineEdit;
    m_median_line_edit->setReadOnly(true);
    form_layout->addRow(median_label, m_median_line_edit);
    auto *min_label = new QLabel(tr("Minimum:"));
    m_min_line_edit = new QLineEdit;
    m_min_line_edit->setReadOnly(true);
    form_layout->addRow(min_label, m_min_line_edit);
    auto *max_label = new QLabel(tr("Maximum:"));
    m_max_line_edit = new QLineEdit;
    m_max_line_edit->setReadOnly(true);
    form_layout->addRow(max_label, m_max_line_edit);
    layout->addLayout(form_layout);
    layout->addStretch(10);
    setLayout(layout);
}
