#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
const int maxn=100010;
class suffix
{
    public:
    int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
    int r[maxn],n;
    int sa[maxn],rank[maxn],height[maxn];
    void init(int *a,int _n)
    {
        n=_n;
        for(int i=0;i<n;i++)r[i]=a[i];
        da(maxn);
        calheight();
    }
    int cmp(int *r,int a,int b,int l)
    {
        return r[a]==r[b]&&r[a+l]==r[b+l];
    }
    void da(int m)
    {
        r[n++]=0;
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p)
        {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
        n--;
    }
    void calheight()
    {
         int i,j,k=0;
         for(i=1;i<=n;i++)rank[sa[i]]=i;
         for(i=0;i<n;height[rank[i++]]=k)
         for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    }
}s;
char ch[maxn];
int a[maxn],n;
long long f[maxn];
int rmq[17][maxn],rmq1[17][maxn];
int main()
{
    while(~scanf("%s",ch))
    {
        n=0;
        for(int i=0;ch[i];i++)
        {
            a[n++]=ch[i];
        }
        s.init(a,n);
        for(int i=1;i<=n;i++)
        {
            rmq[0][i]=s.height[i];
            rmq1[0][i]=s.sa[i];
        }
        for(int i=1;i<=16;i++)
        {
            for(int j=1;j<=n;j++)if(j+(1<<i)-1<=n)
            {
                rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
                rmq1[i][j]=min(rmq1[i-1][j],rmq1[i-1][j+(1<<(i-1))]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            f[i]=n-s.sa[i]-s.height[i];
        }
        for(int i=1;i<=n;i++)f[i]+=f[i-1];
        int l=0,r=0;
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            unsigned long long v;
            scanf("%I64u",&v);
            v=(l^r^v)+1;
            if(v>f[n])
            {
                l=-1,r=-1;
            }
            else
            {
                int L=1,R=n;
                while(L<R)
                {
                    int mid=(L+R)/2;
                    if(f[mid]>=v)
                    {
                        R=mid;
                    }
                    else
                    {
                        L=mid+1;
                    }
                }
                l=s.sa[L];
                int len=v-f[L-1]+s.height[L];
                int now=L+1;
                for(int i=16;i>=0;i--)if(now+(1<<i)-1<=n)
                {
                    if(rmq[i][now]>=len)
                    {
                        l=min(l,rmq1[i][now]);
                        now=now+(1<<i);
                    }
                }
                r=l+len-1;
            }
            l++,r++;
            printf("%d %d\n",l,r);
        }
    }
}