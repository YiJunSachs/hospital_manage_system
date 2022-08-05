#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include<QString>
#include<qdatetime.h>
#include<QTextStream>

class appointment
{
public:
    appointment(QString pn,QString pt,QString s,int a,QDate pd,int ow);
    appointment();
    QString pname;
    QString ptel;
    QString sex;
    int age;
   QDate pdate;
int oworknumber;

    void Saveappointment(QTextStream &aStream);
    void Readappointment(QTextStream &aStream);
~appointment();

};

#endif // APPOINTMENT_H
