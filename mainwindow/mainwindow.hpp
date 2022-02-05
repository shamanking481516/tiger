#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class ImagePairOpenWidget;
class ImageViewer;
class DepthMapWidget;
class ImageParametersWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *t_parent = nullptr);
    virtual ~MainWindow();

private:
    ImagePairOpenWidget *m_image_pair_open_widget;
    ImageViewer *m_image_viewer;
    DepthMapWidget *m_depth_map_widget;
    ImageViewer *m_crop_image_viewer;
    ImageParametersWidget *m_image_parameters_widget;

    void setupUi();
    void initializationOfConnection();
};

#endif // MAINWINDOW_HPP
