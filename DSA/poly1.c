#include<stdio.h>
#include<stdlib.h>
struct polynomial
{
    int cf;
    int px;
};
typedef struct polynomial p;
void accept(p p1[10],int n)
{
    int i;
   printf("enter the coefficient and exponent\n");
   for(i=0;i<n;i++)
   {
    scanf("%d%d",&p1[i].cf,&p1[i].px);
   }
}
void display(p p1[10],int n)
{
     int i;
    printf("polynomial with cf and px\n");
    for(i=0;i<n;i++)
    {
        if(p1[i].cf>0)
        printf("+%dX^%d",p1[i].cf,p1[i].px);
        else
        printf("%dX^%d",p1[i].cf,p1[i].px);
    }
    printf("\n");
}
int check_p_exist(p term,p p2[20],int m)
{
    int j;
    for(j=0;j<m;j++)
    {
        if(term.px==p2[j].px)
        {
            return j;
        }
    }
    return -1;
}
int add(p p1[20],int n1,p p2[20],int n2,p res[20])
{
     int k=0,i,index,j;
     for(i=0;i<n1;i++)
     {
        index=check_p_exist(p1[i],p2,n2);
        if(index!=-1)
        {
              res[k].cf=p1[i].cf+p2[index].cf;
              res[k].px=p1[i].px;
              p2[index].cf=-999;
        }
        else
        {
           res[k].cf=p1[i].cf;
            res[k].px=p1[i].px;
            
        }
        k++;
     }
     for(j=0;j<n2;j++)
     {
        if(p2[j].cf!=-999)
        {
            res[k].cf=p2[j].cf;
            res[k].px=p2[j].px;
            k++;
        }
         
     }
     return k;   
}
int main()
{
    p p1[20],p2[20],res[20];
    int k,n1,n2;
    printf("enter the n1 and n2\n");
    scanf("%d%d",&n1,&n2);
    accept(p1,n1);
    accept(p2,n2);
    display(p1,n1);
    display(p2,n2);
    k=add(p1,n1,p2,n2,res);
    display(res,k);
}