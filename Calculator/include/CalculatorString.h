#ifndef CALCULATORSTRING_H
#define CALCULATORSTRING_H
#include"STACK.h"
class CalculatorString
{
public:
    bool IsData(char);
    bool IsSym(char);
    int IsPar(char);
    bool Check(char *);
    int setPri(char);                 //�жϷ��ŵ����ȼ���
    double ToData(char*);               //���ַ���ת��Ϊ��ֵ
    double Call(double,double,char);    //���尴���ż���
    int GetMatch(char* buffer,int pos); //����ջ�ҵ�ƥ�������
    void Opr( STACK<char>&, STACK<double>&, int& ); //����ջ����
    double Calculate(char*, double& );   //�ַ����Ķ��뼰����

};

#endif
