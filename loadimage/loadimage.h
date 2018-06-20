#ifndef LOADIMAGE_H
#define LOADIMAGE_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>

namespace Ui {
class loadimage;
}

class loadimage : public QWidget
{
    Q_OBJECT

public:
    explicit loadimage(QWidget *parent = 0);
    ~loadimage();

    void chooseImage(const QString &title, QImage *image, QToolButton *button);
    void loadImage(const QString &fileName, QImage *image, QToolButton *button);
private slots:
    void chooseSource(void);

private:
    Ui::loadimage *ui;
    QImage srcImage;
};

#endif // LOADIMAGE_H
