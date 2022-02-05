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

void ImageParametersWidget::setupUi()
{
    auto *layout{new QVBoxLayout};
    auto *form_layout{new QFormLayout};
    auto *mean_label = new QLabel(tr("Mean:"));
    auto *mean_line_edit = new QLineEdit;
    form_layout->addRow(mean_label, mean_line_edit);
    auto *median_label = new QLabel(tr("Median:"));
    auto *median_line_edit = new QLineEdit;
    form_layout->addRow(median_label, median_line_edit);
    auto *min_label = new QLabel(tr("Minimum:"));
    auto *min_line_edit = new QLineEdit;
    form_layout->addRow(min_label, min_line_edit);
    auto *max_label = new QLabel(tr("Maximum:"));
    auto *max_line_edit = new QLineEdit;
    form_layout->addRow(max_label, max_line_edit);
    layout->addLayout(form_layout);
    layout->addStretch(10);
    setLayout(layout);
}
