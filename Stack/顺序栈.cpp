#include <stdlib.h>
#include <stdio.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top; //栈顶
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1; //初始化栈顶指针
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(SqStack &S, ElemType x)
{
    if(S.top == MaxSize)
    {
        return false;
    }
    S.data[++S.top] = x;
    //相当于
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if(S.top == -1)
    {
        return false;
    }
    x = S.data[S.top--]; //出栈，指针-1
    return true;
}

bool GetTop(SqStack S, ElemType &x)
{
    if(S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    bool flag;
    ElemType m;
    InitStack(S);
    flag = StackEmpty(S);
    if(flag)
    {
        printf("栈为空\n");
    }
    Push(S,3);
    Push(S,4);
    Push(S,5);
    flag = GetTop(S,m);
    if(flag)
    {
        printf("栈顶元素为：%d\n",m);
    }
    flag = Pop(S,m);
    if(flag)
    {
        printf("弹出的栈中元素为：%d\n",m);
    }
    return 0;
}


