#ifndef IMAGE_OPEN_OBJECT_HPP
#define IMAGE_OPEN_OBJECT_HPP

#include <QObject>
#include <opencv2/opencv.hpp>

class ImageOpenObject : public QObject
{
    Q_OBJECT
public:
    explicit ImageOpenObject(QObject *t_parent = nullptr);
    virtual ~ImageOpenObject();

    void openMat(const QString &t_filename);
    const cv::Mat &getMat() const;
    const bool getStatus() const;

private:
    cv::Mat m_mat;
    bool m_status{false};

signals:
    void opened();
    void failed();
};

#endif // IMAGE_OPEN_OBJECT_HPP
