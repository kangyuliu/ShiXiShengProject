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
    int timeCount;  //��¼�ƴδ���

    QPushButton* m_controlBtn;
    QPushButton* m_countBtn;
    QLCDNumber* m_time;
    QLCDNumber* m_time1;
    QTableWidget* m_table;

    QTimer *msTimer;   //����һ����ʱ������¼��ʱ��
    QTimer *msTimer1;   //����һ����ʱ������¼����ʱ��

    void display(QLCDNumber*,QString,QString,QString,QString);
    void resetStopwatch();  //��λ���

private slots:
    void timeSlot();
    void timeSlot1();
    void controlStopwatch();  //�������
    void countStopwatch();   //���ƴ�
    void init();
};

#endif // MYSTOPWATCH_H