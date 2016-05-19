#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int mm=55;
class node
{
    public:
    int x,y,peanuts;
}f[mm*mm];
int grap[mm][mm];
int dp[2][mm*mm];
int cas,m,n,t,pos;
bool cmp(node a,node b)
{
    return a.peanuts>b.peanuts;
}
int fabs(int x)
{
    return x>0?x:-x;
}
int main()
{
    while(cin>>cas)
    {
        while(cas--)
        {    pos=0;
            cin>>m>>n>>t;
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>grap[i][j];
                f[pos].x=i;f[pos].y=j;f[pos].peanuts=grap[i][j];
                pos++;
            }
            sort(f,f+pos,cmp);
            int shu=f[0].peanuts,uset=0,ans=0,nx=0,ny=f[0].y;
            for(int i=0;i<pos;i++)
            {   if(f[i].peanuts==0)break;
                if(uset+fabs(f[i].x-nx)+fabs(f[i].y-ny)+f[i].x+1<=t)
                {
                    uset+=fabs(f[i].x-nx)+fabs(f[i].y-ny)+1;
                    nx=f[i].x;ny=f[i].y;
                    ans+=f[i].peanuts;
                }
                else break;
            }
            cout<<ans<<"\n";
        }
    }
}