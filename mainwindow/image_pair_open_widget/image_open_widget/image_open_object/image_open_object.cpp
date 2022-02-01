#include "image_open_object.hpp"

ImageOpenObject::ImageOpenObject(QObject *t_parent) :
    QObject{t_parent}
{

}

ImageOpenObject::~ImageOpenObject()
{

}

void ImageOpenObject::openMat(const QString &t_filename)
{
    m_mat = cv::imread(t_filename.toStdString());
    m_mat.convertTo(m_mat, CV_8UC3);
    if (!m_mat.empty())
    {
        m_status = true;
        emit opened();
    }
    else
    {
        m_status = false;
        emit failed();
    }
}

const cv::Mat &ImageOpenObject::getMat()
{
    return m_mat;
}

const bool ImageOpenObject::getStatus()
{
    return m_status;
}
