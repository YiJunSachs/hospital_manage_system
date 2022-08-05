#include "outpatient.h"
outpatient::outpatient(){anum=0;}
outpatient::outpatient(QString n,int nu,int wn,QDate d,int c,QString ad,QString t)
{
name=n;
number=nu;
worknumber=wn;
    date=d;
cap=c;
address=ad;
tel=t;
anum=0;
}
void outpatient::addappointment(appointment &a){

    aarray.push_back(a);
    anum++;


}
int outpatient::getappointmentnum(){anum=aarray.size();return anum;}
appointment &outpatient::getappointment(int index){return aarray[index];}
void outpatient::Saveoutpatient(QTextStream &aStream){
    aStream<<anum<<'\n';
    aStream << date.year()<<" "<<date.month()<<" "<<date.day()<<'\n';
    aStream << name<<'\n';
    aStream << worknumber<<'\n';
    aStream <<number<<'\n';
    aStream << cap<<'\n';
    aStream << address<<'\n';
    aStream<<tel<<'\n';

  for(int i=0;i<anum;i++){aarray[i].Saveappointment(aStream);}




}
void outpatient::Readoutpatient(QTextStream &aStream){

    int year, month, day;
    aStream>>anum;
    aStream>>year>>month>>day;
    date.setDate(year, month, day);
    aStream >> name;
    aStream >> worknumber;
    aStream >>number;
    aStream >>cap;
    aStream >>address;
    aStream>>tel;
 aarray.resize(anum);
    for(int i=0;i<anum;i++){aarray[i].Readappointment(aStream);}
}
outpatient &outpatient::operator=(const outpatient&pa){
    name=pa.name;
    number=pa.number;
    worknumber=pa.worknumber;
    date=pa.date;
    cap=pa.cap;
    address=pa.address;
    tel=pa.tel;

    return *this;

}


outpatient::~outpatient(){}



