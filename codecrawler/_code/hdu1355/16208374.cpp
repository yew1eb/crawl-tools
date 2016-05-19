/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-24 19:13
 # Filename: ZOJ2235 POJ1928 HDU1355 The Peanuts.cpp
 # Description : 
 ******************************************************************************/
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
#define MAX 3000
using namespace std;

struct NODE
{
  int x,y,p;
  bool operator<(const NODE &t) const
  {
    return p>t.p;
  }
}node[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

    int ncases,n,m,time,temp;
    scanf("%d",&ncases);

    while(ncases--)
    {
        scanf("%d%d%d",&n,&m,&time);

        int cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&temp);
                if(temp)
                {
                    node[cnt].x=i;
                    node[cnt].y=j;
                    node[cnt++].p=temp;
                }
            }
        sort(node,node+cnt);
        int ans=0;
        temp=0;
        if(node[0].x*2+1<=time)
        {
            ans=node[0].p;
            temp=node[0].x+1;
            for(int i=1;i<cnt;++i)
                if(temp+(abs(node[i].x-node[i-1].x)+abs(node[i].y-node[i-1].y)+1) + node[i].x<=time)
                {
                    temp+=(abs(node[i].x-node[i-1].x)+abs(node[i].y-node[i-1].y)+1);
                    ans+=node[i].p;
                }
                else
                    break;
        }
        printf("%d\n",ans);
    }

  return 0;
}
