#include "mainwindow.hpp"
#include <QDockWidget>

MainWindow::MainWindow(QWidget *t_parent) :
    QMainWindow{t_parent},
    m_image_pair_open_widget{new ImagePairOpenWidget},
    m_image_viewer{new ImageViewer}
{
    setupUi();
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
    addDockWidget(Qt::RightDockWidgetArea, image_pair_open_dock_widget);
}
