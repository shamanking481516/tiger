#include "image_pair_open_widget.hpp"
#include "image_open_widget/image_open_widget.hpp"
#include <QVBoxLayout>
#include <QLabel>

ImagePairOpenWidget::ImagePairOpenWidget(QWidget *t_parent) :
    QWidget{t_parent}
{
    setupUi();
    initializationOfConnection();
}

ImagePairOpenWidget::~ImagePairOpenWidget()
{

}

const cv::Mat &ImagePairOpenWidget::getFirstMat()
{
    return m_first_open_widget->getMat();
}

const cv::Mat &ImagePairOpenWidget::getSecondMat()
{
    return m_second_open_widget->getMat();
}

const bool ImagePairOpenWidget::getFirstStatus()
{
    return m_first_open_widget->getStatus();
}

const bool ImagePairOpenWidget::getSecondStatus()
{
    return m_second_open_widget->getStatus();
}

const bool ImagePairOpenWidget::getStatus()
{
    return m_status;
}

void ImagePairOpenWidget::setupUi()
{
    m_first_open_widget = new ImageOpenWidget(tr("First image:"));
    m_second_open_widget = new ImageOpenWidget(tr("Second image:"));
    auto *layout{new QVBoxLayout};
    layout->addWidget(m_first_open_widget);
    layout->addWidget(m_second_open_widget);
    layout->addStretch();
    setLayout(layout);
}

void ImagePairOpenWidget::initializationOfConnection()
{
    connect(m_first_open_widget, &ImageOpenWidget::opened, this, [&](){
        emit firstOpened();
        updateStatus();
    });
    connect(m_first_open_widget, &ImageOpenWidget::failed, this, [&](){
        emit firstFailed();
        updateStatus();
    });
    connect(m_second_open_widget, &ImageOpenWidget::opened, this, [&](){
        emit secondOpened();
        updateStatus();
    });
    connect(m_second_open_widget, &ImageOpenWidget::failed, this, [&](){
        emit secondFailed();
        updateStatus();
    });
}

void ImagePairOpenWidget::updateStatus()
{
    (m_first_open_widget->getStatus() && m_second_open_widget->getStatus()) ? m_status = true : m_status = false;
}
