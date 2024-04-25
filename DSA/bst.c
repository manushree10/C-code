#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    int info;
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
NODE insert(NODE root,int item)
{
    NODE temp,cur,prev;
     temp=getnode();
     temp->info=item;
     temp->llink=temp->rlink=NULL;
    if(root==NULL)
    {
        
        return temp;
    }
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->info>item)
        {
            cur=cur->llink;
        }
        else
            cur=cur->rlink;
    }
    if(prev->info<item)
    {
        prev->rlink=temp;
    }
    else
    {
        prev->llink=temp;
    }
    return root;
}
void pre(NODE root)
{
      if(root==NULL)
        return;
        printf("%d\t",root->info);
        pre(root->llink);
        pre(root->rlink);
}
void in(NODE root)
{
      if(root==NULL)
        return;
        in(root->llink);
        printf("%d\t",root->info);
        in(root->rlink);
}
void post(NODE root)
{
      if(root==NULL)
        return;
        post(root->llink);
        post(root->rlink);
        printf("%d\t",root->info);
}
int main()
{
     int n,ch,i,ele;
     NODE root=NULL;
     printf("enter no nodes in bst\n");
     scanf("%d",&n);
     while(1)
     {
        printf("enter choice\n1.insert\n2.preorder\n3.inorder\n.4.postorder\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
              case 1:printf("enter nodes in bst");
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&ele);
                        root=insert(root,ele);
                    }
                    break;
                case 2:printf("preorder\n");
                pre(root);
                     break;
                case 3:
                printf("inorder\n");
                in(root);
                     break;
                case 4:printf("postorder\n");
                post(root);
                     break;
                default:exit(0);
        }
     }

}
