#include "calculator.h"
#include"CalculatorString.h"
#include<string>
#define DBL_MAX         1.7976931348623158e+308
Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{
    
    init();
    connect(m_pBtn0,SIGNAL(clicked()),this,SLOT(btn0Clicked()));
  //  connect(m_pBtn1,SIGNAL(clicked()),this,SLOT(btn1Clicked()));
    connect(m_pBtn1,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn2,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn3,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn4,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn5,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn6,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn7,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn8,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtn9,SIGNAL(clicked()),this,SLOT(dightClicked()));
    connect(m_pBtnAdd,SIGNAL(clicked()),this,SLOT(opClicked()));
    connect(m_pBtnMinus,SIGNAL(clicked()),this,SLOT(btnMinusClicked()));
    connect(m_pBtnMulti,SIGNAL(clicked()),this,SLOT(opClicked()));
    connect(m_pBtnDiv,SIGNAL(clicked()),this,SLOT(opClicked()));
    connect(m_pBtnEqual,SIGNAL(clicked()),this,SLOT(btnEqualClicked()));
    connect(m_pBtnPoint,SIGNAL(clicked()),this,SLOT(btnPointClicked()));
    connect(m_pBtnC,SIGNAL(clicked()),this,SLOT(btnCClicked()));
    connect(m_pBtnLeftBracket,SIGNAL(clicked()),this,SLOT(btnLBracketClicked()));
    connect(m_pBtnRightBracket,SIGNAL(clicked()),this,SLOT(btnRBracketClicked()));
    
}

Calculator::~Calculator()
{

}

void Calculator::init()
{
    setWindowTitle("lihd_counter");


    m_char = ' ';
    m_text = "";
    m_LeftBracketNum = 0;
    m_pointStatus = false;
    m_EqualStatus = false;

    m_pBtn0 = new QPushButton("0");
    m_pBtn1 = new QPushButton("1");
    m_pBtn2 = new QPushButton("2");
    m_pBtn3 = new QPushButton("3");
    m_pBtn4 = new QPushButton("4");
    m_pBtn5 = new QPushButton("5");
    m_pBtn6 = new QPushButton("6");
    m_pBtn7 = new QPushButton("7");
    m_pBtn8 = new QPushButton("8");
    m_pBtn9 = new QPushButton("9");
    m_pBtnAdd = new QPushButton("+");
    m_pBtnMinus = new QPushButton("-");
    m_pBtnMulti = new QPushButton("*");
    m_pBtnDiv = new QPushButton("/");
    m_pBtnC = new QPushButton("C");
    m_pBtnEqual = new QPushButton("=");
    m_pBtnPoint = new QPushButton(".");
    m_pLabelResult = new QLabel("");
 //   m_pLabelInput = new QLabel("input");
    m_pBtnRightBracket = new QPushButton(")");
    m_pBtnLeftBracket = new QPushButton("(");

    m_pBtn0->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn0->setMinimumHeight(80);
    m_pBtn1->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn1->setMinimumHeight(80);
    m_pBtn2->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn2->setMinimumHeight(80);
    m_pBtn3->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn3->setMinimumHeight(80);
    m_pBtn4->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn4->setMinimumHeight(80);
    m_pBtn5->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn5->setMinimumHeight(80);
    m_pBtn6->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn6->setMinimumHeight(80);
    m_pBtn7->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn7->setMinimumHeight(80);
    m_pBtn8->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn8->setMinimumHeight(80);
    m_pBtn9->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtn9->setMinimumHeight(80);

    m_pBtnAdd->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnAdd->setMinimumHeight(80);
    m_pBtnMinus->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnMinus->setMinimumHeight(80);
    m_pBtnMulti->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnMulti->setMinimumHeight(80);
    m_pBtnDiv->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnDiv->setMinimumHeight(80);
    m_pBtnC->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnC->setMinimumHeight(80);
    m_pBtnEqual->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnEqual->setMinimumHeight(80);
    m_pBtnPoint->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnPoint->setMinimumHeight(80);
    m_pBtnLeftBracket->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnLeftBracket->setMinimumHeight(80);
    m_pBtnRightBracket->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pBtnRightBracket->setMinimumHeight(80);
  //  m_pLabelResult->setStyleSheet("QPushButton{ font-family:'Times New Roman';font-size:38px;color:#666666;}");
    m_pLabelResult->setMinimumHeight(80);
 //   m_pLabelInput->setMinimumHeight(80);
    m_pLabelResult->setFrameShape(QFrame::Box);
    m_pLabelResult->setStyleSheet("border:2px solid red;");

    QFont ft;
    ft.setPointSize(20);
    m_pLabelResult->setFont(ft);
 //   m_pLabelInput->setFont(ft);

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    m_pLabelResult->setPalette(pa);
//    m_pLabelInput->setPalette(pa);

    m_pHBoxLayout1 = new QHBoxLayout;
    m_pHBoxLayout2 = new QHBoxLayout;
    m_pHBoxLayout3 = new QHBoxLayout;
    m_pHBoxLayout4 = new QHBoxLayout;
    m_pHBoxLayout5 = new QHBoxLayout;

    m_pVBoxLayout = new QVBoxLayout;

    
    m_pHBoxLayout1->addWidget(m_pBtnLeftBracket);
    m_pHBoxLayout1->addWidget(m_pBtnRightBracket);
    m_pHBoxLayout1->addWidget(m_pBtnC);


     
    m_pHBoxLayout2->addWidget(m_pBtn1);
    m_pHBoxLayout2->addWidget(m_pBtn2);
    m_pHBoxLayout2->addWidget(m_pBtn3);
    m_pHBoxLayout2->addWidget(m_pBtnAdd);

    m_pHBoxLayout3->addWidget(m_pBtn4);
    m_pHBoxLayout3->addWidget(m_pBtn5);
    m_pHBoxLayout3->addWidget(m_pBtn6);
    m_pHBoxLayout3->addWidget(m_pBtnMinus);

    m_pHBoxLayout4->addWidget(m_pBtn7);
    m_pHBoxLayout4->addWidget(m_pBtn8);
    m_pHBoxLayout4->addWidget(m_pBtn9);
    m_pHBoxLayout4->addWidget(m_pBtnMulti);

    m_pHBoxLayout5->addWidget(m_pBtnPoint);
    m_pHBoxLayout5->addWidget(m_pBtn0);
    m_pHBoxLayout5->addWidget(m_pBtnEqual);
    m_pHBoxLayout5->addWidget(m_pBtnDiv);

    
 //   m_pVBoxLayout->addWidget(m_pLabelInput);
    m_pVBoxLayout->addWidget(m_pLabelResult);
    m_pVBoxLayout->addLayout(m_pHBoxLayout2);
    m_pVBoxLayout->addLayout(m_pHBoxLayout3);
    m_pVBoxLayout->addLayout(m_pHBoxLayout4);
    m_pVBoxLayout->addLayout(m_pHBoxLayout5);
    m_pVBoxLayout->addLayout(m_pHBoxLayout1);

  //  m_pVBoxLayout->setFrameShape(QFrame::Box);
  //  m_pVBoxLayout->setStyleSheet("border:2px solid red;");
    setLayout(m_pVBoxLayout);
}

void Calculator::dightClicked()
{
    QPushButton* pBt = static_cast<QPushButton*>(sender());
    QString str = pBt->text();

    if(  m_char == ')')
        return;

    if(m_EqualStatus)
    {
        m_text = str;
    }
    else
    {
        if(m_text == "0")
        {
            m_text=str;
        }
        else
        {
            m_text+=str;
        }
    }

    QByteArray ba = str.toLatin1();    
    m_char = *(ba.data());

 //   m_char = '1';
    m_EqualStatus = false;
    m_pLabelResult->setText(m_text);
}
void Calculator::btn0Clicked()
{
    if(m_text == "0" || m_char == ')')
        return;

    if(m_EqualStatus)
    {
        m_text = "0";
        m_char = '0';
    }
    else
    {
        if((m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/') || m_char == '(')
        {
            m_text+="0.";
            m_char = '.';
            m_pointStatus = true;
        }
        else
        {
            m_text+="0";
            m_char = '0';
        }
    }
        
    m_EqualStatus = false;
    m_pLabelResult->setText(m_text);
}

void Calculator::opClicked()
{
    if((m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/') || (m_char == ' ') || m_char == '(' )
        return;

    if(m_pointStatus)
        m_pointStatus = false;

    QPushButton* pBt = static_cast<QPushButton*>(sender());
    QString str = pBt->text();

    if(m_char == '.')
        m_text.replace(m_text.size()-1,1,str);
    else
        m_text+=str;

    QByteArray ba = str.toLatin1();    
    m_char = *(ba.data());

//    m_char = '+';
    m_EqualStatus = false;
    m_pLabelResult->setText(m_text);
}

void Calculator::btnMinusClicked(){
   // if((m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/') || (m_char == ' ')  || m_char == '.')
    if((m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/') )
        return;

    if(m_pointStatus)
        m_pointStatus = false;

    if(m_char == '.')
        m_text.replace(m_text.size()-1,1,"-");
    else
        m_text+="-";

 //   m_text+="-";
    m_char = '-';
    m_EqualStatus = false;
    m_pLabelResult->setText(m_text);
}

void Calculator::btnEqualClicked(){
    if(m_char == '+' || m_char == '-' || m_char == '*' || m_char == '/' || m_char == '(')
        return;

    /*   if(m_char == '.')
    m_text -= ".";*/

    if(m_text == "")
        return;

    while( m_LeftBracketNum > 0)
    {
        m_text += ")";
        m_LeftBracketNum--;
    }

  
    double sum;
    char*  ch;
    QByteArray ba = m_text.toLatin1();    
    ch=ba.data();
 
    CalculatorString* pCString = new CalculatorString;
    pCString->Calculate(ch,sum);
    if(DBL_MAX == sum || DBL_MAX == (-sum))
    {
        m_pLabelResult->setText(QStringLiteral("³ýÊýÎªÁã£¬ÊäÈë´íÎó£¡"));
        m_text="";
        m_char = ' ';
     //   m_pLabelResult->setText("");
        m_LeftBracketNum = 0;
        m_pointStatus = false;
        m_EqualStatus = false;
        return;
    }
    else
        m_pLabelResult->setText(QString::number(sum));

    m_text = QString::number(sum);
    m_EqualStatus = true;
    m_pointStatus = false;
}
void Calculator::btnCClicked()
{
    m_text="";
    m_char = ' ';
    m_pLabelResult->setText("");
    m_LeftBracketNum = 0;
    m_pointStatus = false;
    m_EqualStatus = false;
}

void Calculator::btnPointClicked()
{
    if(m_char == ')' || m_char == '(' || m_char == '.' )
        return;

    if(m_pointStatus)
        return;


    if(m_EqualStatus )
    {
        m_text="0.";
    }
        
    else 
    {
        if(m_text == "" ||  (m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/'))
        {
             m_text+="0.";

        }
        else
        {
            m_text+=".";
        }
    }

    
    m_char = '.';
    m_pointStatus = true;
    m_pLabelResult->setText(m_text);
    m_EqualStatus = false;
}

void Calculator::btnLBracketClicked()

{
    if(((m_char >= '0')&&(m_char <= '9')) || (m_char == '.') || (m_char == ')'))
        return;

    m_text+="(";
    m_char = '(';
    m_LeftBracketNum += 1;
    m_pLabelResult->setText(m_text);
}
void Calculator::btnRBracketClicked()
{
    if((m_char == '+') || (m_char == '-') || (m_char == '*') || (m_char == '/') || (m_char == ' ') || (m_char == '.')|| (m_char == '('))
        return;
    if(m_LeftBracketNum <= 0)
        return;

    m_text+=")";
    m_char = ')';
    m_LeftBracketNum -= 1;
    m_pLabelResult->setText(m_text);
}


