#include "loadimage2.h"
#include "ui_loadimage2.h"

loadimage2::loadimage2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loadimage2)
{
    ui->setupUi(this);
    //connect(ui->label,SIGNAL(clicked()),this,SLOT(chooseSource()));
}

loadimage2::~loadimage2()
{
    delete ui;
}

void loadimage2::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,title,"",tr("Image File(*.jpg *.jpeg *.png *.gif *.bmp *.tif *.tiff );"));
    if (QString::compare(filename,QString())!=0)
    {
            QImage image;
            bool v = image.load(filename);
            if(v)
            {
               image=image.scaledToWidth(ui->label->width(),Qt::SmoothTransformation);
               ui->label->setPixmap(QPixmap::fromImage(image));
            }
            else
            {

            }
     }
}
