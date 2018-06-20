#include "imagearithmetic.h"
#include "ui_imagearithmetic.h"

ImageArithmetic::ImageArithmetic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageArithmetic)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()),
                this, SLOT(chooseSource()));
    connect(ui->toolButton_2, SIGNAL(clicked()),
                this, SLOT(chooseSource2()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),
                this, SLOT(calcResult(int)));
    setWindowTitle("ImageArithmetic");
}

ImageArithmetic::~ImageArithmetic()
{
    delete ui;
}

void ImageArithmetic::chooseSource()
{
    chooseImage(tr("Choose Source1 Image"), &srcImg, ui->toolButton);
}
void ImageArithmetic::chooseSource2()
{
    chooseImage(tr("Choose Source2 Image"), &srcImg_2,ui->toolButton_2);
}
void ImageArithmetic::chooseImage(const QString &title, QImage *image,
                         QToolButton *button)
{
    QString fileName = QFileDialog::getOpenFileName(this, title);
    if (!fileName.isEmpty())
    {
        loadImage(fileName, image, button);
    }
}


void ImageArithmetic::loadImage(const QString &fileName, QImage *image,
                       QToolButton *button)
{
    image->load(fileName);
    *image = image->convertToFormat(QImage::Format_RGB32);
    button->setIconSize(QSize(image->width(), image->height()));
    button->setIcon(QPixmap::fromImage(*image));
}

void ImageArithmetic::calcResult(int index)
{
    LogicOperator(&srcImg, &srcImg_2, &desImg, index);
    ui->label_2->setPixmap(QPixmap::fromImage(desImg));
}

// logicOperator
void ImageArithmetic::LogicOperator(QImage *src1, QImage *src2,
                           QImage *output, int Method)
{
    int i, j;
    int tmpPixel;
    unsigned char *src1Pixel, *src2Pixel;
    src1Pixel = new unsigned char[src1->height()*src1->width()];
    src2Pixel = new unsigned char[src2->height()*src2->width()];
    *output = *src1;

    // copy pixels to matrix [1]
    for(j=0; j< src1->height(); j++)
        for(i=0; i< src1->width(); i++)
        {
        src1Pixel[i + j*src1->width()] =
                (unsigned char)qGray(src1->pixel(i,j));
    }
    for(j=0; j< src2->height(); j++)
        for(i=0; i< src2->width(); i++)
        {
        src2Pixel[i + j*src2->width()] =
                (unsigned char)qGray(src2->pixel(i,j));
    }
    // End copy pixels to matrix [1]



    // Logic Operator [2]
    switch(Method)
    {
    case ADD:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         + src2Pixel[i + j*src2->width()])>>1;
            output->setPixel(i, j, qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
        break;

        case SUB:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         - src2Pixel[i + j*src2->width()])>>1;
            output->setPixel(i, j, qRgb(tmpPixel,tmpPixel,tmpPixel));
            }
        break;

        case OR:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         | src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
        break;

        case NOR:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         | src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(~tmpPixel,~tmpPixel,~tmpPixel));
        }
        break;

        case AND:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         & src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
        break;

        case NAND:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         & src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(~tmpPixel,~tmpPixel,~tmpPixel));
        }
        break;

        case XOR:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         ^ src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
        break;

        case NXOR:
        for(j=0; j< src2->height(); j++)
            for(i=0; i< src2->width(); i++)
            {
            tmpPixel = ( src1Pixel[i + j*src1->width()]
                         ^ src2Pixel[i + j*src2->width()] );
            output->setPixel(i, j, qRgb(~tmpPixel,~tmpPixel,~tmpPixel));
        }
        break;
    }
    // End Logic Operator [2]
    delete [] src1Pixel;
    delete [] src2Pixel;
}
