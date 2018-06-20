#include "imagetransform.h"
#include "ui_imagetransform.h"


imagetransform::imagetransform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::imagetransform)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(chooseSource()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(ImgMirrored()));
    connect(ui->dial, SIGNAL(valueChanged(int)),this, SLOT(ImgRotation()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),this, SLOT(ImgShear()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(resetImg()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(saveImg()));
    setWindowTitle("Geometric Transform");

}

imagetransform::~imagetransform()
{
    delete ui;
}

void imagetransform::ImgShear(void)
{
    QTransform transform;
    int num;
    bool isXAxis;
    num = ui->horizontalSlider->value();
    isXAxis = ui->radioButton->isChecked();
    if(isXAxis)
    {
        transform.shear(num, 0);
    }
    else
    {
        transform.shear(0, num);
    }
    desImg = srcImg.transformed(transform);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}

void imagetransform::ImgRotation(void)
{
    QTransform transform;
    int angle;
    angle = ui->dial->value();
    transform.rotate(angle);
    desImg = srcImg.transformed(transform);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}

void imagetransform::ImgMirrored(void)
{
    bool H, V;
    H = ui->checkBox->isChecked();
    V = ui->checkBox_2->isChecked();
    desImg = tmpImg.mirrored(H, V);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
    tmpImg = desImg;
}

void imagetransform::resetImg(void)
{
   desImg = srcImg;
   ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}
void imagetransform::saveImg(void)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                    "Images (*.png *.jpg *.xpm");
    if (!fileName.isEmpty()) {
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)) {
                    // error message
                } else {
                    desImg.save(fileName);
                }
            }

}

void imagetransform::chooseSource(void)
{
    QString fileName = QFileDialog::getOpenFileName(this,"","",tr("Image File(*.jpg *.jpeg *.png *.gif *.bmp *.tif *.tiff );"));
    if (!fileName.isEmpty())
    {
        srcImg.load(fileName);
        desImg = srcImg;
        tmpImg = srcImg;
        ui->toolButton->setIconSize(QSize(srcImg.width(),srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(srcImg));
        ui->toolButton_2->setIconSize(QSize(desImg.width(),desImg.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
        ui->dial->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}
