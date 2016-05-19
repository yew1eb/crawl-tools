#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int p[1010];
int getfather(int n)
{
    while(n!=p[n])
       n=p[n];
    return n;
}
void Union(int x,int y)
{
    int rootx=getfather(x);
    int rooty=getfather(y);
    if(rootx!=rooty)
       p[rooty]=rootx;
}
void inti(int n)
{
    for(int i=1;i<=n;i++)
     p[i]=i;
}
int main()
{
    int T,m,n,i;
     scanf("%d",&T);
       while(T--)
       {
          scanf("%d%d",&n,&m);
           inti(n);
           int a,b;
          for(i=1;i<=m;i++)
          {
              scanf("%d%d",&a,&b);
              Union(a,b);
          }
          int c=0;
          for(i=1;i<=n;i++)
            if(p[i]==i)
               c++;
          printf("%d\n",c);
          getchar();  //  这一步比较关键，我开始一直没注意到，无线wa，坑爹啊。
        }
    return 0;
}