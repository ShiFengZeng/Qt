#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void Notepad::on_actionNew_triggered()
{
    mFileName =" ";
    //Notepad::setWindowTitle(mFileName);
    ui->textEdit->setPlainText("");
}

void Notepad::on_actionOpen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Open File"),QString(),
        tr("Text File(*.txt);;C++ File(*.cpp *.h)"));
    if(!FileName.isEmpty()){
        QFile file(FileName);
        if(file.open(QFile::ReadOnly|QFile::Text))
        {
            mFileName = FileName;
            //QMessageBox::critical(this,tr("Error"),tr("Could not open file"));

            QTextStream in(&file);
            QString text =in.readAll();
            file.close();
            ui->textEdit->setPlainText(text);

        }
    }
}

void Notepad::on_actionSave_triggered()
{

    QFile file(mFileName);
    if(mFileName.isEmpty()){
            on_actionSave_as_triggered();
        }

    if(file.open(QFile::WriteOnly|QFile::Text)){
        QTextStream stream(&file);
        stream<<ui->textEdit->toPlainText();
        stream.flush();
        file.close();
    }
}

void Notepad::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),QString(),
        tr("Text Files(*.txt);;C++ Files(*.cpp *.h)"));
    if(!fileName.isEmpty()){
        mFileName = fileName;
        on_actionSave_triggered();

    }
}

void Notepad::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About","This is my first test.<b>Ha Ha!</b>");
}

void Notepad::on_actionQuit_triggered()
{
    this->close();
}
