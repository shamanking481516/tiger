#ifndef IMAGE_PARAMETERS_WIDGET_HPP
#define IMAGE_PARAMETERS_WIDGET_HPP

#include <QWidget>

class ImageParametersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageParametersWidget(QWidget *t_parent = nullptr);
    virtual ~ImageParametersWidget();

private:
    void setupUi();
};

#endif // IMAGE_PARAMETERS_WIDGET_HPP
