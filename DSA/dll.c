#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    char sn[20],name[20],dept[20],des[20];
    int sal,ph_no;
    struct node *rlink;  
};
typedef struct node *NODE;
NODE getnode()
{
    NODE first;
    first=(NODE)malloc(sizeof(struct node));
    if(first==NULL)
    {
        printf("memory not allocated");
        exit(0);
    }
    return first;
}
NODE i_f(NODE first)
{
    NODE temp;
    temp=getnode();
    printf("enter sn name dept des sal phone no\n");
    scanf("%s%s%s%s%d%d",temp->sn,temp->name,temp->dept,temp->des,&(temp->sal),&(temp->ph_no));
    temp->llink=temp->rlink=NULL;
    if(first==NULL)
    {
        printf("empty");
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}
NODE i_r(NODE first)
{
    NODE temp,cur;
    temp=getnode();
    printf("enter sn name dept des sal phone no\n");
    scanf("%s%s%s%s%d%d",temp->sn,temp->name,temp->dept,temp->des,&(temp->sal),&(temp->ph_no));
    temp->llink=temp->rlink=NULL;
    if(first==NULL)
    {
        printf("empty");
        return temp;
    }
    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}
NODE d_f(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        printf("empty");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("ele deleted");
        printf("%s%s%s%s%d%d",first->sn,first->name,first->dept,first->des,first->sal,first->ph_no);
        free(first);
        return NULL;

    }
    next=first->rlink;
    printf("ele deleted");
    printf("%s%s%s%s%d%d",first->sn,first->name,first->dept,first->des,first->sal,first->ph_no);
    free(first);
    next->llink=NULL;
    return next;
}
NODE d_r(NODE first)
{
     NODE cur,prev;
     if(first==NULL)
    {
        printf("empty");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("ele deleted\n");
        printf("%s%s%s%s%d%d",first->sn,first->name,first->dept,first->des,first->sal,first->ph_no);
        free(first);
        return NULL;
    }
    cur=first;
    prev=NULL;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur=cur->rlink;
    }
    prev->rlink=NULL;
    printf("ele deleted\n");
        printf("%s%s%s%s%d%d",first->sn,first->name,first->dept,first->des,first->sal,first->ph_no);
        free(cur);
        return first;
}
void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("empty");
        return NULL;
    }
    cur=first;
    while(cur!=NULL)
    {
        printf("display data\n");
        printf("%s%s%s%s%d%d",cur->sn,cur->name,cur->dept,cur->des,cur->sal,cur->ph_no);
        cur=cur->rlink;
    }
}
NODE create(NODE first)
{
    int n,i;
    printf("enter number of students\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        first=i_f(first);
    }
    return first;
}
void status(NODE first)
{
    int cnt=0;
    NODE cur=first;
    if(first==NULL)
    {
        printf("empty");
    }
    while(cur!=NULL)
    {
        cnt++;
        cur=cur->rlink;
    }
    printf("number of students deatails entered %d\t",cnt);
}
int main()
{
    NODE first=NULL,next,cur,prev,item;
    int ch,ele;
    while(1)
    {
        printf("enter choice\n1.create\n2.status\n3.insert front\n4.insert rear\n5.delete front\n6.delete rear\n7.display\n8.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=create(first);
            break;
            case 2:status(first);
               break;
            case 3:first=i_f(first);
               break;
               case 4:first=i_r(first);
               break;
               case 5:first=d_f(first);
               break;
               case 6:first=d_r(first);
               break;
               case 7:display(first);
               break;
               default:exit(0);
               break;
        }
    }
}
