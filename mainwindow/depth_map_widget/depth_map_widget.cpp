#include "depth_map_widget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QPushButton>

DepthMapWidget::DepthMapWidget(QWidget *t_parent) :
    QWidget(t_parent)
{
    setupUi();
}

DepthMapWidget::~DepthMapWidget()
{

}

void DepthMapWidget::setupUi()
{
    auto *layout{new QVBoxLayout};
    auto *form_layout{new QFormLayout};
    auto *first_label = new QLabel(tr("First Parameter:"));
    auto *first_spin_box = new QDoubleSpinBox;
    form_layout->addRow(first_label, first_spin_box);
    auto *second_label = new QLabel(tr("Second Parameter:"));
    auto *second_spin_box = new QDoubleSpinBox;
    form_layout->addRow(second_label, second_spin_box);
    layout->addLayout(form_layout);
    auto *calculate_button = new QPushButton(tr("Calculate"));
    calculate_button->setEnabled(false);
    auto *show_button = new QPushButton(tr("Show Depth Map"));
    show_button->setEnabled(false);
    layout->addWidget(calculate_button);
    layout->addWidget(show_button);
    setLayout(layout);
}
