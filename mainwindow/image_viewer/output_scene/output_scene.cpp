#include "output_scene.hpp"
#include <QGraphicsPixmapItem>

OutputScene::OutputScene(QObject *t_parent) :
    QGraphicsScene(t_parent)
{

}

OutputScene::~OutputScene()
{

}

void OutputScene::setMat(const cv::Mat &t_mat)
{
    if (m_pixmap_item == nullptr)
    {
        this->removeItem(m_pixmap_item);
    }
    m_pixmap_item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(t_mat.data, t_mat.cols, t_mat.rows, QImage::Format_RGB888).rgbSwapped()));
    addItem(m_pixmap_item);
}
