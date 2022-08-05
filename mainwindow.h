#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"hmanage.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void ShowoutpatientTable();
     void  ShowappointmentTable();
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
private slots:






     void on_actionaddoutpatient_triggered();

     void on_actionshowout_triggered();

     void on_actionshowapp_triggered();



     void on_actionopen_2_triggered();

     void on_actionsave_triggered();

     void on_actionaddappoint_triggered();

     void on_actionsearch_triggered();

     void on_actiontelsearch_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel * outpatientInforModel;
    //显示表格信息数据模型
   hmanage m_InfoTable; //数据汇总类
    int m_iCurTable;
    QWidget qw();
};
#endif // MAINWINDOW_H
