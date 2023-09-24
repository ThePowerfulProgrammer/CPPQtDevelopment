#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QTimer>

Dialog::Dialog(QWidget *parent, int timeInterval) :
    QDialog(parent),timeChange(timeInterval),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    imagePaths << ":/new/prefix1/red.jpg"
               << ":/new/prefix1/green.jpg"
               << ":/new/prefix1/yellow.jpg";

    currentImageIndex = 0;

    imageTimer = new QTimer(this);
    connect(imageTimer, &QTimer::timeout, this, &Dialog::rotateImages);
    imageTimer->start(timeChange);

    rotateImages(); // Start initial rotation
}

void Dialog::rotateImages()
{
    currentImageIndex = (currentImageIndex + 1) % imagePaths.size();
    QPixmap pix(imagePaths[currentImageIndex]);
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
}

Dialog::~Dialog()
{
    delete ui;
}
