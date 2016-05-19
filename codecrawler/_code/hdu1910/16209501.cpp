/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-12 19:22
 # Filename: ZOJ3116 POJ3483 HDU1910 Loan Scheduling.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
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
#define MAX 10010
using namespace std;

pair<int ,int> app[MAX];
bool used[MAX];

bool inline cmp(const pair<int,int> &lhs,const pair<int,int> &rhs)
{
    if(lhs.first==rhs.first)
        return lhs.second>rhs.second;
    else
        return lhs.first<rhs.first;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
    int n,l;

    while(~scanf("%d%d",&n,&l))
    {
        for(int i=0;i<n;++i)
            scanf("%d%d",&app[i].second,&app[i].first);
        sort(app,app+n,cmp);
        memset(used,false,sizeof(used));

        int remain=l,now=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            remain +=(app[i].first-now)*l;
            if(now<=app[i].first && remain)
            {
                --remain;
                ans+=app[i].second;
                used[i]=true;
            }
            else if(now<=app[i].first && !remain)
            {
                int t_ind=i;
                for(int j=i-1;j>=0;--j)
                    if(used[j] && app[j].second<app[t_ind].second)
                        t_ind=j;
                if(t_ind!=i)
                {
                    used[t_ind]=false;
                    ans-=app[t_ind].second;
                    used[i]=true;
                    ans+=app[i].second;
                }
            }
            now = app[i].first;
        }
        printf("%d\n",ans);
    }

  return 0;
}
