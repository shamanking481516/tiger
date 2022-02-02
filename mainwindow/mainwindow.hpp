#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QComboBox>

class ImagePairOpenWidget;
class ImageViewer;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *t_parent = nullptr);
    virtual ~MainWindow();

private:
    ImagePairOpenWidget *m_image_pair_open_widget;
    ImageViewer *m_image_viewer;

    void setupUi();
    void initializationOfConnection();
};

#endif // MAINWINDOW_HPP
