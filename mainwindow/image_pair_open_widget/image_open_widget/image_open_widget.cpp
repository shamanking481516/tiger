#include "image_open_widget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QLabel>
#include <QGroupBox>

#include "image_open_object/image_open_object.hpp"

ImageOpenWidget::ImageOpenWidget(const QString &t_label_text, QWidget *t_parent) :
    m_label_text{t_label_text},
    QWidget{t_parent},
    m_image_open_object{new ImageOpenObject(this)}
{
    setupUi();
    initializationOfConnection();
}

ImageOpenWidget::~ImageOpenWidget()
{

}

const cv::Mat &ImageOpenWidget::getMat()
{
    return m_image_open_object->getMat();
}

const bool ImageOpenWidget::getStatus()
{
    return m_image_open_object->getStatus();
}

void ImageOpenWidget::setupUi()
{
    auto *group_box{new QGroupBox};
    group_box->setTitle(m_label_text);
    auto *vbox_layout{new QVBoxLayout};
    vbox_layout->setContentsMargins(0, 0, 0, 0);
    auto *hbox_layout{new QHBoxLayout};
    hbox_layout->setContentsMargins(0, 0, 0, 0);
    m_filename_lineedit = new QLineEdit;
    m_browse_button = new QPushButton(tr("Browse"));
    hbox_layout->addWidget(m_filename_lineedit);
    hbox_layout->addWidget(m_browse_button);
    m_show_button = new QPushButton(tr("Show Image"));
    m_show_button->setEnabled(false);
    vbox_layout->addLayout(hbox_layout);
    vbox_layout->addWidget(m_show_button);
    group_box->setLayout(vbox_layout);
    auto *layout{new QVBoxLayout};
    layout->addWidget(group_box);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void ImageOpenWidget::initializationOfConnection()
{
    connect(m_browse_button, &QPushButton::clicked, this, [&](){
        const QString filename = selectFileToOpen();
        m_filename_lineedit->setText(filename);
    });
    connect(m_filename_lineedit, &QLineEdit::textChanged, this, [&](){
        m_image_open_object->openMat(m_filename_lineedit->text());
    });
    connect(m_image_open_object, &ImageOpenObject::opened, this, [&](){
        m_filename_lineedit->setStyleSheet("background: green");
        m_show_button->setEnabled(true);
        emit opened();
    });
    connect(m_image_open_object, &ImageOpenObject::failed, this, [&](){
        m_filename_lineedit->setStyleSheet("background: red");
        m_show_button->setEnabled(false);
        emit failed();
    });
    connect(m_show_button, &QPushButton::clicked, this, &ImageOpenWidget::showImage);
}

const QString ImageOpenWidget::selectFileToOpen()
{
    const QString caption {tr("Open Image")};
    const QString filter {tr("Images (*.jpeg *.jpg)")};
    const QString filename = QFileDialog::getOpenFileName(this, caption, QDir::homePath(), filter);
    return filename;
}
