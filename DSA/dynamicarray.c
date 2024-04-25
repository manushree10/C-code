#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define days 7
struct activity
{
    char *nday;
    int date;
    char *desc;
};
typedef struct activity *plan;
plan create()
{
   plan *t;
   t=(plan*)malloc(sizeof(struct activity));
   if(t==NULL)
   {
    printf("memort not allocated\n");
    return *t;
   }
}
void read(plan p)
{
    int i;
    for(i=0;i<days;i++)
    {
        p[i].nday=(char*)malloc(sizeof(struct activity));
        printf("enter the name of the day");
        scanf("%s",p[i].nday);
        printf("enter the date of the day\n");
        scanf("%d",&p[i].date);
        printf("enter the discription of the day\n");
        p[i].desc=(char*)malloc(sizeof(struct activity));
        scanf("%s",p[i].desc);
        p[i].desc=(char*)realloc(p[i].desc,strlen(p[i].desc)+1);
    } 
}
void display(plan p)
{
     int i;
     printf("**** activity %d days",days);
     for(i=0;i<days;i++)
     {
        printf("\nname of the day:%s\n",p[i].nday);
        printf("\ndate of the day:%d\n",p[i].date);
        printf("\nactivity dis:%s\n",p[i].desc);
     }
}
int main()
{
    plan cal=NULL;
    cal=create();
    read(cal);
    display(cal); 
}