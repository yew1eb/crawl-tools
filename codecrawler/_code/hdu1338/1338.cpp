#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#define eps 1e-6
#define INF 0x1f1f1f1f
#define PI acos(-1.0)
#define ll __int64
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

/*
freopen("data.in","r",stdin);
freopen("data.out","w",stdout);
*/
int my[60];
bool vis[1100];

int main()
{
   int n,m,ca=0;

   while(scanf("%d%d",&m,&n)&&m+n)
   {
      memset(vis,false,sizeof(vis));
      for(int i=1;i<=n;i++)
      {
         scanf("%d",&my[i]);
         vis[my[i]]=true;
      }
      sort(my+1,my+n+1); //按自己手上的牌，从大到小排序
      //如果其他人能赢，则只要有一张牌超过自己手上牌就行了，这时可以丢掉其他的小牌
      //当没有比自己大的牌时，后面的一定自己赢了
      int pos=1,ans=0;
      for(int i=1;i<=n;i++)
      {
         int tt=my[i],j;
         for(j=tt+1;j<=n*m;j++) //找到一张没出的比自己最靠近的大牌
            if(!vis[j])
            {
               vis[j]=true;
               break;
            }
         if(j>n*m) //找不到后面肯定自己赢
         {
            ans=n-i+1;
            break;
         }
        if(m==2) //其他人已经出完了
           continue;
        for(int k=0;;) //其他人出较小的牌
        {
           if(!vis[pos])
           {
              vis[pos]=true;
              k++;
           }
           pos++;
           if(k>=m-2)
              break;
        }
      }
      printf("Case %d: %d\n",++ca,ans);

   }
   return 0;
}