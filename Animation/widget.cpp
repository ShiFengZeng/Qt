#include "widget.h"
#include "ui_widget.h"
#include "SItem.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-400, -400, 600, 600);
    QPen mypen = QPen(Qt::red);

        QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
        QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
        QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
        QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

        scene->addLine(TopLine,mypen);
        scene->addLine(LeftLine,mypen);
        scene->addLine(RightLine,mypen);
        scene->addLine(BottomLine,mypen);

        int ItemCount = 6;
            for(int i = 0; i < ItemCount; i++)
            {
                SItem *item = new SItem();
                scene->addItem(item);
            }

            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), scene,SLOT(advance()));
            timer->start(100);

}

Widget::~Widget()
{
    delete ui;
}
