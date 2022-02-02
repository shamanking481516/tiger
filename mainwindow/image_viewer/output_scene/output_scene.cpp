#include "output_scene.hpp"
#include <QGraphicsPixmapItem>

OutputScene::OutputScene(QObject *t_parent) :
    QGraphicsScene(t_parent),
    m_pixmap_item{new QGraphicsPixmapItem}
{

}

OutputScene::~OutputScene()
{
    delete m_pixmap_item;
}

void OutputScene::setMat(const cv::Mat &t_mat)
{
    clearScene();
    m_pixmap_item->setPixmap(QPixmap::fromImage(QImage(t_mat.data, t_mat.cols, t_mat.rows, QImage::Format_RGB888).rgbSwapped()));
    addItem(m_pixmap_item);
}

void OutputScene::clearScene()
{
    if (this->items().contains(m_pixmap_item))
        removeItem(m_pixmap_item);
}
