#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
}

Dialog3::~Dialog3()
{
    delete ui;
}
QString Dialog3::appointname(){return ui->textEditname->toPlainText();}
QString Dialog3::appointsex(){return ui->textEditsex->toPlainText();}
QDate Dialog3::appointdate(){return ui->dateEditappoint->date();}
QString Dialog3::appointtel(){return ui->textEdittel->toPlainText();}
int Dialog3::appointage(){ QString sage=ui->textEditage->toPlainText();
                           int age=sage.toInt();
                           return age;}

int Dialog3::oworknumber(){ QString swn=ui->textEditoworknumber->toPlainText();
                           int oworknumber=swn.toInt();
                           return oworknumber;}
