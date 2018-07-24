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
    int setPri(char);                 //判断符号的优先极别
    double ToData(char*);               //把字符串转化为数值
    double Call(double,double,char);    //具体按符号计算
    int GetMatch(char* buffer,int pos); //利用栈找到匹配的括号
    void Opr( STACK<char>&, STACK<double>&, int& ); //利用栈计算
    double Calculate(char*, double& );   //字符串的读入及调配

};

#endif
