#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max 30
int compute(int op1,int op2,char op)
{
    switch(op)
    {
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '$':
        case '^':return pow(op1,op2);
    }
}
void push(int s[max],int *top,int symbol)
{
    (*top)++;
    s[*top]=symbol;
}
int pop(int s[max],int *top)
{
    int symbol;
    symbol=s[*top];
    (*top)--;
    return symbol;
}
int main()
{
     int s[max],top=-1,i,op1,op2,res; 
     char postfix[100],symbol;
     printf("enter expression");
     scanf("%s",postfix);
     for(i=0;postfix[i]!='\0';i++)
     {
          symbol=postfix[i];
        if(isdigit(symbol))
        {
            push(s,&top,symbol-'0');
        }
        else
        {
            op2=pop(s,&top);
            op1=pop(s,&top);
            res=compute(op1,op2,symbol);
            push(s,&top,res);
        }
     }
     printf("result=%d",pop(s,&top));
}