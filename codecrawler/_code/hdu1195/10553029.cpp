#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int visz[10000],visf[10000];
struct NODE
{
    int a[5];//ÎÒÓÃÒ»¸ö½á¹¹Ìå´æµÄËÄÎ»Êý
}s,t;
struct QUEUE
{
    NODE p;int step;
}q1[100000],q2[100000];
int m,n;
NODE pis(int x)
{
    NODE ls;
    ls.a[4]=x%10;
    ls.a[3]=(x/10)%10;
    ls.a[2]=(x/100)%10;
    ls.a[1]=(x/1000)%10;
    return ls;
}
int antipis(NODE x)
{
    int a;
    a=x.a[4]+10*x.a[3]+100*x.a[2]+1000*x.a[1];
    return a;
}
int solve()
{
    NODE s,t;
    s=pis(n); t=pis(m);
    visz[n]=visf[m]=0;//visit
    int h1=1,h2=1,t1=2,t2=2;
    q1[1].p=s; q2[1].p=t; q1[1].step=q2[1].step=0;
    int stp=0;
    while(1)
    {
        while(h1<t1&&q1[h1].step==stp)//forward direction
        {
            QUEUE sta=q1[h1++];
            int tp=antipis(sta.p);
            if(visf[tp]!=-1) return visf[tp]+sta.step;
            NODE now;
            for(int i=1;i<=4;i++)//plus one
            {
                now=sta.p; now.a[i]+=1;
                if(now.a[i]==10) now.a[i]=1;
                int sk=antipis(now);
                if(visz[sk]==-1)//haven't search
                {
                    q1[t1].p=now; q1[t1++].step=sta.step+1;
                    visz[sk]=sta.step+1;
                }
            }
            for(int i=1;i<=4;i++)//subtract one
            {
                now=sta.p; now.a[i]-=1;
                if(now.a[i]==0) now.a[i]=9;
                int sk=antipis(now);
                if(visz[sk]==-1)//haven't search
                {
                    q1[t1].p=now; q1[t1++].step=sta.step+1;
                    visz[sk]=sta.step+1;
                }
            }
            for(int i=1;i<=3;i++)//swap
            {
                now=sta.p; swap(now.a[i],now.a[i+1]);
                int sk=antipis(now);
                if(visz[sk]==-1)//haven't search
                {
                    q1[t1].p=now; q1[t1++].step=sta.step+1;
                    visz[sk]=sta.step+1;
                }
            }
        }
        while(h2<t2&&q2[h2].step==stp)//opposite direction
        {
            QUEUE sta=q2[h2++];
            int tp=antipis(sta.p);
            if(visz[tp]!=-1) return visz[tp]+sta.step;
            NODE now;
            for(int i=1;i<=4;i++)//anti plus one
            {
                now=sta.p;
                if(now.a[i]==1) now.a[i]=9;
                else now.a[i]-=1;
                int sk=antipis(now);
                if(visf[sk]==-1)//haven't search
                {
                    q2[t2].p=now; q2[t2++].step=sta.step+1;
                    visf[sk]=sta.step+1;
                }
            }
            for(int i=1;i<=4;i++)//anti subtract one
            {
                now=sta.p;
                if(now.a[i]==9) now.a[i]=1;
                else now.a[i]+=1;
                int sk=antipis(now);
                if(visf[sk]==-1)//haven't search
                {
                    q2[t2].p=now; q2[t2++].step=sta.step+1;
                    visf[sk]=sta.step+1;
                }
            }
            for(int i=1;i<=3;i++)//anti swap
            {
                now=sta.p; swap(now.a[i],now.a[i+1]);
                int sk=antipis(now);
                if(visf[sk]==-1)//haven't search
                {
                    q2[t2].p=now; q2[t2++].step=sta.step+1;
                    visf[sk]=sta.step+1;
                }
            }
        }
        stp++;
    }
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        memset(visz,-1,sizeof visz);
        memset(visf,-1,sizeof visf);
        scanf("%d%d",&n,&m);
        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}