#ifndef HMANAGE_H
#define HMANAGE_H
#include"appointment.h"
#include"outpatient.h"
#include<iostream>
using namespace std;
class hmanage
{
public:
    hmanage();
   QVector<outpatient>oarray;
   int onum;

    void addoutpatient(outpatient &o);
   int getoutpatientnum();
   outpatient &getoutpatient(int index);
   outpatient &searchname(outpatient &o);
   outpatient &searchtel(outpatient &o);
   bool ReadoutpatientFromFile(const QString &aReadFileName);
   bool SaveoutpatientToFile(const QString &aSaveFileName);

};

#endif // HMANAGE_H
