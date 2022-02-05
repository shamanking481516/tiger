#include "depth_map_processor.hpp"

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
        cv::Mat first_temp;
        t_first_mat.convertTo(first_temp, CV_64FC3);
        cv::Mat second_temp;
        t_second_mat.convertTo(second_temp, CV_64FC3);
        cv::divide(first_temp, second_temp, m_depth_map);
        cv::normalize(m_depth_map, m_depth_map, 0, 255, cv::NORM_MINMAX);
        m_depth_map.convertTo(m_depth_map, CV_8UC3);
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
