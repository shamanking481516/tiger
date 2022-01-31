#include "image_open_widget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QLabel>

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
    auto *vbox_layout{new QVBoxLayout};
    vbox_layout->setContentsMargins(0, 0, 0, 0);
    auto *label{new QLabel(m_label_text)};
    vbox_layout->addWidget(label);
    auto *hbox_layout{new QHBoxLayout};
    hbox_layout->setContentsMargins(0, 0, 0, 0);
    m_filename_lineedit = new QLineEdit;
    m_browse_button = new QPushButton(tr("Browse"));
    hbox_layout->addWidget(m_filename_lineedit);
    hbox_layout->addWidget(m_browse_button);
    vbox_layout->addLayout(hbox_layout);
    setLayout(vbox_layout);
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
        emit opened();
    });
    connect(m_image_open_object, &ImageOpenObject::failed, this, [&](){
        m_filename_lineedit->setStyleSheet("background: red");
        emit failed();
    });
}

const QString ImageOpenWidget::selectFileToOpen()
{
    const QString caption {tr("Open Image")};
    const QString filter {tr("Images (*.jpeg)")};
    const QString filename = QFileDialog::getOpenFileName(this, caption, QDir::homePath(), filter);
    return filename;
}
