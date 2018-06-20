#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    resize(800, 640);
    pix = QPixmap(200, 160);
    pix.fill(Qt::white);
    scale =1;
    button = new QPushButton(this);
    button->setText(tr("ZoomIn"));
    button->move(720, 600);
    button2 = new QPushButton(this);
    button2->setText(tr("ZoomOut"));
    button2->move(640, 600);
    button3 = new QPushButton(this);
    button3->setText(tr("Save"));
    button3->move(560, 600);
    connect(button, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(button2, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(button3, SIGNAL(clicked()), this, SLOT(Save()));
}
void Dialog::paintEvent(QPaintEvent *)
{
    QPainter p(&pix);
    p.drawLine(lastPoint/scale, endPoint/scale);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.scale(scale, scale);
    painter.drawPixmap(0,0,pix);
}
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons()==Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::zoomIn()
{
    scale *=2;
    update();
}
void Dialog::zoomOut()
{
    scale /=2;
    update();
}
void Dialog::Save()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image."),QString(),
            tr("Image Files(*.jpg);;"));
    if(!fileName.isEmpty()){
        QFile file(fileName);

    if(file.open(QIODevice::WriteOnly)){
            pix.save(fileName);
        }
    }
}
