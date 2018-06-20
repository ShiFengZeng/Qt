#ifndef IMAGEARITHMETIC_H
#define IMAGEARITHMETIC_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>

enum Logic{ADD=1, SUB, OR, NOR, AND, NAND, XOR, NXOR};

namespace Ui {
class ImageArithmetic;
}

class ImageArithmetic : public QWidget
{
    Q_OBJECT

public:
    explicit ImageArithmetic(QWidget *parent = 0);
    ~ImageArithmetic();
    void chooseImage(const QString &title, QImage *image,
                         QToolButton *button);
    void loadImage(const QString &fileName, QImage *image,
                       QToolButton *button);
    void LogicOperator(QImage *srcImg_1, QImage *srcImg_2,
                           QImage *output, int Method);

    private slots:
        void chooseSource(void);
        void chooseSource2(void);
        void calcResult(int);
private:
    Ui::ImageArithmetic *ui;
    QImage srcImg;
    QImage srcImg_2;
    QImage desImg;

};

#endif // IMAGEARITHMETIC_H
