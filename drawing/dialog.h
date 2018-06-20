#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QPainter>
#include <QFileDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void zoomIn();
    void zoomOut();
    void Save();
private:

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
    qreal scale;
    QPushButton *button;
    QPushButton *button2;
    QPushButton *button3;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
