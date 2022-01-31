#ifndef DEPTH_MAP_PROCESSOR_HPP
#define DEPTH_MAP_PROCESSOR_HPP

#include <QObject>
#include <opencv2/opencv.hpp>

class DepthMapProcessor : public QObject
{
    Q_OBJECT
public:
    explicit DepthMapProcessor(QObject *t_parent = nullptr);
    virtual ~DepthMapProcessor();

    void computeDepthMap(const cv::Mat &t_first_mat, const cv::Mat &t_second_mat);
    const cv::Mat &getDepthMat();

private:
    cv::Mat m_depth_map;

signals:
    void computed();
    void failed();
};

#endif // DEPTH_MAP_PROCESSOR_HPP
