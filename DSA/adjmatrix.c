#include<stdio.h>
#include<stdlib.h>
#define size 20
int a[10][10],F[100];
void read_adj(int n)
{
    int i,j;
    printf("enter adjacent matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
int main()
{
    int i,j,s[10],source,top=-1,n,no_cn;
    printf("enter no of nodes in graph\n");
    scanf("%d",&n);
    read_adj(n);
    for(source=0;source<n;source++)
    {
        for(i=0;i<n;i++)
        {
            F[i]=0;
        }
            F[source]=1;
             s[++top]=source;
        
             printf("node reachable from %d:%d\n",source,source);
        while(top!=-1)
        {
            no_cn=0;
            for(j=0;j<n;j++)
            {
                if(a[s[top]][j]==1&&F[j]==0)
                {
                    printf("%d\n",j);
                    s[++top]=j;
                    F[j]=1;
                    no_cn=1;
                    break;
                }
            }
                if(no_cn==0)
                {
                    top--;
                }

            }
        }
}