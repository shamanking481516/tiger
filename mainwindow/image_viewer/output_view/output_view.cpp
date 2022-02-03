#include "output_view.hpp"

#include <QWheelEvent>
#include <QtMath>
#include <QResizeEvent>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QRubberBand>
#include <QDebug>

OutputView::OutputView(QWidget *t_parent) :
    QGraphicsView{t_parent},
    m_rubber_band{new QRubberBand(QRubberBand::Rectangle, this)}
{
    setupUi();
}

OutputView::~OutputView()
{

}

void OutputView::fitIntoView()
{
    if (!items().empty())
        fitInView(items().at(0), Qt::KeepAspectRatio);
}

void OutputView::wheelEvent(QWheelEvent *t_event)
{
    Q_UNUSED(t_event);
    const double angle_delta_y = t_event->angleDelta().y();
    const double zoom_factor = qPow(1.0015, angle_delta_y);
    scale(zoom_factor, zoom_factor);
    if (angle_delta_y > 0)
    {
        this->centerOn(m_scene_mouse_position);
        m_scene_mouse_position = this->mapToScene(t_event->position().toPoint());
    }
    this->viewport()->update();
}

void OutputView::resizeEvent(QResizeEvent *t_event)
{
    Q_UNUSED(t_event);
    fitIntoView();
}

void OutputView::mouseDoubleClickEvent(QMouseEvent *t_event)
{
    Q_UNUSED(t_event);
    fitIntoView();
}

void OutputView::mousePressEvent(QMouseEvent *t_event)
{
    m_origin = t_event->pos();
    m_rubber_band->setGeometry(QRect(m_origin, QSize()));
    m_rubber_band->show();
}

void OutputView::mouseMoveEvent(QMouseEvent *t_event)
{
    m_rubber_band->setGeometry(QRect(m_origin, t_event->pos()).normalized());
}

void OutputView::mouseReleaseEvent(QMouseEvent *t_event)
{
    bool is_not_same_pos = m_origin != t_event->pos();
    if (!items().empty() && is_not_same_pos)
    {
        QGraphicsPixmapItem *pixmap_item = qgraphicsitem_cast<QGraphicsPixmapItem*>(items().at(0));
        QPixmap selected_area = pixmap_item->pixmap().copy(getRectForScene(m_rubber_band->geometry()));
        emit sendSelectedArea(selected_area);
    }
    m_rubber_band->hide();
}

void OutputView::setupUi()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

const QRect OutputView::getRectForScene(const QRect &t_rect)
{
    QPointF top_left = mapToScene(t_rect.x(), t_rect.y());
    QPointF bottom_right = mapToScene(t_rect.x() + t_rect.width(), t_rect.y() + t_rect.height());
    return QRect(top_left.toPoint(), bottom_right.toPoint());
}
