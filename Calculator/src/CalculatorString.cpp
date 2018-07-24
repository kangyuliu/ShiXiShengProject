#include"CalculatorString.h"
#include<iostream>
#include<cmath>
using namespace std;
#define DBL_MAX         1.7976931348623158e+308


bool CalculatorString::IsData(char ch)      //判断输入计算的数字是否为0-9
{
    return ((ch>='0'&&ch<='9')||ch=='.')?true:false;
}
bool CalculatorString::IsSym(char ch)      //判断是否输入非法运算符
{
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/')?true:false;
}
int CalculatorString::IsPar(char ch)
{
    if(ch=='(')
        return 1;
    if(ch==')')
        return -1;
    return 0;
}
bool CalculatorString::Check(char *ch)
{
    int a=0;
    for(int i=0;i<strlen(ch);i++)
        if(ch[i]=='.')
            a++;
    if(a>1)
        return false;
    return true;
}
int CalculatorString::setPri(char ch)          //符号的优先极别
{
    switch(ch)
    {
    case '+':
        return 0;
    case '-':
        return 0;
    case '*':
        return 1;
    case '/':
        return 1;             
    default:
        return -1;
    }
}         
double CalculatorString::ToData(char* ch)   //将数字转化为数值
{
    int i,j,sumn=0;
    double sum=0.0;
    if(!Check(ch)) return 0.0;
    for(i=0;i<strlen(ch);i++)             //读入整数部分
    {
        if(ch[i]!='.')
            sumn=sumn*10+(ch[i]-'0');
        else break;
    }
    if(i<strlen(ch))
        for(j=i+1;j<strlen(ch);j++)        //小数部分
            sum=sum*10+(ch[j]-'0');
    sum /= pow(10.0,(double)(strlen(ch)-1-i));
    return (sum+sumn);                      //返回值
}
double CalculatorString::Call(double sum,double data,char ch)
{
    double ans=0.0;
    switch(ch)
    {
    case '+':
        ans=sum+data;        
        break;
    case '-':
        ans=sum-data;
        break;
    case '*':
        ans=sum*data;
        break;
    case '/':
        if( data != 0.0 )
            ans=sum/data;
        else
        {
            return DBL_MAX;
            /*cout<<"程序出现除0错误，终止！\n";
            system("pause");
            exit(1);*/
        }
        break;              
    default:ans=0.0;
        break;    
    }
    return ans;
}
int CalculatorString::GetMatch(char* buffer,int pos)     //利用栈找到匹配的括号
{
    STACK<char> Temp;
    int i;
    for(i=pos;i<strlen(buffer);i++)
    {
        if(IsPar(buffer[i])==1)
            Temp.push('0');
        if(IsPar(buffer[i])==-1)
        {
            Temp.pop();
            if(Temp.size()==0) return i;
        }
    }
    return -1;
}
void CalculatorString::Opr(STACK<char>& symbol,STACK<double>& data,int& mark)
{
    double sum;
    while(symbol.size()!=0)
    {
        char tem=symbol.pop();
        int temp=setPri(tem);
        symbol.push(tem);
        if(temp<mark)
            break;
        else{
            sum=Call(data.pop(),data.pop(),symbol.pop());
            data.push(sum);
        }
    }
}
double CalculatorString::Calculate(char* buffer,double& sum)   //字符串读入和各个函数调配
{
    STACK<double> data;
    STACK<char> symbol;
    double ans;
    char temp[MAX];
    int ct=0,mark=0,tp=0;
    data.push(sum);
    while(ct<=strlen(buffer))
    {
        if(IsData(buffer[ct]))            //如果是数字或小数点
        {
            while( ct < strlen(buffer) && IsData(buffer[ct]) )
                temp[tp++]=buffer[ct++];
            temp[tp]='\0';
            tp=0;                         //读到非数字也非小数为止
            ans=ToData(temp);             //把读到的字符串转化为数
            data.push(ans);     

            if(ct==strlen(buffer))        //已经独到字符串末尾
            {
                mark=0;
                Opr(symbol,data,mark);    //计算
                sum=data.pop();           //此时data栈中还剩一个数据，即是结果
                return sum;               //返回结果
            }
            else{
                int mark=setPri(buffer[ct]);
                Opr(symbol,data,mark);     //计算
            }
        }
        else if(IsSym(buffer[ct]))         //如果是运算符
            symbol.push(buffer[ct++]);     //运算符入symbol栈
        else
        {
            char BF[100];int k=0;          //如果都不是，则只能是括号
            while( IsPar( buffer[ct] ) != 1 && ct <= strlen(buffer) )
                BF[k++] = buffer[ct++];
            BF[k]='\0';     
            if(IsPar(buffer[ct])==1)       //一旦读到左括号，寻找它匹配的右括号
            {
                int i,j;
                char Temp[100];
                for(i=ct+1,j=0;i<GetMatch(buffer,ct);i++,j++)
                    Temp[j]=buffer[i];     //把这对括号中的字符串存入Temp
                Temp[j]='\0';
                data.push(Calculate(Temp,sum)); //递归调用Calculate直到没有括号
                //然后开始计算，值层层返回最后将最终结果放入data栈
                ct+=(strlen(Temp)+1);       //跳过已经处理完的字符
                if(ct+1==strlen(buffer))    //这里考虑字符串以括号结尾的情况
                {
                    mark=0;
                    Opr(symbol,data,mark);
                    sum=data.pop();
                    return sum;
                }
                else
                {
                    mark=setPri(buffer[ct+1]); //不是的话继续计算
                    Opr(symbol,data,mark);
                }
                ct++;                           //读入下一个字符
            }
        }
    }
    return 0.;
}