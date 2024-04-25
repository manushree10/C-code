#include<stdio.h>
#include<stdlib.h>
struct node
{
    char usn[20],name[20],branch[20];
    int sem,ph_no;
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
NODE i_f(NODE first)
{
    
    NODE temp;
    temp=getnode();
    printf("enter the name\tusn\tbranch\tsem\tphone number\n");
    scanf("%s%s%s%d%d",temp->name,temp->usn,temp->branch,&(temp->sem),&(temp->ph_no));
    temp->link=first;
    return temp;
}
NODE i_r(NODE first)
{
    NODE temp,cur;
     cur=first;
     temp=getnode();
     temp->link=NULL;
    printf("enter the name\tusn\tbranch\tsem\tphone number\n");
    scanf("%s%s%s%d%d",temp->name,temp->usn,temp->branch,&(temp->sem),&(temp->ph_no));
    if(first==NULL)
      return temp;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}
NODE d_f(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        printf("empty");
        return first;
    }
    next=first->link;
    printf("ele deleted student details");
    printf("name=%s\tusn=%s\tbranch=%s\tsem=%d\tphone number=%d\n",first->name,first->usn,first->branch,first->sem,first->ph_no);
    free(first);
    return next;
}
NODE d_r(NODE first)
{ 
    NODE cur,prev;
    cur=first;
    prev=NULL;
    if(first==NULL)
      return first;
    if(first->link==NULL)
    {
        printf("ele deleted student details");
       printf("name=%s\tusn=%s\tbranch=%s\tsem=%d\tphone number=%d\n",first->name,first->usn,first->branch,first->sem,first->ph_no);
        free(first);     
        return NULL;
    }
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("ele deleted student details");
    printf("name=%s\tusn=%s\tbranch=%s\tsem=%d\tphone number=%d\n",first->name,first->usn,first->branch,first->sem,first->ph_no);
    free(cur);
    prev->link=NULL;
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
        cur=cur->link;
    }
    printf("number of students deatails entered %d\t",cnt);
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    if(first==NULL)
     {
        printf("empty sll");
        return;
      }
      while(cur!=NULL)
      {
        printf("name=%s\tusn=%s\tbranch=%s\tsem=%d\tphone number=%d\n",cur->name,cur->usn,cur->branch,cur->sem,cur->ph_no);
        cur=cur->link;
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
