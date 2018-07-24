#ifndef STACK_H
#define STACK_H
const int MAX=1000;
template <class Type>       
class STACK{                 //定义栈类
private:
    Type base[MAX];
    int Size;
public:
    STACK(){Size=0;};
    void push(Type a)     //入栈
    {
        base[Size]=a;
        Size++;
    }
    Type pop()            //出栈
    {
        return base[--Size];
    }
    int size()
    {return Size;}
};


#endif