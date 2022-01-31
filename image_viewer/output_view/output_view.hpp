#ifndef OUTPUT_VIEW_HPP
#define OUTPUT_VIEW_HPP

#include <QGraphicsView>

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

private:
    QPointF m_scene_mouse_position;

    void setupUi();
};

#endif // OUTPUT_VIEW_HPP
