#ifndef LOADIMAGE2_H
#define LOADIMAGE2_H

#include <QMainWindow>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
#include <QLabel>

namespace Ui {
class loadimage2;
}

class loadimage2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit loadimage2(QWidget *parent = 0);
    ~loadimage2();

    //void chooseImage(const QString &title, QImage *image, QLabel *label);
    //void loadImage(const QString &fileName, QImage *image, QLabel *label);


private slots:
    //void chooseSource(void);
    void on_actionOpen_triggered();

private:
    Ui::loadimage2 *ui;
    QImage srcImage;
};

#endif // LOADIMAGE2_H
