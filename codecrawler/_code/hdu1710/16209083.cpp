#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int i,j,k;

int n;
int a[1010],b[1010];
int c[1010];
struct node
{
    int data;
    node * pl;
    node * pr;
}p[1010];

int pa;
node * dfs(int zhi,int l,int r)
{
    int t=-1;
    for(i=l;i<=r;i++)
        if(b[i]==zhi){
            t=i;
            break;
        }
    if(t==-1)
    {
        return NULL;
    }
    int ans=pa;
    pa++;
    p[ans].data=zhi;
    p[ans].pl=dfs(a[pa],l,t-1);
    if(p[ans].pl!=NULL)
    {
        pa++;
    }
    p[ans].pr=dfs(a[pa],t+1,r);
    if(p[ans].pr==NULL)
        pa--;
    return p+ans; 
}
int flag;
void post(node * pp)
{
    if(pp->pl!=NULL)
        post(pp->pl);
    if(pp->pr!=NULL)
        post(pp->pr);
    if(flag==0){
        printf("%d",pp->data);
        flag=1;
    }
    else
        printf(" %d",pp->data);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        pa=1;
        node * pp=dfs(a[pa],1,n);
        flag=0;
        post(pp);
        printf("\n");
    }
}