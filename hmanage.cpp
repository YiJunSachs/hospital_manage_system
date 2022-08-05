#include "hmanage.h"
#include<QTextStream>
#include<qfile.h>
#include<QTextCodec>
hmanage::hmanage()
{
onum=0;
}
void hmanage::addoutpatient(outpatient &o){


 oarray.push_back(o);
  onum++;

}

int hmanage::getoutpatientnum(){

    onum=oarray.size();
    return onum;


}
outpatient &hmanage::getoutpatient(int index){return oarray[index];}
bool hmanage::SaveoutpatientToFile(const QString &aSaveFileName){

    QFile aFile(aSaveFileName);
    if(!aFile.open(QIODevice::WriteOnly| QIODevice::Text)) //保存为文本
        return false;
    QTextStream aStream(&aFile);//用文本流保存文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字


    aStream<<onum<<'\n';
    if(onum>0)
    {
        for(int i=0; i<onum; i++)
           oarray[i].Saveoutpatient(aStream);
    }
    aFile.close(); //关闭文件
    return true;


}
bool hmanage::ReadoutpatientFromFile(const QString &aReadFileName){QFile aFile(aReadFileName);
                                                                   if(!aFile.exists()) //文件不存在
                                                                       return false;
                                                                   if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本方式打开
                                                                       return false;
                                                                   QTextStream aStream(&aFile); //用文本流读取文件
                                                                   aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

                                                                   //初始化
                                                                   oarray.clear();
                                                                  onum = 0;


                                                                   aStream>>onum;
                                                                  outpatient tempoutpatient;
                                                                   if(onum>0)
                                                                   {
                                                                       for(int i=0; i<onum; i++)
                                                                       {
                                                                           tempoutpatient.Readoutpatient(aStream);
                                                                           oarray.push_back(tempoutpatient);
                                                                       }
                                                                   }
                                                                   aFile.close();//关闭文件
                                                                   return true;}

