#ifndef IMAGETRANSFORM_H
#define IMAGETRANSFORM_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
#include <QTransform>


namespace Ui {
class imagetransform;
}

class imagetransform : public QWidget
{
    Q_OBJECT

public:
    explicit imagetransform(QWidget *parent = 0);
    ~imagetransform();

private slots:
    void chooseSource(void);
    void ImgShear(void);
    void ImgMirrored(void);
    void ImgRotation(void);
    void resetImg(void);
    void saveImg(void);

private:
    Ui::imagetransform *ui;
    QImage srcImg;
    QImage desImg;
    QImage tmpImg;
};




#endif // IMAGETRANSFORM_H
