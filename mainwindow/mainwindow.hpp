#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *t_parent = nullptr);
    virtual ~MainWindow();

private:

};

#endif // MAINWINDOW_HPP
