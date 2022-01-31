#ifndef IMAGE_VIEWER_HPP
#define IMAGE_VIEWER_HPP

#include <QWidget>
#include "output_scene/output_scene.hpp"
#include "output_view/output_view.hpp"
#include <opencv2/opencv.hpp>

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *t_parent = nullptr);
    virtual ~ImageViewer();
    void setMat(const cv::Mat &t_mat);

private:
    OutputScene *m_scene;
    OutputView *m_output_view;
};

#endif // IMAGE_VIEWER_HPP
