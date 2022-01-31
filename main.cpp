#include <QApplication>
#include "mainwindow/mainwindow.hpp"
#include "image_pair_open_object/image_pair_open_widget.hpp"
#include "image_viewer/image_viewer.hpp"
#include "depth_map_processor/depth_map_processor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ImagePairOpenWidget wgt;
    wgt.show();

    ImageViewer view;
    view.show();

    QObject::connect(&wgt, &ImagePairOpenWidget::firstOpened, [&](){
        view.setMat(wgt.getFirstMat());
    });
    return app.exec();
}
