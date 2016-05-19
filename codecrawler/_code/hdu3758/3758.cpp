#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 10010

bool prime[MAXN+5];
int p[1400];
int up;
int num[1400];
int ans[MAXN][2];
vector <short> init[MAXN+2];

void Prime()
{
    int i,k;
    up=0;
    memset(prime,0,sizeof(prime));
    for (i=2;i<MAXN;i++)
    {
        if (prime[i]==1) continue;
        k=i;
        while(k*i<MAXN)
        {
            prime[i*k]=1;
            k++;
        }
        p[up++]=i;
    }
}

int GetNum(int t,int k)
{
    if (t<k) return 0;
    return t/k+GetNum(t/k,k);
}

void Init()
{
    int i,j;
    for (i=1;i<MAXN;i++)
    {
        for (j=0;j<up;j++)
        {
            if (i<p[j]) break;
            init[i].push_back(GetNum(i,p[j]));
        }
    }
}

bool Check(int t,int k)
{
    int i;
    for (i=0;i<k;i++)
    {
        if (t<p[i]) break;
        if (init[t][i]>num[i]) return false;
    }
    return true;
}

int Count(int t,int &k)
{
    int i,ss,tag;
    ss=100000;
    for (i=0;i<k;i++)
    {
        if (t<p[i]) break;
        ss=min(ss,num[i]/init[t][i]);
    }
    tag=k;
    for (i=0;i<k;i++)
    {
        if (t<p[i]) break;
        num[i]-=ss*init[t][i];
        if (num[i]==0) tag=min(tag,i);
    }
    k=tag;
    return ss;
}

int main()
{
    int T,i,j,n,m,s,k,l,r,mid,now,x;
    Prime();
    Init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        s=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            for (j=0;j<up;j++)
            {
                if (x<p[j]) break;
                num[j]+=init[x][j];
            }
            s=max(s,j);
        }
        for (i=0;i<m;i++)
        {
            scanf("%d",&x);
            for (j=0;j<up;j++)
            {
                if (x<p[j]) break;
                num[j]-=init[x][j];
            }
            s=max(s,j);
        }
        k=s;
        for (i=0;i<s;i++)
        {
            if (num[i]<0) break;
            if (num[i]==0) k=min(k,i);
        }
        if (i<s)
        {
            printf("-1\n");
            continue;
        }
        now=0;
        while(1)
        {
            if (k==0) break;
            l=1;
            r=p[k]-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if (Check(mid,k)==true) l=mid+1;
                else r=mid-1;
            }
            ans[now][0]=r;
            ans[now++][1]=Count(r,k);
        }
        printf("%d\n",now);
        for (i=0;i<now;i++)
        {
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}
