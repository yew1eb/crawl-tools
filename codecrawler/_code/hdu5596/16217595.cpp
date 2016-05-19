#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string.h>
#include<stack>
using namespace std;
const int  maxn = 1e5+10;
int c[maxn];
struct node
{
    int data;
    int id;
}a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
      int  n,m;
      scanf("%d%d",&n,&m);
      for(int i = 1;i<=n;i++)
      {
          scanf("%d%d",&a[i].id,&a[i].data);
      }
      int x;
      memset(c,0,sizeof(c));
        for(int i = 1;i<=m;i++)
          {
              scanf("%d",&x);
              c[x]++;
          }
          int ans= n;
          int max1= -1;
          int max2= -1;
          for(int i= n;i>=1;i--)
          {    max1-=c[i];
               max2-=c[i];
              if(a[i].id ==1)
               {  //max1-=c[i];
                   if(a[i].data<max2)
                   {
                       ans--;
                   }
                   max1= max(max1,a[i].data);
              }
              else
              {
                 if(a[i].data<max1)
                   {
                       ans--;
                   }
                   max2= max(max2,a[i].data);
              }
          }
          printf("%d\n",ans);
    }
    return 0;
}
