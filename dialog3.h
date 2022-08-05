#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include<QDate>
#include<QString>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();
    QString appointname();
    QString appointsex();
    QString appointtel();
    int appointage();
    QDate appointdate();
    int oworknumber();


private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
