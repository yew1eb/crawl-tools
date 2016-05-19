#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<algorithm>
#define For(i,a,n) for(int i=a;i<n;i++)
#define rep(i,n) For(i,0,n)
using namespace std;
int n,m,k,fina;
char ch[4]={'+','-','*','%'};
struct node
{
    int num,step;
    string road;
}ans;
int deal(int x,int key)
{
    if(key==0)
        return x+m;
    else if(key==1)
        return x-m;
    else if(key==2)
        return x*m;
    else
    {
        int tem=x%m;
        if(tem<0)
            tem=tem+m;
        return tem;
    }
}
void bfs()
{
    int tem;
    map < int,int > mp;
    mp[n]=1;
    queue< node >q;
    node in,out;
    in.num=n,in.step=0,in.road="";
    q.push(in);
    while(!q.empty())
    {
        out=q.front();q.pop();
        rep(i,4)
        {
            tem=deal(out.num,i)%(k*m);
            if(mp[tem]==0)
            {
                in.num=tem,in.step=out.step+1,in.road=out.road+ch[i];
                mp[tem]=1;
                int x=tem%k;
                if(x<0)
                    x=x+k;
                if(x==fina)
                {
                    ans=in;
                    return ;
                }
                else
                q.push(in);
            }
        }
    }
}
int main()
{
    
    while(1)
    {
        scanf("%d%d%d",&n,&k,&m);
        if(n==m&&m==k&&k==0)return 0;
            fina=(n+1)%k;
            if(fina<0)
                fina+=k;
            ans.step=0;
            bfs();
            printf("%d\n",ans.step);
            if(ans.step)
                cout<<ans.road<<endl;
    }
    return 0;
}