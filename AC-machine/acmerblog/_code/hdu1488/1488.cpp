#include<stdio.h>
#define inf 1000009
struct node
{
    __int64 q;
    int  num;
    int  next;
 
}p[inf];
int link[inf],m;
void init()
{
    for(int  i=0;i<=inf;i++)
    {
        link[i]=0;
 
    }
    m=1;
 
}
int  find(__int64 q,int  x)
{
    int i;
    for(i=link[x];i>0;i=p[i].next)
    {
        if(q==p[i].q)
        {
            p[i].num++;
            return  p[i].num;
        }
    }
 
    return 0;
}
void add(__int64 q,int  x)
{
    p[m].q=q;
    p[m].num=1;
    p[m].next=link[x];
    link[x]=m++;
}
int  main()
{
    int n,a,b;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&a,&b);
        init();
        __int64  x=b%n;
        int   ans = 0;
        while(1)
        {
            int temp=find(x,x%inf);
            if(temp==0)
              add(x,x%inf);
            else
            if(temp==2)ans++;
            else if(temp==3)break;
 
 
            x=(((a*x)%n*x)%n+b)%n;
        }
        printf("%d\n",n-ans);
 
 
    }
}