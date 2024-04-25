#include<stdio.h>
void t_h(int n,char s,char t,char d)
{
    if(n==0)
    return;
    t_h(n-1,s,d,t);
    printf("move %d disk from %c to %c\n",n,s,d);
    t_h(n-1,t,s,d);
}
int main()
{
    int n;
    printf("enter number of disks");
    scanf("%d",&n);
    t_h(n,'A','B','C');
}