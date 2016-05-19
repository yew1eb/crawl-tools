#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-8
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )


using namespace std;

int n,pointnum,ans,cnt,l,r,sum,num,p;

struct node1
{
    int x,y,sta;
} Point[1005],temp[1005];

int detmul(const node1 a,const node1 b)
{
    return a.x * b.y - b.x * a.y;
}

bool cmp(const node1 a,const node1 b)
{
    return detmul(a,b)>0;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&Point[i].x,&Point[i].y,&Point[i].sta);
        }
        ans=0;
        for(pointnum=0; pointnum<n; pointnum++)
        {
            cnt=0;
            for(int i=0; i<n; i++)
            {
                if(i==pointnum)continue;
                temp[cnt].x=Point[i].x-Point[pointnum].x;
                temp[cnt].y=Point[i].y-Point[pointnum].y;
                temp[cnt].sta=Point[i].sta;
                if(temp[cnt].y<0||(temp[cnt].y==0&&temp[cnt].x<0))
                {
                    temp[cnt].x*=-1;
                    temp[cnt].y*=-1;
                    temp[cnt].sta=!temp[cnt].sta;
                }
                cnt++;
            }
            sort(temp,temp+cnt,cmp);
            l=0;
            r=0;
            sum=0;
            for(int i=0;i<cnt;i++)
            {
                if(temp[i].sta==0)l++;
            }
            for(int i=0;i<cnt;i=p)
            {
                num=0;
                for(p=i;p<cnt;p++)
                {
                    if(detmul(temp[i],temp[p]))break;
                    if(temp[p].sta)r++;
                    else num++;
                }
                sum=max(sum,l+r+1);
                sum=max(sum,cnt-l-r+p-i+1);
                l-=num;
            }
            ans=max(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
