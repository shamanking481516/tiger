#include "output_scene.hpp"

OutputScene::OutputScene(QObject *t_parent) :
    QGraphicsScene(t_parent)
{

}

OutputScene::~OutputScene()
{

}

void OutputScene::setMat(const cv::Mat &t_mat)
{
    if (m_pixmap_item)
    {
        this->removeItem(m_pixmap_item);
    }
    m_pixmap_item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(t_mat.data, t_mat.cols, t_mat.rows, QImage::Format_RGB888).rgbSwapped()));
    addItem(m_pixmap_item);
}

void OutputScene::setPreviousPosition(const QPointF t_previous_position)
{
    if (m_previous_position != t_previous_position)
    {
        m_previous_position = t_previous_position;
        emit previousPositionChanged();
    }
}

void OutputScene::mousePressEvent(QGraphicsSceneMouseEvent *t_event)
{
    if (t_event->button() & Qt::LeftButton)
    {
        m_is_left_mouse_buttom_pressed = true;
        setPreviousPosition(t_event->scenePos());
        m_selection = new QGraphicsRectItem();
        m_selection->setBrush(QBrush(QColor(158, 182, 255, 96)));
        m_selection->setPen(QPen(QColor(158, 182, 255, 200), 1));
        addItem(m_selection);
    }
}

void OutputScene::mouseMoveEvent(QGraphicsSceneMouseEvent *t_event)
{
    if (m_is_left_mouse_buttom_pressed)
    {
        qreal width = t_event->scenePos().x() - m_previous_position.x();
        qreal height = t_event->scenePos().y() - m_previous_position.y();
        m_selection->setRect(m_previous_position.x(), m_previous_position.y(), width, height);
    }
}

void OutputScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *t_event)
{
    if (t_event->button() & Qt::LeftButton)
    {
        if (m_selection != nullptr)
        {
            m_is_left_mouse_buttom_pressed = false;
            delete m_selection;
            m_selection = nullptr;
        }
    }
}
