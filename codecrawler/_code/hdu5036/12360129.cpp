#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1010;

int n;
int v[MaxN][MaxN];

int Stop,Bcnt,Dindex;
int DFN[MaxN],LOW[MaxN],instack[MaxN],Stap[MaxN],Belong[MaxN];
int size[MaxN];

int w[MaxN][MaxN];
int b[MaxN];
bitset<MaxN> s[MaxN];

void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (int k=1;k<=v[i][0];++k)
    {
        j=v[i][k];
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        s[Bcnt].reset();
        size[Bcnt]=0;
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
            s[Bcnt][j]=1;
            size[Bcnt]++;
        }
        while (j!=i);
    }
}

void calc(int x)
{
    if (b[x]) return;
    for (int i=1;i<=w[x][0];++i)
    {
        int y=w[x][i];
        if (x==y) continue;
        calc(y);
        s[x]|=s[y];
    }
    b[x]=1;
}

int main()
{
    int Test;
    cin>>Test;
    for (int T=1;T<=Test;++T)
    {
        printf("Case #%d: ",T);
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&v[i][0]);
            for (int j=1;j<=v[i][0];++j)
                scanf("%d",&v[i][j]);
        }
        Stop=Bcnt=Dindex=0;
        for (int i=1;i<=n;++i)
            DFN[i]=instack[i]=0;
        for (int i=1;i<=n;++i)
            if (!DFN[i]) tarjan(i);
        for (int i=1;i<=Bcnt;++i)
        {
            w[i][0]=0;
            b[i]=0;
        }
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=v[i][0];++j)
            {
                int x=Belong[i];
                int y=Belong[v[i][j]];
                if (x==y) continue;
                w[y][0]++;
                w[y][w[y][0]]=x;
            }
        }
        ld ans=0;
        for (int i=1;i<=Bcnt;++i)
        {
            calc(i);
            ans+=(ld)size[i]/(s[i].count());
        }
        printf("%.5f\n",(double)ans);
    }
    return 0;
}