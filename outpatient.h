#ifndef OUTPATIENT_H
#define OUTPATIENT_H
#include<QString>
#include"appointment.h"
#include<QVector>
#include<qdatetime.h>
#include<QTextStream>
#include<vector>

class outpatient
{
public:
    outpatient(QString n,int nu,int wn,QDate d,int c,QString ad,QString t);
    outpatient();
    QString name;
    int number;
    int worknumber;
   QDate date;
    int cap;
    QString address;
    QString tel;

    QVector<appointment>aarray;
    int anum;
    void addappointment(appointment &a);
    int getappointmentnum();
    appointment &getappointment(int index);
    outpatient &operator=(const outpatient&pa);

    void Saveoutpatient(QTextStream &aStream);
    void Readoutpatient(QTextStream &aStream);
~outpatient();

};

#endif // OUTPATIENT_H
