#include "depth_map_processor.hpp"
#include <QDebug>

DepthMapProcessor::DepthMapProcessor(QObject *t_parent) :
    QObject{t_parent}
{

}

DepthMapProcessor::~DepthMapProcessor()
{

}

void DepthMapProcessor::computeDepthMap(const cv::Mat &t_first_mat, const cv::Mat &t_second_mat)
{
    m_depth_map = 0;
    if (t_first_mat.size() == t_second_mat.size())
    {
        cv::Mat first_temp = getGrayDoubleMat(t_first_mat);
        cv::Mat second_temp = getGrayDoubleMat(t_second_mat);
        cv::divide(first_temp, second_temp, m_depth_map);
        m_depth_map -= m_first_parameter;
        cv::divide(m_depth_map, m_second_parameter, m_depth_map);
//        cv::normalize(m_depth_map, m_depth_map, 0, 255, cv::NORM_MINMAX);
//        m_depth_map = getNormalMat(m_depth_map);
        m_depth_map.convertTo(m_depth_map, CV_8UC1);
        m_depth_map = getColorMapMat(m_depth_map);
    }
    m_status = !m_depth_map.empty();
    emit statusChanged();
}

const cv::Mat &DepthMapProcessor::getDepthMat() const
{
    return m_depth_map;
}

const bool DepthMapProcessor::getStatus() const
{
    return m_status;
}

void DepthMapProcessor::setFirstParameter(double t_first_parameter)
{
    m_first_parameter = t_first_parameter;
}

void DepthMapProcessor::setSecondParameter(double t_second_parameter)
{
    m_second_parameter = t_second_parameter;
}

cv::Mat DepthMapProcessor::getGrayDoubleMat(const cv::Mat &t_mat)
{
    cv::Mat result;
    cv::cvtColor(t_mat, result, cv::COLOR_BGR2GRAY);
    result.convertTo(result, CV_64FC1);
    return result;
}

cv::Mat DepthMapProcessor::getNormalMat(const cv::Mat &t_mat)
{
    cv::Mat result;
    t_mat.convertTo(result, CV_8UC1);
    cv::cvtColor(result, result, cv::COLOR_GRAY2BGR);
    result.convertTo(result, CV_8UC3);
    return result;
}

cv::Mat DepthMapProcessor::getColorMapMat(const cv::Mat &t_mat)
{
    if (t_mat.channels() == 1)
    {
        cv::Mat result;
        cv::applyColorMap(t_mat, result, cv::COLORMAP_JET);
        return result;
    }
    else
        return cv::Mat();
}
