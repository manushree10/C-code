#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
    int cf;
    int px;
    int py;
    int pz;
    struct poly *link;  
};
typedef struct poly *P;
P getnode()
{
    P temp;
    temp=(P)malloc(sizeof(struct poly));
    return temp;
}
void read_poly(P p1,int n)
{
    P temp,next;
    int i;
    for(i=0;i<n;i++)
    {
        temp=getnode();
        printf("enter cf px py pz\n");
        scanf("%d%d%d%d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        next=p1->link;
        p1->link=temp;
        temp->link=next;
    }
}
void display(P head)
{
    P cur;
    printf("ele of polynomial");
    cur=head->link;
    while(cur!=head)
    {
       if(cur->cf>0)
       {
        printf("+%dX^%dy^%dz^%d\n",cur->cf,cur->px,cur->py,cur->pz);
       }
       else
       {
         printf("%dX^%dy^%dz^%d\n",cur->cf,cur->px,cur->py,cur->pz);
       }
    cur=cur->link;
    }
    printf("\n");
}
P compare(P term,P p2)
{
    P cur;
    cur=p2->link;
    while(cur!=p2)
    {
        if(cur->px==term->px&&cur->py==term->py&&cur->pz==term->pz)
        return cur;
     cur=cur->link;
    }
    return NULL;
}
void insert(P p3,int cf,int px,int py,int pz)
{
    P temp,next;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    next=p3->link;
    p3->link=temp;
    temp->link=next;
}
void add(P p1,P p2,P p3)
{
    P cur,res;
    cur=p1->link;
    while(cur!=p1)
    {
        res=compare(cur,p2);
        if(res!=NULL)
        {
            insert(p3,cur->cf+res->cf,cur->px,cur->py,cur->pz);
            res->cf=-999;
        }
        else
        {
            insert(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        cur=cur->link;
    }
    cur=p2->link;
    while(cur!=p2)
    {
        if(cur->cf!=-999)
        {
            insert(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        cur=cur->link;
    }
}
void eval(P p3)
{
    int x,y,z,res=0;
    P cur;
    printf("enter valuse of x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    for(cur=p3->link;cur!=p3;cur=cur->link)
    {
        res=res+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
        
    }
    printf("evaluate poly is%d\n",res);
}
    
int main()
{
    P p1,p2,p3;
    int m,n,ch,a;
    while(1)
    {
        printf("enter choice\n1.add poly\n2.evaluate\n3.exit");
        scanf("%d",&ch);
        switch(ch)
        {
    case 1:p1=getnode();
    p1->link=p1;
    printf("enter terms of p1\n");
    scanf("%d",&n);
    read_poly(p1,n);
    display(p1);
    p2=getnode();
    p2->link=p2;
    printf("enter terms of p2\n");
    scanf("%d",&m);
    read_poly(p2,m);
    display(p2);
    p3=getnode();
    p3->link=p3;
    add(p1,p2,p3);
    display(p3);
    break;
    case 2:
           
           display(p3);
           eval(p3);
           break;
    default:exit(0);
     }
    }
}