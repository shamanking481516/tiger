#ifndef OUTPUT_SCENE_HPP
#define OUTPUT_SCENE_HPP

#include <QGraphicsScene>
#include <opencv2/opencv.hpp>

class OutputScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit OutputScene(QObject *t_parent = nullptr);
    virtual ~OutputScene();

    void setMat(const cv::Mat &t_mat);
    void clearScene();

private:
    QGraphicsPixmapItem *m_pixmap_item;
};

#endif // OUTPUT_SCENE_HPP
