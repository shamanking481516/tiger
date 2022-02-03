#include "mainwindow.hpp"
#include "image_pair_open_widget/image_pair_open_widget.hpp"
#include "image_viewer/image_viewer.hpp"

#include <QDockWidget>

MainWindow::MainWindow(QWidget *t_parent) :
    QMainWindow{t_parent},
    m_image_pair_open_widget{new ImagePairOpenWidget},
    m_image_viewer{new ImageViewer},
    m_depth_map_widget{new DepthMapWidget},
    m_crop_image_viewer{new ImageViewer}
{
    setupUi();
    initializationOfConnection();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi()
{
    setCentralWidget(m_image_viewer);
    auto image_pair_open_dock_widget = new QDockWidget(tr("Open a Pair of Images"));
    image_pair_open_dock_widget->setFeatures(QDockWidget::DockWidgetMovable);
    image_pair_open_dock_widget->setWidget(m_image_pair_open_widget);
    image_pair_open_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, image_pair_open_dock_widget);

    auto depth_map_dock_widget = new QDockWidget(tr("Depth Map Calculation Options"));
    depth_map_dock_widget->setFeatures(QDockWidget::DockWidgetMovable);
    depth_map_dock_widget->setWidget(m_depth_map_widget);
    depth_map_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, depth_map_dock_widget);

    auto crop_image_dock_widget = new QDockWidget(tr("Crop Image Viewer"));
    crop_image_dock_widget->setFeatures(QDockWidget::DockWidgetMovable);
    crop_image_dock_widget->setWidget(m_crop_image_viewer);
    crop_image_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, crop_image_dock_widget);
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
}
