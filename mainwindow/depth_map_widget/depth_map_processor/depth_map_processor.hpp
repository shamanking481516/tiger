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

    void computeDepthMap(const cv::Mat &t_first_mat, const cv::Mat &t_second_mat, const bool t_is_normalize);
    const cv::Mat &getDepthMat() const;
    const bool getStatus() const;

public slots:
    void setFirstParameter(double t_first_parameter);
    void setSecondParameter(double t_second_parameter);

private:
    cv::Mat m_depth_map;
    double m_first_parameter{0};
    double m_second_parameter{0};
    bool m_status{false};

    cv::Mat getGrayDoubleMat(const cv::Mat &t_mat);
    cv::Mat getNormalMat(const cv::Mat &t_mat);
    cv::Mat getColorMapMat(const cv::Mat &t_mat);

signals:
    void statusChanged();
};

#endif // DEPTH_MAP_PROCESSOR_HPP
