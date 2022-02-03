#ifndef DEPTH_MAP_WIDGET_HPP
#define DEPTH_MAP_WIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

#include "depth_map_processor/depth_map_processor.hpp"
#include <opencv2/opencv.hpp>

class QDoubleSpinBox;
class QPushButton;

class DepthMapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DepthMapWidget(QWidget *t_parent = nullptr);
    virtual ~DepthMapWidget();

    void setReadinessStatus(bool t_status);
    void computeDepthMap(const cv::Mat &t_first_mat, const cv::Mat &t_second_mat);
    const cv::Mat &getDepthMat();

private:
    bool m_readiness_status{false};
    bool m_status{false};
    DepthMapProcessor *m_depth_map_processor;
    QDoubleSpinBox *m_first_spin_box;
    QDoubleSpinBox *m_second_spin_box;
    QPushButton *m_compute_button;
    QPushButton *m_show_button;

    void setupUi();
    void initializationOfConnection();

signals:
    void computeButtonClicked();
    void showButtonClicked();
    void computed();
    void failed();
};

#endif // DEPTH_MAP_WIDGET_HPP
