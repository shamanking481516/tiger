#include "output_view.hpp"

#include <QWheelEvent>
#include <QtMath>
#include <QResizeEvent>

OutputView::OutputView(QWidget *t_parent) :
    QGraphicsView{t_parent}
{
//    setDragMode(QGraphicsView::ScrollHandDrag);
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

}

void OutputView::setupUi()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
