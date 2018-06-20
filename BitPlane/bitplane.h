#ifndef BITPLANE_H
#define BITPLANE_H
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include<QDataStream>

#include <QWidget>
#include <QToolBUtton>
#include <QImage>
#include <QFileDialog>
#include "Bitfield.h"
namespace Ui {
class BitPlane;
}

class BitPlane : public QWidget
{
    Q_OBJECT

public:
    explicit BitPlane(QWidget *parent = 0);
    ~BitPlane();

    void chooseImage(const QString &title,QImage *image,QToolButton *button);
    void loadImage(const QString &fileName,QImage *image,QToolButton *button);
    void addComboList();
    void getBitPlane();

private slots:
    void chooseSource(void);
    void showBitPlane(int);

    void saveImg();

private:
    Ui::BitPlane *ui;
    QImage srcImg;
    QImage bit0Img;
    QImage bit1Img;
    QImage bit2Img;
    QImage bit3Img;
    QImage bit4Img;
    QImage bit5Img;
    QImage bit6Img;
    QImage bit7Img;
    QImage resultImg;
};

#endif // BITPLANE_H
