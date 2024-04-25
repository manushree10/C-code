#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mx 3 
void c_i(char cq[mx],int *r,int *cnt)
{
    char ele;
    printf("enter ele");
    scanf("%s",&ele);
    if(*cnt==mx)
    {
        printf("overflow");
        return;
    }
    *r=((*r)+1)%mx;
     cq[*r]=ele;
     (*cnt)++;
}
void c_d(char cq[mx],int *f,int *cnt)
{
    char ele;
    if(*cnt==0)
    {
        printf("underflow");
        return;
    }
    *f=((*f)+1)%mx;
     ele=cq[*f];
     printf("display ele %c",ele);
     (*cnt)--;
}
void display(char cq[mx],int f,int cnt)
{
     int i;
    char ele;
    if(cnt==0)
    {
        printf("underflow");
        return;
    }
    printf("display elements\n");
    for(i=0;i<cnt;i++)
    {
        printf("%c\n",cq[f]);
        f=(f+1)%mx;
    }
}
void status(char cq[mx],int cnt)
{
    int used;
    if(cnt==0)
      used=0;
    else
    used=cnt;
    printf("%dloc used up\n",used);
    printf("%dloaction free\n",mx-used);
}
int main()
{
    char cq[mx];
    int r=-1,f=0,ch,cnt=0;
    while(1)
     {
        printf("\nenter choice1.insert\n2.delete\n3.display\n\n4.status\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:c_i(cq,&r,&cnt);
              break;
            case 2:c_d(cq,&f,&cnt);
               break;
            case 3:display(cq,f,cnt);
               break;
            case 4:status(cq,cnt);
               break;
            default:exit(0);
        }

     }
}
