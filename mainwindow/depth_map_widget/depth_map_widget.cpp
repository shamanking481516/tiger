#include "depth_map_widget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

DepthMapWidget::DepthMapWidget(QWidget *t_parent) :
    QWidget(t_parent),
    m_depth_map_processor{new DepthMapProcessor(this)}
{
    setupUi();
    initializationOfConnection();
}

DepthMapWidget::~DepthMapWidget()
{

}

void DepthMapWidget::setReadinessStatus(const bool t_status)
{
    m_readiness_status = t_status;
    m_compute_button->setEnabled(m_readiness_status);
}

void DepthMapWidget::computeDepthMap(const cv::Mat &t_first_mat, const cv::Mat &t_second_mat)
{
    m_depth_map_processor->computeDepthMap(t_first_mat, t_second_mat, m_normalize_check_box->isChecked());
}

const cv::Mat &DepthMapWidget::getDepthMat() const
{
    return m_depth_map_processor->getDepthMat();
}

const bool DepthMapWidget::getStatus() const
{
    return m_depth_map_processor->getStatus();
}

void DepthMapWidget::setupUi()
{
    auto *layout{new QVBoxLayout};
    auto *form_layout{new QFormLayout};
    auto *first_label = new QLabel(tr("First Parameter:"));
    m_first_spin_box = new QDoubleSpinBox;
    form_layout->addRow(first_label, m_first_spin_box);
    auto *second_label = new QLabel(tr("Second Parameter:"));
    m_second_spin_box = new QDoubleSpinBox;
    form_layout->addRow(second_label, m_second_spin_box);
    layout->addLayout(form_layout);
    m_normalize_check_box = new QCheckBox(tr("Normalize Depth Map Image"));
    layout->addWidget(m_normalize_check_box);
    m_compute_button = new QPushButton(tr("Compute"));
    m_compute_button->setEnabled(false);
    m_show_button = new QPushButton(tr("Show Depth Map"));
    m_show_button->setEnabled(false);
    layout->addWidget(m_compute_button);
    layout->addWidget(m_show_button);
    setLayout(layout);
}

void DepthMapWidget::initializationOfConnection()
{
    connect(m_compute_button, &QPushButton::clicked, this, &DepthMapWidget::computeButtonClicked);
    connect(m_show_button, &QPushButton::clicked, this, &DepthMapWidget::showButtonClicked);
    connect(m_depth_map_processor, &DepthMapProcessor::statusChanged, this, [&](){
        m_show_button->setEnabled(m_depth_map_processor->getStatus());
    });
    connect(m_first_spin_box, &QDoubleSpinBox::valueChanged, m_depth_map_processor, &DepthMapProcessor::setFirstParameter);
    connect(m_second_spin_box, &QDoubleSpinBox::valueChanged, m_depth_map_processor, &DepthMapProcessor::setSecondParameter);
}
