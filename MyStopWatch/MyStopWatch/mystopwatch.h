#ifndef MYSTOPWATCH_H
#define MYSTOPWATCH_H

#include <QWidget>
#include<QTimer>
#include<QLineEdit>
#include<QPushButton>
#include<QLCDNumber>
#include"QTableWidget"
class MyStopWatch : public QWidget
{
    Q_OBJECT

public:
    explicit MyStopWatch(QWidget *parent = 0);
    ~MyStopWatch();

    

private:

    int hourTemp;           //Hour
    int minuteTemp;         //Minute
    int secondTemp;         //Second
    int countTemp;
    int hourTemp1;           //Hour
    int minuteTemp1;         //Minute
    int secondTemp1;         //Second
    int countTemp1;
    int timeCount;  //记录计次次数

    QPushButton* m_controlBtn;
    QPushButton* m_countBtn;
    QLCDNumber* m_time;
    QLCDNumber* m_time1;
    QTableWidget* m_table;

    QTimer *msTimer;   //定义一个定时器，记录总时间
    QTimer *msTimer1;   //定义一个定时器，记录单次时间

    void display(QLCDNumber*,QString,QString,QString,QString);
    void resetStopwatch();  //复位秒表

private slots:
    void timeSlot();
    void timeSlot1();
    void controlStopwatch();  //启动秒表
    void countStopwatch();   //秒表计次
    void init();
};

#endif // MYSTOPWATCH_H