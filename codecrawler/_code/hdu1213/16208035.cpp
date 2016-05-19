#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int father[1010];
int getfather(int n)
{
    while(n!=father[n])
       n=father[n];
    return n;
}
void Union(int x,int y)
{
    int rootx=getfather(x);
    int rooty=getfather(y);
    if(rootx!=rooty)
       father[rooty]=rootx;
}
void inti(int n)
{
    for(int i=1;i<=n;i++)
      father[i]=i;
}
int main()
{
    int N,m,n,i;
     scanf("%d",&N);
       while(N--)
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
            if(father[i]==i)
               c++;
          printf("%d\n",c);
          getchar();  //  è¿ä¸æ­¥æ¯è¾å³é®ï¼æå¼å§ä¸ç´æ²¡æ³¨æå°ï¼æ çº¿waï¼åç¹åã
        }
    return 0;
}