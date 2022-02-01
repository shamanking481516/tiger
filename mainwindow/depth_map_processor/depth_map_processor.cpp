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
    cv::divide(t_first_mat, t_second_mat, m_depth_map);
    m_depth_map.empty() ? emit failed() : emit computed();
}

const cv::Mat &DepthMapProcessor::getDepthMat()
{
    return m_depth_map;
}
