#include<bits/stdc++.h>
using namespace std;
const int Inf=1e9;
typedef long long Int;
bool isp[10020];
vector<int>pri;
int cas=1,mul;
int powmod(int x,int y,int mod)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=ret*(Int)x%mod;
        x=x*(Int)x%mod;
        y>>=1;
    }
    return ret;
}
void exgcd(int a,int b,int &x,int &y)
{
    b?(exgcd(b,a%b,y,x),y-=a/b*x):(x=1,y=0);
}
void getp()
{
    for(int i=2;i<=10000;i++)
    {
        if(!isp[i])
        {
            pri.push_back(i);
            for(int j=i+i;j<=10000;j+=i)
                isp[j]=1;
        }
    }
}
void divide(int x,vector<int>&V)
{
    for(int i=0;i<pri.size()&&pri[i]*pri[i]<=x;i++)
    {
        if(x%pri[i]==0)
        {
            V.push_back(pri[i]);
            while(x%pri[i]==0)x/=pri[i];
        }
    }
    if(x>1)V.push_back(x);
}
int getd(int x)
{
    if(x==2)return 1;
    vector<int>tp;
    divide(x-1,tp);
    for(int i=2;;i++)
    {
        bool flag=1;
        for(int j=0;j<tp.size();j++)
            if(powmod(i,(x-1)/tp[j],x)==1)
            {
                flag=0;
                break;
            }
        if(flag)return i;
    }
    return -1;
}
int Mp1[100000000];
int Mp2[10][10000];
void get(int &a,int tx,int p)
{
    if(Mp1[tx]>=0)a=Mp1[tx];
    else
    {
        int now=tx;
        for(int i=1;i*1000000<=p;i++)
        {
            now=now*(Int)mul%p;
            if(Mp1[now]>=0){a=Mp1[now]+i*1000000;return;}
        }
    }
}
int getrev(int a,int b)
{
    int x,y;
    exgcd(a,b,x,y);
    return x<0?(x+b):x;
}
int main()
{
    getp();
    int _;scanf("%d",&_);
    while(_--)
    {
        int sum,m;scanf("%d%d",&sum,&m);
        vector<int>allp;
        vector<int>small;
        divide(sum,allp);
        int maxx=-1,maxsz;
        for(int i=0;i<allp.size();i++)
            if(allp[i]<10000)
            {
                small.push_back(allp[i]);
            }
            else
            {
                int now=1,x=getd(allp[i]);
                maxx=allp[i];
                mul=powmod(x,maxx-1-1000000%(maxx-1),maxx);
                maxsz=min(1000000,maxx-1);
                for(int j=1;j<maxx;j++)Mp1[j]=-1;
                for(int j=0;j<maxsz;j++)
                {
                    if(Mp1[now]<0)Mp1[now]=j;
                    now=now*(Int)x%maxx;
                }
            }
        for(int i=0;i<small.size();i++)
        {
            memset(Mp2[i],-1,sizeof(Mp2[i]));
            int now=1,x=getd(small[i]);
            for(int j=0;j<small[i]-1;j++)
            {
                if(Mp2[i][now]<0)Mp2[i][now]=j;
                now=now*(Int)x%small[i];
            }
        }
        printf("Case #%d:\n",cas);
        while(m--)
        {
            int x,y;scanf("%d%d",&x,&y);
            int ans=Inf;
            for(int i=0;i<small.size();i++)
            {
                int p=small[i];
                int tx=x%p,ty=y%p;
                if(tx==0)
                {
                    if(ty==0)ans=min(ans,1);
                    else if(ty==1)ans=min(ans,0);
                    continue;
                }
                else if(ty==0)continue;
                int a=Mp2[i][tx],b=Mp2[i][ty];
                int gc=__gcd(a,p-1);
                if(b%gc)continue;
                int k=b/gc*(Int)getrev(a/gc,(p-1)/gc)%((p-1)/gc);
                ans=min(ans,k);
            }
            if(maxx!=-1)
            {
                int p=maxx;
                int tx=x%p,ty=y%p;
                if(tx==0)
                {
                    if(ty==0)ans=min(ans,1);
                    else if(ty==1)ans=min(ans,0);
                }
                else 
                if(ty)
                {
                    int a,b;
                    get(a,tx,p);
                    get(b,ty,p);
                    int gc=__gcd(a,p-1);
                    if(b%gc==0)
                    {
                        int k=b/gc*(Int)getrev(a/gc,(p-1)/gc)%((p-1)/gc);
                        ans=min(ans,k);
                    }
                }
            }
            if(ans==Inf)ans=-1;
            printf("%d\n",ans);
        }
        cas++;
    }

}