#include "loadimage.h"
#include "ui_loadimage.h"

loadimage::loadimage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loadimage)
{
    ui->setupUi(this);
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
}

loadimage::~loadimage()
{
    delete ui;
}

void loadimage::chooseSource(void)
{
    chooseImage(tr("Choose Source Image."), &srcImage,ui->toolButton);
}

void loadimage::chooseImage(const QString &title, QImage *image, QToolButton *button)
{
    QString fileName = QFileDialog::getOpenFileName(this,title,"",tr("Image File(*.jpg *.jpeg *.png *.gif *.bmp *.tif *.tiff );"));
    if (!fileName.isEmpty())
    {
        loadImage(fileName,image,button);
    }
}
void loadimage::loadImage(const QString &fileName, QImage *image, QToolButton *button)
{
  image->load(fileName);
  button->setIconSize(QSize(image->width(),image->height()));
  button->setIcon(QPixmap::fromImage(*image));
}
