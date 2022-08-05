#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qdir.h"
#include"qfiledialog.h"
#include"dialog2.h"
#include"dialog3.h"
#include"appointment.h"
#include"hmanage.h"
#include"outpatient.h"
#include<QStandardItem>
#include<qvariant.h>
#include<QMessageBox>
#include<QAbstractItemDelegate>
#include<QModelIndex>
#include"readonly.h"
#include"dialog4.h"
#include"dialog5.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ShowInfotableView->setSelectionMode(QAbstractItemView::SingleSelection); //单次选择
    ui->ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectItems); //选中一个item

    outpatientInforModel = new QStandardItemModel();

    //建立关联
    ui->ShowInfotableView->setModel(outpatientInforModel);





}


void MainWindow::ShowoutpatientTable(){





    outpatientInforModel->clear();
    outpatientInforModel->setColumnCount(7);


    QStringList templist;
    templist.append("门诊名称");
    templist.append("门诊号");
    templist.append("医生工号");
    templist.append("接诊时间");
    templist.append("容量");
    templist.append("地址");
    templist.append("联系电话");

    outpatientInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.getoutpatientnum(); //行数（不含标题）
    outpatientInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    for(int i=0; i<RowCnt; ++i)
    {
       outpatient tempoutpatient=m_InfoTable.getoutpatient(i);

       aTempItem = new QStandardItem(tempoutpatient.name);
       outpatientInforModel->setItem(i, 0, aTempItem);
      tempStr=QString::number(tempoutpatient.number);
      aTempItem=new QStandardItem(tempStr);
      outpatientInforModel->setItem(i,1,aTempItem);
      tempStr=QString::number(tempoutpatient.worknumber);
      aTempItem=new QStandardItem(tempStr);
       outpatientInforModel->setItem(i,2,aTempItem);
       tempStr=tempoutpatient.date.toString("yyyy-MM-dd");
       aTempItem=new QStandardItem(tempStr);
       outpatientInforModel->setItem(i,3,aTempItem);
       tempStr=QString::number(tempoutpatient.cap);
       aTempItem=new QStandardItem(tempStr);
       outpatientInforModel->setItem(i,4,aTempItem);
       aTempItem=new QStandardItem(tempoutpatient.address);
       outpatientInforModel->setItem(i,5,aTempItem);
       aTempItem=new QStandardItem(tempoutpatient.tel);
       outpatientInforModel->setItem(i,6,aTempItem);




    }
    //设置号码为只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
}



void  MainWindow::ShowappointmentTable(){
                                         outpatientInforModel->clear();
                                         outpatientInforModel->setColumnCount(5);
                                         QStringList templist;
                                         templist.append("预约人姓名");
                                         templist.append("电话");
                                         templist.append("性别");
                                         templist.append("年龄");
                                         templist.append("预约时间");
                                         templist.append("预约医生工号");
                                         outpatientInforModel->setHorizontalHeaderLabels(templist);
                                         int RowCnt = m_InfoTable.getoutpatientnum();

                                                 QStandardItem *aTempItem; //临时的item
                                                 QString tempStr;
                                         for(int i=0;i<RowCnt;i++){
                                             int j=m_InfoTable.oarray[i].getappointmentnum();
                                             outpatientInforModel->setRowCount(j);
                                             for(int z=0;z<j;z++){
                                                 appointment tempapp=m_InfoTable.oarray[i].getappointment(z);

                                                 aTempItem = new QStandardItem(tempapp.pname);
                                                 outpatientInforModel->setItem(i, 0, aTempItem);
                                                aTempItem=new QStandardItem(tempapp.ptel);
                                                outpatientInforModel->setItem(i,1,aTempItem);
                                             aTempItem=new QStandardItem(tempapp.sex);
                                                 outpatientInforModel->setItem(i,2,aTempItem);

                                                 tempStr=QString::number(tempapp.age);
                                                 aTempItem=new QStandardItem(tempStr);
                                                 outpatientInforModel->setItem(i,3,aTempItem);
                                                 tempStr=tempapp.pdate.toString("yyyy-MM-dd");
                                                 aTempItem=new QStandardItem(tempStr);
                                                 outpatientInforModel->setItem(i,4,aTempItem);
                                                 tempStr=QString::number(tempapp.oworknumber);
                                                 aTempItem=new QStandardItem(tempStr);
                                                 outpatientInforModel->setItem(i,5,aTempItem);



                                             }}}

void MainWindow::on_actionaddoutpatient_triggered()
{
    Dialog2 dlgSignup(this);
    int ret = dlgSignup.exec(); //以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        outpatient tempoutpatient;
       tempoutpatient.name=dlgSignup.Name();
       tempoutpatient.number=dlgSignup.Number();
       tempoutpatient.worknumber=dlgSignup.worknumber();
       tempoutpatient.tel=dlgSignup.tel();
       tempoutpatient.address=dlgSignup.address();
       tempoutpatient.cap=dlgSignup.cap();
       tempoutpatient.date=dlgSignup.outpatientDate();
       m_InfoTable.addoutpatient(tempoutpatient);
       ShowoutpatientTable();
    }
}


void MainWindow::on_actionshowout_triggered()
{ShowoutpatientTable();

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    //父类的保持
    QMainWindow::resizeEvent(event);

    int x = this->frameGeometry().width();
    int y = this->frameGeometry().height();

    //窗口改变大小的时候列表控件跟着改变
    ui->ShowInfotableView->setGeometry(5,5,x*0.99,y*0.99);
}
void MainWindow::on_actionshowapp_triggered()
{
    ShowappointmentTable();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete outpatientInforModel;
}








void MainWindow::on_actionopen_2_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    if(aFileName.isEmpty())
        return;

    //创建成功，打开文件
    m_InfoTable.ReadoutpatientFromFile(aFileName);
    ShowoutpatientTable();
    ShowappointmentTable();
}

void MainWindow::on_actionsave_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "另存为一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if(aFileName.isEmpty())
        return;

    m_InfoTable.SaveoutpatientToFile(aFileName);

}

void MainWindow::on_actionaddappoint_triggered()
{int RowCnt = m_InfoTable.getoutpatientnum();
    Dialog3 dlgSignup(this);
    int ret = dlgSignup.exec();
    int a=0;//以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        appointment app;
        outpatient out;
        app.pname=dlgSignup.appointname();
        app.ptel=dlgSignup.appointtel();
        app.sex=dlgSignup.appointsex();
        app.age=dlgSignup.appointage();
        app.pdate=dlgSignup.appointdate();
        app.oworknumber=dlgSignup.oworknumber();

       for(int i=0;i<RowCnt;i++)if((app.oworknumber==m_InfoTable.oarray[i].worknumber)&&(app.pdate==m_InfoTable.oarray[i].date)&&(m_InfoTable.oarray[i].getappointmentnum()<m_InfoTable.oarray[i].cap))
                                   {m_InfoTable.oarray[i].addappointment(app);a=1;}

       if(a==0){QMessageBox box(QMessageBox::NoIcon,"提示","不可以添加预约信息");

           box.exec();
           return;} ShowappointmentTable();
    }
}

void MainWindow::on_actionsearch_triggered()
{int RowCnt = m_InfoTable.getoutpatientnum();
Dialog4 dlgSignup(this);
int ret = dlgSignup.exec(); //以模态方式显示对话框
if(ret==QDialog::Accepted){
outpatient out;
int a=0;
out.number=dlgSignup.snumber();
 for(int i=0;i<RowCnt;i++){
     if(out.number==m_InfoTable.oarray[i].number){
         outpatientInforModel->clear();
         outpatientInforModel->setColumnCount(7);


         QStringList templist;
         templist.append("门诊名称");
         templist.append("门诊号");
         templist.append("医生工号");
         templist.append("接诊时间");
         templist.append("容量");
         templist.append("地址");
         templist.append("联系电话");

         outpatientInforModel->setHorizontalHeaderLabels(templist);

         int RowCnt = m_InfoTable.getoutpatientnum(); //行数（不含标题）
         outpatientInforModel->setRowCount(RowCnt);

         //遍历，插入数据
         QStandardItem *aTempItem; //临时的item
         QString tempStr;
         outpatient tempoutpatient=m_InfoTable.getoutpatient(i);

         aTempItem = new QStandardItem(tempoutpatient.name);
         outpatientInforModel->setItem(i, 0, aTempItem);
        tempStr=QString::number(tempoutpatient.number);
        aTempItem=new QStandardItem(tempStr);
        outpatientInforModel->setItem(i,1,aTempItem);
        tempStr=QString::number(tempoutpatient.worknumber);
        aTempItem=new QStandardItem(tempStr);
         outpatientInforModel->setItem(i,2,aTempItem);
         tempStr=tempoutpatient.date.toString("yyyy-MM-dd");
         aTempItem=new QStandardItem(tempStr);
         outpatientInforModel->setItem(i,3,aTempItem);
         tempStr=QString::number(tempoutpatient.cap);
         aTempItem=new QStandardItem(tempStr);
         outpatientInforModel->setItem(i,4,aTempItem);
         aTempItem=new QStandardItem(tempoutpatient.address);
         outpatientInforModel->setItem(i,5,aTempItem);
         aTempItem=new QStandardItem(tempoutpatient.tel);
         outpatientInforModel->setItem(i,6,aTempItem);



a=1;

     }



 }

if(a==0){QMessageBox box(QMessageBox::NoIcon,"提示","查无此人");
    box.exec();
    return;}


}
}

void MainWindow::on_actiontelsearch_triggered()
{int RowCnt = m_InfoTable.getoutpatientnum();
    Dialog5 dlgSignup(this);

    int ret = dlgSignup.exec(); //以模态方式显示对话框
    if(ret==QDialog::Accepted){
    outpatient out;
    out.tel=dlgSignup.stel();
    int a=0;
     for(int i=0;i<RowCnt;i++){
         if(out.tel==m_InfoTable.oarray[i].tel){
             outpatientInforModel->clear();
             outpatientInforModel->setColumnCount(7);


             QStringList templist;
             templist.append("门诊名称");
             templist.append("门诊号");
             templist.append("医生工号");
             templist.append("接诊时间");
             templist.append("容量");
             templist.append("地址");
             templist.append("联系电话");

             outpatientInforModel->setHorizontalHeaderLabels(templist);

             int RowCnt = m_InfoTable.getoutpatientnum(); //行数（不含标题）
             outpatientInforModel->setRowCount(RowCnt);

             //遍历，插入数据
             QStandardItem *aTempItem; //临时的item
             QString tempStr;
             outpatient tempoutpatient=m_InfoTable.getoutpatient(i);

             aTempItem = new QStandardItem(tempoutpatient.name);
             outpatientInforModel->setItem(i, 0, aTempItem);
            tempStr=QString::number(tempoutpatient.number);
            aTempItem=new QStandardItem(tempStr);
            outpatientInforModel->setItem(i,1,aTempItem);
            tempStr=QString::number(tempoutpatient.worknumber);
            aTempItem=new QStandardItem(tempStr);
             outpatientInforModel->setItem(i,2,aTempItem);
             tempStr=tempoutpatient.date.toString("yyyy-MM-dd");
             aTempItem=new QStandardItem(tempStr);
             outpatientInforModel->setItem(i,3,aTempItem);
             tempStr=QString::number(tempoutpatient.cap);
             aTempItem=new QStandardItem(tempStr);
             outpatientInforModel->setItem(i,4,aTempItem);
             aTempItem=new QStandardItem(tempoutpatient.address);
             outpatientInforModel->setItem(i,5,aTempItem);
             aTempItem=new QStandardItem(tempoutpatient.tel);
             outpatientInforModel->setItem(i,6,aTempItem);
             a=1;





         }



     }

if(a==0){QMessageBox box(QMessageBox::NoIcon,"提示","查无此人");
    box.exec();
    return;}


    }
}
