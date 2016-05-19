#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
//typedef long long lld;
const int oo=0x3f3f3f3f;
//const lld OO=1LL<<61;
const int MOD=10007;
const int maxn=200010;
int h[maxn],n,len;
int p[maxn];

int Manacher()
{
    int mx=0,id=0;
    for(int i=1;i<=len;i++)
    {
        if(mx>i)
            p[i]=min(mx-i,p[2*id-i]);
        else
            p[i]=1;
        while(h[i+p[i]]==h[i-p[i]]&&h[i-p[i]]<=h[i-p[i]+2])
            p[i]++;
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
    }
    int ans=0;
    for(int i=1;i<=len;i++)
        ans=max(ans,p[i]-1);
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        len=0;
        h[len]=oo;
        for(int i=1;i<=n;i++)
        {
            h[++len]=-1;
            scanf("%d",&h[++len]);
        }
        h[++len]=-1;
        h[++len]=-oo;
        printf("%d\n",Manacher());
    }
    return 0;
}
/**
2
3
51 52 51
4
51 52 52 51
*/




