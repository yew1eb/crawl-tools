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
#define cin(x) scanf("%d",&x)
#define outln(x) printf("%d\n",x)
#define out(x)  printf("%d",x)
#define outspace(x)  printf("%d ",x);
#define all(v) (v).begin(),(v).end()
#define for1(i,l,r) for(int i=l;i<r;i++)
#define for2(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int M=2000010;

bool use[M];
int p[M];
int s=0;
void init()
{
    for(int i=2;i<M;i++)
    {
        if(!use[i])
        {
            p[s++]=i;
            for(int j=2*i;j<M;j+=i)
                use[j]=1;
        }
    }
    //cout<<s<<endl;
}

void go()
{
   unsigned long long  n,m;
    while(cin>>n>>m)
    {
        unsigned long long t=n+m+1;
        unsigned long long res=t;
        if(t<M&&!use[t]){
            cout<<t-1<<endl;
            continue;
        }
        for(int i=0;i<s&&p[i]<=t;i++)
        {
            if(t%p[i]==0)
            {
                while(t%p[i]==0)t/=p[i];
                res=(res/p[i])*(p[i]-1);
            }
        }
        if(t!=1)
            res=(res/t)*(t-1);
        cout<<res<<endl;
    }

}
int main()
{
    init();
    go();
    return 0;
}