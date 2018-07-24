#include "mystopwatch.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QHeaderView>
#include<QFont>
MyStopWatch::MyStopWatch(QWidget *parent) :
    QWidget(parent)

{
    init();

    //���ź���۽�������
    connect(msTimer,SIGNAL(timeout()),this,SLOT(timeSlot()));
    connect(msTimer1,SIGNAL(timeout()),this,SLOT(timeSlot1()));
    connect(m_controlBtn,SIGNAL(clicked()),this,SLOT(controlStopwatch()));
    connect(m_countBtn,SIGNAL(clicked()),this,SLOT(countStopwatch()));   
}

MyStopWatch::~MyStopWatch()
{

}

void MyStopWatch::timeSlot()
{
    countTemp+=1;
    if(countTemp==100)
    {
        countTemp=0;
        secondTemp++;
        if(secondTemp==60)
        {
            secondTemp=0;
            minuteTemp++;
            if(minuteTemp==60)
            {
                minuteTemp=0;
                hourTemp++;
                if(hourTemp==24)
                {
                    hourTemp=0;
                }
            }
        }
    }
    //������ת�����ַ���
    QString hourstr = QString::number(hourTemp);
    QString minutestr = QString::number(minuteTemp);
    QString secondstr = QString::number(secondTemp);
    QString msecondstr = QString::number(countTemp);
    display(m_time,hourstr,minutestr,secondstr,msecondstr);
}

void MyStopWatch::timeSlot1()
{
    countTemp1+=1;
    if(countTemp1==100)
    {
        countTemp1=0;
        secondTemp1++;
        if(secondTemp1==60)
        {
            secondTemp1=0;
            minuteTemp1++;
            if(minuteTemp1==60)
            {
                minuteTemp1=0;
                hourTemp1++;
                if(hourTemp1==24)
                {
                    hourTemp1=0;
                }
            }
        }
    }
    //������ת�����ַ���
    QString hourstr = QString::number(hourTemp1);
    QString minutestr = QString::number(minuteTemp1);
    QString secondstr = QString::number(secondTemp1);
    QString msecondstr = QString::number(countTemp1);
    display(m_time1,hourstr,minutestr,secondstr,msecondstr);
}


void MyStopWatch::display(QLCDNumber* time, QString hour, QString minute, QString second, QString msecond)
{
    time->display(hour+":"+minute+":"+second+":"+msecond);
}

void MyStopWatch::controlStopwatch()
{
    if((m_controlBtn->text()) == QStringLiteral("����"))
    {
        msTimer->start(10); //1ms
        msTimer1->start(10); //1ms
        m_controlBtn->setText(QStringLiteral("ֹͣ"));
        m_countBtn->setEnabled(true);
    }
    else
    {
        msTimer->stop();
        msTimer1->stop();
        m_controlBtn->setText(QStringLiteral("ֹͣ"));
        m_countBtn->setText(QStringLiteral("��λ"));
    }
}

void MyStopWatch::resetStopwatch()
{
    m_time->display("0:0:0:00");
    m_time1->display("0:0:0:00");
    countTemp=0;
    secondTemp=0;
    minuteTemp=0;
    hourTemp=0;
    countTemp1=0;
    secondTemp1=0;
    minuteTemp1=0;
    hourTemp1=0;
    m_table->setRowCount(0);
    timeCount = 0;

}


void MyStopWatch::countStopwatch()
{
    if(m_countBtn->isEnabled())
    {
        if((m_countBtn->text()) == QStringLiteral("��λ"))
        {
            resetStopwatch();
            m_countBtn->setText(QStringLiteral("�ƴ�"));
            m_countBtn->setEnabled(false);
            m_controlBtn->setText(QStringLiteral("����"));
        }
        else
        {

            timeCount++;
            m_table->insertRow(0);
            //��ӱ��
            QFont oFont;
            oFont.setPointSize(12);

            QTableWidgetItem* pTabWidgetItem = new QTableWidgetItem(QString::number(timeCount)); //�½�һ�������Ŀ
            pTabWidgetItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);        //��������䷽ʽ
            pTabWidgetItem->setFont(oFont);
            m_table->setItem(0,0,pTabWidgetItem);                         //���
            pTabWidgetItem = new QTableWidgetItem(QString::number(hourTemp1)+":"+QString::number(minuteTemp1)+":"+QString::number(secondTemp1)+":"+QString::number(countTemp1));
            pTabWidgetItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            pTabWidgetItem->setFont(oFont);
            m_table->setItem(0,1,pTabWidgetItem);
            countTemp1=0;
            secondTemp1=0;
            minuteTemp1=0;
            hourTemp1=0;
          //  m_pTime2->setHMS(0,0,0,0);
        }

    }
}

void MyStopWatch::init()
{
    //��ʼ����Ա����
    countTemp=0;
    secondTemp=0;
    minuteTemp=0;
    hourTemp=0;
    timeCount = 0;
    msTimer= new QTimer;  //this˵���ǵ�ǰ�����Ķ�ʱ��
    msTimer1= new QTimer;  //this˵���ǵ�ǰ�����Ķ�ʱ��
    countTemp1=0;
    secondTemp1=0;
    minuteTemp1=0;
    hourTemp1=0;

    //������ť
    m_controlBtn = new QPushButton(QStringLiteral("����"));
    m_countBtn = new QPushButton(QStringLiteral("�ƴ�"));
    m_countBtn->setEnabled(false);
    m_controlBtn->setStyleSheet("border:2px groove blue;border-radius:10px;padding:2px 4px;");
    m_countBtn->setStyleSheet("border:2px solid red;border-radius:10px;padding:2px 4px;");


    //������ʾ��
    m_time = new QLCDNumber;
    m_time->setDigitCount(11);
    m_time->setSegmentStyle(QLCDNumber::Flat);   
    m_time1 = new QLCDNumber;
    m_time1->setDigitCount(11);

    //���ñ���¼�ƴ�
    QFont oFont;
    oFont.setPointSize(30);
    oFont.setBold(true); 

    m_table = new QTableWidget;
    m_table->setColumnCount(2); //��������
    QStringList oHeader;
    oHeader << QStringLiteral("�ƴ�") << QStringLiteral("��ʱ")  ;     
    m_table->horizontalHeader()->setFixedHeight(30);                                               //���ñ�ͷ�ĸ߶�
    m_table->setHorizontalHeaderLabels(oHeader);                                               //���ñ�ͷ����
    oFont = m_table->horizontalHeader()->font();                                               //��ͷ��������
    oFont.setPointSize(15);                                                                   //�����С
    oFont.setBold(true);                                                                     //����Ӵ�
    m_table->horizontalHeader()->setFont(oFont);   
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);                               //������༭
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);                          //����ѡ��
    m_table->verticalHeader()->setVisible(false);                                          //�кŲ��ɼ�
    m_table->setColumnWidth(0,91);                                                         //����ÿһ���п�
    m_table->setColumnWidth(1,200);
    m_table->setColumnWidth(2,200);



    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_countBtn);
   // layout->addStretch(1);
    layout->addWidget(m_time1);
    layout->addWidget(m_controlBtn);


    QVBoxLayout* layout2 = new QVBoxLayout;
  //  layout2->addWidget(m_time1);
    layout2->addWidget(m_time);
    layout2->addLayout(layout);
    layout2->addWidget(m_table);
    setLayout(layout2);
}

