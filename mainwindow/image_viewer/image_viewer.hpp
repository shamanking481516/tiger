#ifndef IMAGE_VIEWER_HPP
#define IMAGE_VIEWER_HPP

#include <QWidget>
#include <opencv2/opencv.hpp>

class OutputScene;
class OutputView;

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *t_parent = nullptr);
    virtual ~ImageViewer();

    void setMat(const cv::Mat &t_mat);
    void clearViewer();

private:
    OutputScene *m_scene;
    OutputView *m_output_view;

    void setupUi();
};

#endif // IMAGE_VIEWER_HPP
