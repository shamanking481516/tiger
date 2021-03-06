#include "image_viewer.hpp"
#include "output_scene/output_scene.hpp"
#include "output_view/output_view.hpp"
#include <QVBoxLayout>

ImageViewer::ImageViewer(QWidget *t_parent) :
    QWidget{t_parent},
    m_scene{new OutputScene(this)},
    m_output_view{new OutputView}
{
    setupUi();
    initializationOfConnection();
}

ImageViewer::~ImageViewer()
{

}

void ImageViewer::setMat(const cv::Mat &t_mat)
{
    m_scene->setMat(t_mat);
    m_output_view->fitIntoView();
}

void ImageViewer::setPixmap(const QPixmap &t_pixmap)
{
    m_scene->setPixmap(t_pixmap);
    m_output_view->fitIntoView();
}

void ImageViewer::clearViewer()
{
    m_scene->clearScene();
}

void ImageViewer::setupUi()
{
    m_output_view->setScene(m_scene);
    auto *vbox_layout{new QVBoxLayout};
    vbox_layout->setContentsMargins(0, 0, 0, 0);
    vbox_layout->addWidget(m_output_view);
    setLayout(vbox_layout);
}

void ImageViewer::initializationOfConnection()
{
    connect(m_output_view, &OutputView::sendSelectedArea, this, &ImageViewer::sendSelectedArea);
    connect(m_output_view, &OutputView::sendSelectedRect, this, &ImageViewer::sendSelectedRect);
}
