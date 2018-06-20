#include "bitplane.h"
#include "ui_bitplane.h"

BitPlane::BitPlane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BitPlane)
{
    ui->setupUi(this);
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    addComboList();
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(showBitPlane(int)));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(saveImg()));
}

BitPlane::~BitPlane()
{
    delete ui;
}

void BitPlane::addComboList()
{
    ui->comboBox->addItem("none");
    ui->comboBox->addItem("bit 0");
    ui->comboBox->addItem("bit 1");
    ui->comboBox->addItem("bit 2");
    ui->comboBox->addItem("bit 3");
    ui->comboBox->addItem("bit 4");
    ui->comboBox->addItem("bit 5");
    ui->comboBox->addItem("bit 6");
    ui->comboBox->addItem("bit 7");
}
void BitPlane::showBitPlane(int index)
{
    switch(index)
    {
    case 1:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit0Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit0Img));
        resultImg = bit0Img;
        break;
    case 2:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit1Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit1Img));
        resultImg = bit1Img;
        break;
    case 3:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit2Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit2Img));
        resultImg = bit2Img;
        break;
    case 4:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit3Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit3Img));
        resultImg = bit3Img;
        break;
    case 5:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit4Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit4Img));
        resultImg = bit4Img;
        break;
    case 6:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit5Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit5Img));
        resultImg = bit5Img;
        break;
    case 7:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit6Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit6Img));
        resultImg = bit6Img;
        break;
    case 8:
        ui->toolButton_2->setIconSize(QSize(bit0Img.width(),bit7Img.height()));
        ui->toolButton_2->setIcon(QPixmap::fromImage(bit7Img));
        resultImg = bit7Img;
        break;
    }
}

void BitPlane::chooseSource(void)
{
    chooseImage(tr("Choose Source Image."),&srcImg,ui->toolButton);
}

void BitPlane::chooseImage(const QString &title,QImage *image,QToolButton *button)
{
    QString fileName = QFileDialog::getOpenFileName(this,title,"",tr("Image File(*.jpg *.jpeg *.png *.gif *.bmp *.tif *.tiff );"));
    if(!fileName.isEmpty())
    {
        loadImage(fileName,image,button);
    }
}

void BitPlane::loadImage(const QString &fileName,QImage *image,QToolButton *button)
{
    image->load(fileName);
    button->setIconSize(QSize(image->width(),image->height()));
    button->setIcon(QPixmap::fromImage(*image));
    getBitPlane();
}

void BitPlane::getBitPlane()
{
    int i,j;
    MyByte Byte;
    bool bitPix;
    QSize imageSize=QSize(srcImg.width(),srcImg.height());
    bit0Img=QImage(imageSize,QImage::Format_Mono);
    bit1Img=QImage(imageSize,QImage::Format_Mono);
    bit2Img=QImage(imageSize,QImage::Format_Mono);
    bit3Img=QImage(imageSize,QImage::Format_Mono);
    bit4Img=QImage(imageSize,QImage::Format_Mono);
    bit5Img=QImage(imageSize,QImage::Format_Mono);
    bit6Img=QImage(imageSize,QImage::Format_Mono);
    bit7Img=QImage(imageSize,QImage::Format_Mono);

    for(j=0;j<srcImg.height();j++)
    {
        for(i=0;i<srcImg.width();i++)
        {
            Byte.byte=qGray(srcImg.pixel(i,j));
            bitPix=(Byte.bit.bit0==1)?1:0;
            bit0Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit1==1)?1:0;
            bit1Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit2==1)?1:0;
            bit2Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit3==1)?1:0;
            bit3Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit4==1)?1:0;
            bit4Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit5==1)?1:0;
            bit5Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit6==1)?1:0;
            bit6Img.setPixel(i,j,bitPix);
            bitPix=(Byte.bit.bit7==1)?1:0;
            bit7Img.setPixel(i,j,bitPix);

        }
    }
}

void BitPlane::saveImg()
{
   /* QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image."),QString(),
        tr("Image Files(*.jpg);;"));

    QPixmap pix(ui->toolButton_2->grab());

    pix.save(fileName);
*/

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image."),QString(),
            tr("Image Files(*.jpg);;"));
    if(!fileName.isEmpty()){
        QFile file(fileName);

    if(file.open(QIODevice::WriteOnly)){
            resultImg.save(fileName);
        }
    }
}
