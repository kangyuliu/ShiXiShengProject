#ifndef STACK_H
#define STACK_H
const int MAX=1000;
template <class Type>       
class STACK{                 //����ջ��
private:
    Type base[MAX];
    int Size;
public:
    STACK(){Size=0;};
    void push(Type a)     //��ջ
    {
        base[Size]=a;
        Size++;
    }
    Type pop()            //��ջ
    {
        return base[--Size];
    }
    int size()
    {return Size;}
};


#endif