#include"CalculatorString.h"
#include<iostream>
#include<cmath>
using namespace std;
#define DBL_MAX         1.7976931348623158e+308


bool CalculatorString::IsData(char ch)      //�ж��������������Ƿ�Ϊ0-9
{
    return ((ch>='0'&&ch<='9')||ch=='.')?true:false;
}
bool CalculatorString::IsSym(char ch)      //�ж��Ƿ�����Ƿ������
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
int CalculatorString::setPri(char ch)          //���ŵ����ȼ���
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
double CalculatorString::ToData(char* ch)   //������ת��Ϊ��ֵ
{
    int i,j,sumn=0;
    double sum=0.0;
    if(!Check(ch)) return 0.0;
    for(i=0;i<strlen(ch);i++)             //������������
    {
        if(ch[i]!='.')
            sumn=sumn*10+(ch[i]-'0');
        else break;
    }
    if(i<strlen(ch))
        for(j=i+1;j<strlen(ch);j++)        //С������
            sum=sum*10+(ch[j]-'0');
    sum /= pow(10.0,(double)(strlen(ch)-1-i));
    return (sum+sumn);                      //����ֵ
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
            /*cout<<"������ֳ�0������ֹ��\n";
            system("pause");
            exit(1);*/
        }
        break;              
    default:ans=0.0;
        break;    
    }
    return ans;
}
int CalculatorString::GetMatch(char* buffer,int pos)     //����ջ�ҵ�ƥ�������
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
double CalculatorString::Calculate(char* buffer,double& sum)   //�ַ�������͸�����������
{
    STACK<double> data;
    STACK<char> symbol;
    double ans;
    char temp[MAX];
    int ct=0,mark=0,tp=0;
    data.push(sum);
    while(ct<=strlen(buffer))
    {
        if(IsData(buffer[ct]))            //��������ֻ�С����
        {
            while( ct < strlen(buffer) && IsData(buffer[ct]) )
                temp[tp++]=buffer[ct++];
            temp[tp]='\0';
            tp=0;                         //����������Ҳ��С��Ϊֹ
            ans=ToData(temp);             //�Ѷ������ַ���ת��Ϊ��
            data.push(ans);     

            if(ct==strlen(buffer))        //�Ѿ������ַ���ĩβ
            {
                mark=0;
                Opr(symbol,data,mark);    //����
                sum=data.pop();           //��ʱdataջ�л�ʣһ�����ݣ����ǽ��
                return sum;               //���ؽ��
            }
            else{
                int mark=setPri(buffer[ct]);
                Opr(symbol,data,mark);     //����
            }
        }
        else if(IsSym(buffer[ct]))         //����������
            symbol.push(buffer[ct++]);     //�������symbolջ
        else
        {
            char BF[100];int k=0;          //��������ǣ���ֻ��������
            while( IsPar( buffer[ct] ) != 1 && ct <= strlen(buffer) )
                BF[k++] = buffer[ct++];
            BF[k]='\0';     
            if(IsPar(buffer[ct])==1)       //һ�����������ţ�Ѱ����ƥ���������
            {
                int i,j;
                char Temp[100];
                for(i=ct+1,j=0;i<GetMatch(buffer,ct);i++,j++)
                    Temp[j]=buffer[i];     //����������е��ַ�������Temp
                Temp[j]='\0';
                data.push(Calculate(Temp,sum)); //�ݹ����Calculateֱ��û������
                //Ȼ��ʼ���㣬ֵ��㷵��������ս������dataջ
                ct+=(strlen(Temp)+1);       //�����Ѿ���������ַ�
                if(ct+1==strlen(buffer))    //���￼���ַ��������Ž�β�����
                {
                    mark=0;
                    Opr(symbol,data,mark);
                    sum=data.pop();
                    return sum;
                }
                else
                {
                    mark=setPri(buffer[ct+1]); //���ǵĻ���������
                    Opr(symbol,data,mark);
                }
                ct++;                           //������һ���ַ�
            }
        }
    }
    return 0.;
}