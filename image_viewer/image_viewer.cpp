#include "image_viewer.hpp"
#include <QVBoxLayout>

ImageViewer::ImageViewer(QWidget *t_parent) :
    QWidget{t_parent},
    m_scene{new OutputScene(this)},
    m_output_view{new OutputView}
{
    m_output_view->setScene(m_scene);
    auto *vbox_layout{new QVBoxLayout};
    vbox_layout->setContentsMargins(0, 0, 0, 0);
    vbox_layout->addWidget(m_output_view);
    setLayout(vbox_layout);
}

ImageViewer::~ImageViewer()
{

}

void ImageViewer::setMat(const cv::Mat &t_mat)
{
    m_scene->setMat(t_mat);
    m_output_view->fitIntoView();
}
