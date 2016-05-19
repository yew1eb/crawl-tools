#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <set>
#define maxn 1000010
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

using namespace std;

typedef long long ll;

const int N=200015;

struct Range
{
    int st,ed,ind;
    Range(){}
    Range(int st,int ed,int ind) :
        st(st),ed(ed),ind(ind) {}
    bool operator<(const Range &B)const
    {
        return ed<B.ed;
    }
};

int n,m,mx;
int A[N],L[N],R[N],pos[N];
int ans[3][N],num[N];

vector<Range>rab[3],range;

void fun(bool flag)
{
    if(flag==0)
    {
        for(int i=0;i<=mx;i++) pos[i]=0;

        for(int i=1;i<=n;i++)
        {
            int tmp=A[i];
            for(int j=2;j*j<=tmp;j++)
            {
                if(tmp%j) continue;
                L[i]=max(L[i],pos[j]);
                pos[j]=i;
                while(tmp%j==0) tmp/=j;
            }
            if(tmp!=1)
            {
                L[i]=max(L[i],pos[tmp]);
                pos[tmp]=i;
            }
        }
    }
    else
    {
        for(int i=0;i<=mx;i++) pos[i]=n+1;

        for(int i=n;i>=1;i--)
        {
            int tmp=A[i];
            for(int j=2;j*j<=tmp;j++)
            {
                if(tmp%j) continue;
                R[i]=min(R[i],pos[j]);
                pos[j]=i;
                while(tmp%j==0) tmp/=j;
            }
            if(tmp!=1)
            {
                R[i]=min(R[i],pos[tmp]);
                pos[tmp]=i;
            }
        }
    }
}


struct BIT
{
    int T[N];

    void clear() { for(int i=1;i<=n+10;i++) T[i]=0; }

    int lowbit(int x) { return x&(-x); }
    void updata(int pos)
    {
        if(pos==0||pos==n+1) return;
        for(int i=pos;i<=n;i+=lowbit(i)) T[i]++;
    }
    int query(int st,int ed)
    {
        int ans=0;
        for(int i=ed;i>=1;i-=lowbit(i)) ans+=T[i];
        for(int i=st-1;i>=1;i-=lowbit(i)) ans-=T[i];
        return ans;
    }
}seg;

void getAns(int key)
{
    seg.clear();

    int ind=0;
    for(int i=0;i<m;i++)
    {
        int st=range[i].st;
        int ed=range[i].ed;
        int id=range[i].ind;

        while(ind<n&&rab[key][ind].ed<=ed)
        {
            seg.updata(rab[key][ind].st);
            ind++;
        }
        ans[key][id]+=seg.query(st,ed);
    }
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;

        range.clear(); mx=0;
        rab[0].clear(); rab[1].clear(); rab[2].clear();

        for(int i=0;i<N;i++)
        {
            L[i]=0; R[i]=n+1;
            ans[0][i]=ans[1][i]=ans[2][i]=0;
        }

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            mx=max(mx,A[i]);
        }
        for(int i=0;i<m;i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            num[i]=y-x+1;
            range.push_back(Range(x,y,i));
        }

        fun(0); fun(1);

        for(int i=1;i<=n;i++)
        {
            rab[0].push_back(Range(L[i],i,0));
            rab[1].push_back(Range(i,R[i],0));
            rab[2].push_back(Range(L[i],R[i],0));
        }

        sort(range.begin(),range.end());
        sort(rab[0].begin(),rab[0].end());
        sort(rab[1].begin(),rab[1].end());
        sort(rab[2].begin(),rab[2].end());

        getAns(0);
        getAns(1);
        getAns(2);

        for(int i=0;i<m;i++) printf("%d\n",num[i]-ans[0][i]-ans[1][i]+ans[2][i]);
    }
    return 0;
}
