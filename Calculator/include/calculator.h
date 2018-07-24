 #ifndef CALCULATOR_H
#define CALCULATOR_H
#include<QPushButton>
#include<QLabel>
#include <QtWidgets/QDialog>
#include<QHBoxLayout>
#include<QVBoxLayout>
class Calculator : public QDialog
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);
    ~Calculator();
private:
    void init(); //初始化
private:


    char m_char; //前一个输入字符
    QString m_text; //显示的字符串
    int m_LeftBracketNum; //记录左括号数
    bool m_pointStatus; //记录点的状态
    bool m_EqualStatus; //记录等于号性质

    QPushButton* m_pBtn0;
    QPushButton* m_pBtn1;
    QPushButton* m_pBtn2;
    QPushButton* m_pBtn3;
    QPushButton* m_pBtn4;
    QPushButton* m_pBtn5;
    QPushButton* m_pBtn6;
    QPushButton* m_pBtn7;
    QPushButton* m_pBtn8;
    QPushButton* m_pBtn9;
    QPushButton* m_pBtnAdd;
    QPushButton* m_pBtnMinus;
    QPushButton* m_pBtnMulti;
    QPushButton* m_pBtnDiv;
    QPushButton* m_pBtnC;
    QPushButton* m_pBtnEqual;
    QPushButton* m_pBtnPoint;
    QPushButton* m_pBtnLeftBracket;
    QPushButton* m_pBtnRightBracket;

    QLabel* m_pLabelResult;
 //   QLabel* m_pLabelInput;
    
    QHBoxLayout *m_pHBoxLayout1;
    QHBoxLayout *m_pHBoxLayout2;
    QHBoxLayout *m_pHBoxLayout3;
    QHBoxLayout *m_pHBoxLayout4;
    QHBoxLayout *m_pHBoxLayout5;

    QVBoxLayout *m_pVBoxLayout;

private slots:
    void btn0Clicked();
    void btnMinusClicked();
    void btnEqualClicked();
    void btnPointClicked();
    void btnCClicked();
    void btnLBracketClicked();
    void btnRBracketClicked();
    void dightClicked();
    void opClicked();
};

#endif // CALCULATOR_H
