#include<stdio.h>
#include<stdlib.h>
#define max 3
void push(int s[max],int *top)
{
    int ele;
    printf("enter the element\n");
    scanf("%d",&ele);
    if(*top==max-1)
    {
        printf("overflow");
        return;
    }
    (*top)++;
    s[*top]=ele;
}
void pop(int s[max],int *top)
{
    int ele;
    if(*top==-1)
    {
        printf("underflow");
        return;
    }
    ele=s[*top];
    (*top)--;
    printf("display %d",ele);
}
void pali(int s[max],int *top)
{
    int num[5],rev[5],i,t;
    for(i=0,t=*top;t>=0;i++,t--)
    num[i]=rev[t]=s[t];
    for(i=0;i<=*top;i++)
     if(num[i]!=rev[i])
     break;
     if(i==(*top)+1)
       printf("\npalindrome");
    else
       printf("\n not a palindrome");
}
void display(int s[max],int top)
{
    int ele,i;
    if(top==-1)
    {
        printf("underflow");
        return;
    }
    printf("display elements\n");
    for(i=0;i<=top;i++)
    {
        printf("%d\n",s[i]);

    }
}
void status(int s[max],int top)
{
    int used;
    if(top==-1)
      used=0;
    else
    used=top+1;
    printf("%dloc used up\n",used);
    printf("%dloaction free\n",max-used);
}
int main()
{
     int s[max],ch,top=-1;
     while(1)
     {
        printf("\nenter choice1.push\n2.pop\n3.palindrome\n4.display\n5.status\n6.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(s,&top);
              break;
            case 2:pop(s,&top);
               break;
            case 3:pali(s,&top);
               break;
            case 4:display(s,top);
               break;
            case 5:status(s,top);
               break;
            default:exit(0);
               break;
        }

     }
}