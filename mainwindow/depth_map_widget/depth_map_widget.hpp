#ifndef DEPTH_MAP_WIDGET_HPP
#define DEPTH_MAP_WIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class DepthMapWidget : public QWidget
{
public:
    explicit DepthMapWidget(QWidget *t_parent = nullptr);
    virtual ~DepthMapWidget();

private:
    void setupUi();
};

#endif // DEPTH_MAP_WIDGET_HPP
