#ifndef OUTPUT_SCENE_HPP
#define OUTPUT_SCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <opencv2/opencv.hpp>

class OutputScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit OutputScene(QObject *t_parent = nullptr);
    virtual ~OutputScene();

    void setMat(const cv::Mat &t_mat);

public slots:
    void setPreviousPosition(const QPointF t_previous_position);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *t_event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *t_event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *t_event) override;

private:
    QGraphicsPixmapItem *m_pixmap_item;
    QGraphicsRectItem *m_selection;
    QPointF m_previous_position;
    bool m_is_left_mouse_buttom_pressed{false};

signals:
    void previousPositionChanged();
};

#endif // OUTPUT_SCENE_HPP
