#include "mainwindow.hpp"
#include "image_pair_open_widget/image_pair_open_widget.hpp"
#include "image_viewer/image_viewer.hpp"

#include <QDockWidget>

MainWindow::MainWindow(QWidget *t_parent) :
    QMainWindow{t_parent},
    m_image_pair_open_widget{new ImagePairOpenWidget},
    m_image_viewer{new ImageViewer}
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
}

void MainWindow::initializationOfConnection()
{
    connect(m_image_pair_open_widget, &ImagePairOpenWidget::firstShow, this, [&](){
        m_image_viewer->setMat(m_image_pair_open_widget->getFirstMat());
    });
    connect(m_image_pair_open_widget, &ImagePairOpenWidget::secondShow, this, [&](){
        m_image_viewer->setMat(m_image_pair_open_widget->getSecondMat());
    });
}
