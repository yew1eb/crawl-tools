#include <iostream>
#include <cstring> 

using namespace std;

int father[10000001];
long long int ans;
int n,m;
const int mod=1000000007;
long long s;

int find(int x)
{
    while (x!=father[x])
        x=father[x];
    return x;
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if (a==b)
        return ;
    father[a]=b;
    ans--;
}

void init()
{
    for (int i=0;i<=n;i++)
        father[i]=i;
}

void fast_power()
{
    s=1;
    long long int t=26;
    while (ans>0)
    {
        if (ans%2==1)
            s=(s*t)%mod;
        t=(t*t)%mod;
        ans=ans/2;
    }
}

int main()
{
    while (cin>>n>>m)
    {
        int a,b;
        init();
        ans=n;
        for (int i=1;i<=m;i++)
        {
            cin>>a>>b;
            Union(a-1,b);
        }
        fast_power();
        cout<<s<<endl;
    }
}