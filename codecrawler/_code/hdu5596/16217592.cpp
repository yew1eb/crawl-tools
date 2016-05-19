#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll  long long
#define pii pair<int,int>
#define p_queue priority_queue
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define for1(i,l,r) for(int i=l;i<r;i++)
#define for2(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int M=50010;

int type[M],v[M];

int t[M];
int dp[M][2];// dp[i][j] ä¸ºä»iå°nä¸­ç±»åä¸ºjçæå¤§æ°å­

void go()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d%d",type+i,v+i);
    for(int i=1;i<=m;i++)
        scanf("%d",t+i);
    sort(t+1,t+1+m);
    int l,r,mid;
    for(int i=1;i<=n;i++)
    {
        l=1,r=m;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(t[mid]>=i)
                r=mid-1;
            else 
                l=mid+1;
        }
        v[i]+=m-r;
    }
    dp[n+1][0]=dp[n+1][1]=-1;
    for(int i=n;i>=1;i--)
    {
        dp[i][type[i]]=max(dp[i+1][type[i]],v[i]);
        dp[i][1-type[i]]=dp[i+1][1-type[i]];
    }
    
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]>=dp[i+1][1-type[i]])sum++;
    }
    cout<<sum<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)go();
    return 0;
}