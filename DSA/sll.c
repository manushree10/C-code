#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;  
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
NODE i_f(NODE first,int item)
{
    
    NODE temp;
    temp=getnode();
    temp->link=NULL;
    temp->info=item;
    if(first==NULL)
      return temp;
    {
        temp->link=first;
        return temp;
    }
}
NODE i_r(NODE first,int item)
{
    NODE temp,prev,cur;
     temp=getnode();
     temp->link=NULL;
    temp->info=item;
    if(first==NULL)
      return temp;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    printf("ele deleted%d\n",item);
    return first;
}
NODE d_f(NODE first)
{
    int item;
    NODE next;
    if(first==NULL)
    {
        printf("empty");
        return first;
    }
    item=first->info;
    next=first->link;
    free(first);
    printf("ele deleted %d",item);
    return next;
}
NODE d_r(NODE first)
{ 
     int item;
    NODE cur,prev;
    if(first==NULL)
      return first;
    if(first->link==NULL)
    {
        item=first->info;
        free(first);
        return NULL;
    }
    cur=first;
    prev=NULL;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    item=cur->info;
    free(cur);
    prev->link=NULL;
    return first;
}
void display(NODE first)
{
    NODE cur;
    int item;
    if(first==NULL)
     {
        printf("empty sll");
        return;
      }
      cur=first;
      while(cur!=NULL);
      {
        item=cur->info;
        printf("%d\t",item);
        cur=cur->link;
      }
      printf("%d",cur->info);
}
int main()
{
    NODE first=NULL,next,cur,prev,item;
    int ch,ele;
    while(1)
    {
        printf("enter choice\n1.insert front\n2.insert rear\n3.delete front\n4.delete rear\n5.display\n6.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element");
                   scanf("%d",&ele);
            first=i_f(first,ele);
               break;
            case 2:printf("enter element");
                   scanf("%d",&ele);
            first=i_r(first,ele);
               break;
            case 3:first=d_f(first);
               break;
               case 4:first=d_r(first);
               break;
               case 5:display(first);
               break;
               default:exit(0);
               break;
        }
    }
}
