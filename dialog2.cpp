#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}
QString Dialog2::Name(){


    return ui->textEditName->toPlainText();
}
int Dialog2::Number()
{
    QString sNumber = ui->textEditNumber->toPlainText();
    int number = sNumber.toInt();
    return number;
}

int Dialog2::worknumber()
{
    QString sworknumber=ui->textEditworknumber->toPlainText();
    int Worknumber=sworknumber.toInt();
    return Worknumber;
}
QString Dialog2::address()
{
    return ui->textEditaddress->toPlainText();
}
int Dialog2::cap()
{
    QString scap=ui->textEditcap->toPlainText();
    int Cap=scap.toInt();return Cap;
}
QString Dialog2::tel()
{
    return ui->textEdittel->toPlainText();
}
QDate Dialog2::outpatientDate(){ return ui->dateEditoutpatient->date();}
