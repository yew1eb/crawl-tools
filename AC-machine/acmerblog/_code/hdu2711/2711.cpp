#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 8005
#define M 16100
struct node
{
    int x,y;
    int min;
    int flag;
}a[N*3];
int b[N],c[N];
int Min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}
void ChangeTree(int t,int k)
{
    a[t].flag+=k;
    a[t].min+=k;
    return ;
}
void CreatTree(int t,int x,int y)
{
    a[t].x=x;
    a[t].y=y;
    a[t].flag=0;
    if(x==y)
    {
        a[t].min=b[x];
        return ;
    }
    int temp=t*2;
    int mid=(a[t].x+a[t].y)/2;
    CreatTree(temp,x,mid);
    CreatTree(temp+1,mid+1,y);
    a[t].min=Min(a[temp].min,a[temp+1].min);
    return ;
}
void InsertTree(int t,int x,int y,int k)
{
    if(a[t].x==x&&a[t].y==y)
    {
        ChangeTree(t,k);
        return ;
    }
    int temp=t*2;
    int mid=(a[t].x+a[t].y)/2;
    if(a[t].flag)
    {
        ChangeTree(temp,a[t].flag);
        ChangeTree(temp+1,a[t].flag);
        a[t].flag=0;
    }
    if(y<=mid)
        InsertTree(temp,x,y,k);
    else if(x>mid)
        InsertTree(temp+1,x,y,k);
    else
    {
        InsertTree(temp,x,mid,k);
        InsertTree(temp+1,mid+1,y,k);
    }
    a[t].min=Min(a[temp].min,a[temp+1].min);
    return ;
}
int FindTree(int t)
{
    if(a[t].x==a[t].y)
    {
        if(a[t].min==0)
            return a[t].x;
        else
            return 0;
    }
    int temp=t*2;
    if(a[t].flag)
    {
        ChangeTree(temp,a[t].flag);
        ChangeTree(temp+1,a[t].flag);
        a[t].flag=0;
    }
    if(a[temp+1].min==0)
        return FindTree(temp+1);
    else
        return FindTree(temp);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        b[1]=0;
        for(i=2;i<=n;i++)
            scanf("%d",&b[i]);
        CreatTree(1,1,n);
        j=1;
        while(a[1].min==0)
        {
            int tt;
            tt=FindTree(1);
            if(!tt)
                tt=1;
            c[tt]=j++;
            InsertTree(1,tt,tt,M);
            InsertTree(1,tt,n,-1);
        }
        for(i=1;i<=n;i++)
            printf("%d\n",c[i]);
    }
    return 0;
}