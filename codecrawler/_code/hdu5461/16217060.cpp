#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int tz[5000050],tf[5000050];
bool compare(int a,int b)
{
    return a<b;
}
int main()
{
    int T,tt=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        long long a,b;
        int tzlen=0,tflen=0;
        scanf("%d%lld%lld",&n,&a,&b);
        for(int i=0; i<n; i++)
        {
            int num;
            scanf("%d",&num);
            if(num>=0)
                tz[tzlen++]=num;
            else tf[tflen++]=-num;
        }
        sort(tz,tz+tzlen,compare);
        sort(tf,tf+tflen,compare);
        long long Max;
        if(tzlen>1&&tflen>1)
        {
            if(a>=0&&b>=0)
            {
                Max=a*tz[tzlen-1]*tz[tzlen-1]+b*tz[tzlen-2];
                Max=max(Max,a*tz[tzlen-2]*tz[tzlen-2]+b*tz[tzlen-1]);
                Max=max(Max,a*tf[tflen-1]*tf[tflen-1]+b*tz[tzlen-1]);
            }
            else if(a>=0&&b<0)
            {
                Max=-b*tf[tflen-1]+a*tz[tzlen-1]*tz[tzlen-1];
                Max=max(Max,-b*tf[tflen-1]+a*tf[tflen-2]*tf[tflen-2]);
                Max=max(Max,-b*tf[tflen-2]+a*tf[tflen-1]*tf[tflen-1]);
            }
            else if(a<0&&b>=0)
            {
                Max=a*tz[0]*tz[0]+b*tz[tzlen-1];
                Max=max(Max,a*tf[0]*tf[0]+b*tz[tzlen-1]);
            }
            else
            {
                Max=-b*tf[tflen-1]+a*tz[0]*tz[0];
                Max=max(Max,-b*tf[tflen-1]+a*tf[0]*tf[0]);
            }
        }else if(tzlen==0)
        {
            if(a>=0&&b>=0)
            {
                Max=a*tf[tflen-1]*tf[tflen-1]-b*tf[0];
            }
            else if(a>=0&&b<0)
            {
                Max=-b*tf[tflen-1]+a*tf[tflen-2]*tf[tflen-2];
                Max=max(Max,-b*tf[tflen-2]+a*tf[tflen-1]*tf[tflen-1]);
            }
            else if(a<0&&b>=0)
            {
                Max=a*tf[1]*tf[1]-b*tf[0];
                Max=max(Max,a*tf[0]*tf[0]-b*tf[1]);
            }
            else
            {
                Max=-b*tf[tflen-1]+a*tf[0]*tf[0];
            }

        }else if(tflen==0)
        {
            if(a>=0&&b>=0)
            {
                Max=a*tz[tzlen-1]*tz[tzlen-1]-b*tz[tzlen-2];
                Max=max(Max,a*tz[tzlen-2]*tz[tzlen-2]-b*tz[tzlen-1]);
            }
            else if(a>=0&&b<0)
            {
                Max=a*tz[tzlen-1]*tz[tzlen-1]-b*tz[0];
            }
            else if(a<0&&b>=0)
            {
                Max=a*tz[0]*tz[0]-b*tz[tzlen-1];
            }
            else
            {
                Max=a*tz[0]*tz[0]-b*tz[1];
                Max=max(Max,a*tz[1]*tz[1]-b*tz[0]);
            }

        }else
        {
            Max=a*tz[0]*tz[0]-b*tf[0];
            Max=max(Max,a*tf[0]*tf[0]+b*tz[0]);
        }

        printf("Case #%d: %lld\n",tt++,Max);
    }
}
