#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll xr,xi,br,bi,mu;
int num_a,t;
int path[105];
bool flag=0;

void dfs(ll xr,ll xi,int num_a)
{
    ll xrr,xii;
    if(num_a>100||flag)
        return ;
    if(xr==0&&xi==0)
    {
        t=num_a;
        flag=1;
        return ;
    }
    for(int i=0;i*i<mu;i++)
    {
        if(flag)
            return;
        xrr=xr,xii=xi;
        xrr-=i;
        if((xrr*br+xii*bi)%mu!=0||(xii*br-xrr*bi)%mu!=0)
            continue;
        ll qxrr=xrr;
        xrr=(xrr*br+xii*bi)/mu;
        xii=(xii*br-qxrr*bi)/mu;
        path[num_a]=i;
        dfs(xrr,xii,num_a+1);
    }
}

int main()
{
    int kase;
    cin>>kase;
    while(kase--)
    {
        cin>>xr>>xi>>br>>bi;
        mu=br*br+bi*bi;
        flag=0;
        dfs(xr,xi,0);
        if(!flag)
        {
            cout<<"The code cannot be decrypted."<<endl;
            continue;
        }
        cout<<path[t-1];
        for(int i=t-2;i>=0;i--)
            cout<<','<<path[i];
        cout<<endl;
    }
    return 0;
}
