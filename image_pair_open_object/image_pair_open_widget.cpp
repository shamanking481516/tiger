#include "image_pair_open_widget.hpp"
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

void ImagePairOpenWidget::setupUi()
{
    m_first_open_widget = new ImageOpenWidget(tr("First image:"));
    m_second_open_widget = new ImageOpenWidget(tr("Second image:"));
    auto *layout{new QVBoxLayout};
    layout->addWidget(m_first_open_widget);
    layout->addWidget(m_second_open_widget);
    setLayout(layout);
}

void ImagePairOpenWidget::initializationOfConnection()
{
    connect(m_first_open_widget, &ImageOpenWidget::opened, this, &ImagePairOpenWidget::firstOpened);
    connect(m_first_open_widget, &ImageOpenWidget::failed, this, &ImagePairOpenWidget::firstFailed);
    connect(m_second_open_widget, &ImageOpenWidget::opened, this, &ImagePairOpenWidget::secondOpened);
    connect(m_second_open_widget, &ImageOpenWidget::failed, this, &ImagePairOpenWidget::secondFailed);
}
