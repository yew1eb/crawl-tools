#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 1010
using namespace std;

struct NODE
{
  char name[40];
  int price,quality;
};

NODE node[MAX];

int quality[MAX];
int n,m;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncase=1;
  char str[40];
  scanf("%d",&ncase);

  while(ncase--)
  {
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=0;i<n;++i)
    {
      getchar();
      scanf("%s%s%d%d",node[i].name,str,&node[i].price,&node[i].quality);
      quality[cnt++]=node[i].quality;
    }
    sort(quality,quality+cnt);
    cnt=unique(quality,quality+cnt)-quality;
    int low=0,high=cnt-1;
    int ans=0;
    while(high>=low)
    {
      int mid=(low+high)>>1;
      int qua=quality[mid];
      int now=0,pre=0;
      int sum=0;
      while(pre<n)
      {
        int tmp=INT_MAX;
        while(!strcmp(node[now].name,node[pre].name))
        {
          if(node[now].quality>=qua)
            tmp=min(tmp,node[now++].price);
          else
            now++;
        }
        if(tmp==INT_MAX || sum+tmp>m)
          break;
        else
        {
          sum+=tmp;
          pre=now;
        }
      }
      if(pre<n || sum>m)
        high=mid-1;
      else
      {
        ans=mid;
        low=mid+1;
      }
    }
    printf("%d\n",quality[ans]);
  }

  return 0;
}
