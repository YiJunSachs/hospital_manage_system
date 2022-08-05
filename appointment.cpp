#include "appointment.h"

appointment::appointment(QString pn,QString pt,QString s,int a,QDate pd,int ow)
{pname=pn;
    ptel=pt;
    sex=s;
    age=a;
  pdate=pd;
  oworknumber=ow;

}
appointment::appointment(){}

void appointment::Saveappointment(QTextStream &aStream){
    aStream << pdate.year()<<" "<<pdate.month()<<" "<<pdate.day()<<'\n';
    aStream << pname<<'\n';

    aStream << sex<<'\n';
    aStream <<age<<'\n';
    aStream<<ptel<<'\n';
    aStream<<oworknumber<<'\n';


}
void appointment::Readappointment(QTextStream &aStream) {int year, month, day;
aStream>>year>>month>>day;
pdate.setDate(year, month, day);
aStream >> pname<<'\n';

 aStream >>sex;
 aStream >>age;
  aStream>>ptel;

aStream>>oworknumber;



          }
appointment::~appointment(){}
