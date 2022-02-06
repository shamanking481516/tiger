#include "mainwindow.hpp"
#include "image_pair_open_widget/image_pair_open_widget.hpp"
#include "image_viewer/image_viewer.hpp"
#include "depth_map_widget/depth_map_widget.hpp"
#include "image_parameters_widget/image_parameters_widget.hpp"

#include <QDebug>

MainWindow::MainWindow(QWidget *t_parent) :
    QMainWindow{t_parent},
    m_image_pair_open_widget{new ImagePairOpenWidget},
    m_image_viewer{new ImageViewer},
    m_depth_map_widget{new DepthMapWidget},
    m_crop_image_viewer{new ImageViewer},
    m_image_parameters_widget{new ImageParametersWidget}
{
    setupUi();
    initializationOfConnection();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi()
{
    resize(800, 400);
    setWindowTitle(tr("AP TMS"));
    setCentralWidget(m_image_viewer);
    const auto dock_feature = QDockWidget::DockWidgetMovable;
    const auto dock_areas = Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea;
    addWidgetAsDockWidget(m_image_pair_open_widget, tr("Open a Pair of Images"), dock_feature, dock_areas, Qt::LeftDockWidgetArea);
    addWidgetAsDockWidget(m_depth_map_widget, tr("Depth Map Calculation Options"), dock_feature, dock_areas, Qt::LeftDockWidgetArea);
    addWidgetAsDockWidget(m_crop_image_viewer, tr("Crop Image Viewer"), dock_feature, dock_areas, Qt::RightDockWidgetArea);
    addWidgetAsDockWidget(m_image_parameters_widget, tr("Crop Image Parameters"), dock_feature, dock_areas, Qt::RightDockWidgetArea);
}

void MainWindow::initializationOfConnection()
{
    connect(m_image_pair_open_widget, &ImagePairOpenWidget::firstShow, this, [&](){
        m_image_viewer->setMat(m_image_pair_open_widget->getFirstMat());
    });
    connect(m_image_pair_open_widget, &ImagePairOpenWidget::secondShow, this, [&](){
        m_image_viewer->setMat(m_image_pair_open_widget->getSecondMat());
    });
    connect(m_image_pair_open_widget, &ImagePairOpenWidget::statusChanged, this, [&](){
        m_depth_map_widget->setReadinessStatus(m_image_pair_open_widget->getStatus());
    });
    connect(m_depth_map_widget, &DepthMapWidget::computeButtonClicked, this, [&](){
        m_depth_map_widget->computeDepthMap(m_image_pair_open_widget->getFirstMat(), m_image_pair_open_widget->getSecondMat());
    });
    connect(m_depth_map_widget, &DepthMapWidget::showButtonClicked, this, [&](){
        m_image_viewer->setMat(m_depth_map_widget->getDepthMat());
    });
    connect(m_image_viewer, &ImageViewer::sendSelectedArea, this, [&](const QPixmap t_pixmap){
        m_crop_image_viewer->setPixmap(t_pixmap);
    });
    connect(m_image_viewer, &ImageViewer::sendSelectedArea, this, [&](const QPixmap t_pixmap){
        m_image_parameters_widget->setParametersFromPixmap(t_pixmap);
    });
}

void MainWindow::addWidgetAsDockWidget(QWidget *t_widget,
                                       const QString &t_title,
                                       const QDockWidget::DockWidgetFeature t_feature,
                                       const Qt::DockWidgetAreas t_dock_widget_areas,
                                       const Qt::DockWidgetArea t_dock_selected_area)
{
    auto dock_widget = new QDockWidget(t_title);
    dock_widget->setFeatures(t_feature);
    dock_widget->setWidget(t_widget);
    dock_widget->setAllowedAreas(t_dock_widget_areas);
    addDockWidget(t_dock_selected_area, dock_widget);
}
