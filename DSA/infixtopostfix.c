#include<stdio.h>
#include<string.h>
#define max 3
int f(char sy)
{
    switch(sy)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '$':
        case '^':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8;

    }
}
int g(char sy)
{
    switch(sy)
    {
         case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '$':
        case '^':return 6;
        case '(':return 9;
        case ')':return 0;
        default:return 7;

    }
}
void push(char s[max],int *top,char sy)
{
    (*top)++;
    s[*top]=sy;
}
char pop(char s[max],int *top)
{
    char sy;
    sy=s[*top];
    (*top)--;
    return sy;
}
void c_in_postfix(char infix[100])
{
      char s[max],postfix[100],sy;
      int j=0,i,top=-1;
      push(s,&top,'#');
      for(i=0;infix[i]!='\0';i++)
      {
              sy=infix[i];
              while(f(s[top])>g(sy))
              {
                postfix[j]=pop(s,&top);
                    j++;
              }
              if(f(s[top])!=g(sy))
                push(s,&top,sy);
            else
                top--;
      }
    while(s[top]!='#')
    {
        postfix[j]=pop(s,&top);
          j++;
    }
   postfix[j]='\0';
   printf("%s",postfix);
}
int main()
{
   char infix[100];
   printf("enter the expression\n");
   scanf("%s",infix);
   c_in_postfix(infix);
}