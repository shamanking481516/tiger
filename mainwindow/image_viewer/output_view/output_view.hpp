#ifndef OUTPUT_VIEW_HPP
#define OUTPUT_VIEW_HPP

#include <QGraphicsView>

class QRubberBand;

class OutputView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit OutputView(QWidget *t_parent = nullptr);
    virtual ~OutputView();

    void fitIntoView();

protected:
    void wheelEvent(QWheelEvent *t_event) override;
    void resizeEvent(QResizeEvent *t_event) override;
    void mouseDoubleClickEvent(QMouseEvent* t_event) override;
    void mousePressEvent(QMouseEvent *t_event) override;
    void mouseMoveEvent(QMouseEvent *t_event) override;
    void mouseReleaseEvent(QMouseEvent *t_event) override;

private:
    QPointF m_scene_mouse_position;
    QPoint m_origin;
    QRubberBand *m_rubber_band;

    void setupUi();
    const QRect getRectForScene(const QRect &t_rect);

signals:
    void sendSelectedArea(QPixmap t_selected_area);
    void sendSelectedRect(QRect t_rect);
};

#endif // OUTPUT_VIEW_HPP
