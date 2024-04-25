#include<stdio.h>
#include<stdlib.h>
#define HZ 3
FILE *fp;
struct employe
{
    int empno;
    char name[20];
    int sal;
};
typedef struct employe EMP;
struct hashtable
{
    int key;
    long int addr;
};
typedef struct hashtable ht;
int hashval(int num)
{
    int key;
    key=num%HZ;
    return key;
}
void insert(FILE *fp,ht *h,int n)
{
    EMP a;
    int i,hindex,countindex;
    for(i=0;i<n;i++)
    {
        printf("enter empno name salary\n");
        scanf("%d%s%d",&(a.empno),a.name,&(a.sal));
        hindex=hashval(a.empno);
        countindex=hindex;
        while(h[hindex].key!=-1)
        {
            hindex=(hindex+1)%HZ;
            if(hindex==countindex)
            {
                printf("entry not possible..\n");
                return;
            }
        }
        h[hindex].key=hashval(a.empno);
        fseek(fp,0,SEEK_END);
        h[hindex].addr=ftell(fp);
        fwrite(&a,sizeof(EMP),1,fp);
        printf("entry successful...\n");
    }
}
void display(FILE *fp,ht *h,int n)
{
    EMP a;
    int i,j;
    for(i=0;i<HZ;i++)
    {
        if(h[i].key!=-1)
        {
            printf("\nhash table:%d\t%d\t",h[i].key,h[i].addr);
            fseek(fp,h[i].addr,SEEK_SET);
            fread(&a,sizeof(EMP),1,fp);
            printf("%d%s%d",a.empno,a.name,a.sal);
        }
    }
}
void search(FILE *fp,ht *h,int n)
{
    EMP a;
    int hindex,countindex;
    printf("enter emp no to search\n");
    scanf("%d",&(a.empno));
    hindex=hashval(a.empno);
    countindex=hindex;
    while(h[hindex].key!=a.empno)
    {
        hindex=(hindex+1)%HZ;
        if(countindex==hindex)
        {
            printf("search unsuccesfull");
            return;
        }
    }
     fseek(fp,h[hindex].addr,SEEK_SET);
     fread(&a,sizeof(EMP),1,fp);
    printf("%d%s%d",a.empno,a.name,a.sal);
}
int main()
{
    ht h[HZ];
    EMP d;
    int n,ch;
    fp=fopen("emp.txt","w+");
    for(n=0;n<HZ;n++)
    h[n].key=-1;
    while(1)
    {
        printf("enter choice\n1.insert\n2.display\n3.search\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter no of empolyee\n");
                   scanf("%d",&n);
                   insert(fp,h,n);
                   break;
            case 2:display(fp,h,n);
                    break;
            case 3:search(fp,h,n);
                    break;
            default:exit(0);
        }
    }
    return 0;
}