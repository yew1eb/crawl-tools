#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
int num[110][110];
set<int>sr[110],sc[110];
int r,c,T;
bool beyond(int tr,int tc)
{
    return tr<1||tc<1||tr>r||tc>c;
}
struct point
{
    int tr,tc,flag;
    point(){}
    point(int tr,int tc,int flag)
    {
        this->tr=tr;
        this->tc=tc;
        this->flag=flag;
    }
}hehe[110];
vector<point>bx;
bool vis[110][110];
void gao(int tr,int tc,int flag,int cnt)
{
    if(!beyond(tr,tc)&&!vis[tr][tc])
    {
        if(num[tr][tc]>0)
        {
            num[tr][tc]++;
            if(num[tr][tc]>4)
            {
                sr[tr].erase(tc);
                sc[tc].erase(tr);
                num[tr][tc]=-cnt;
                bx.push_back(point(tr,tc,0));
                vis[tr][tc]=1;
            }
        }
        else
            bx.push_back(point(tr,tc,flag));
    }
}
void work()
{
    set<int>::iterator it;
    int cnt=0,p=0;
    while(1)
    {
        int len=bx.size(),mn=INT_MAX;
        if(p==len)
            return;
        for(int i=p;i<len;i++)
        {
            point t=bx[i];
            int tr=t.tr,tc=t.tc,flag=t.flag;
            if(flag==0||flag==1)
            {
                it=sc[tc].lower_bound(tr);
                if(it!=sc[tc].begin())
                {
                    it--;
                    mn=min(mn,tr-*it);
                }
            }
            if(flag==0||flag==2)
            {
                it=sc[tc].upper_bound(tr);
                if(it!=sc[tc].end())
                    mn=min(mn,*it-tr);
            }
            if(flag==0||flag==3)
            {
                it=sr[tr].lower_bound(tc);
                if(it!=sr[tr].begin())
                {
                    it--;
                    mn=min(mn,tc-*it);
                }
            }
            if(flag==0||flag==4)
            {
                it=sr[tr].upper_bound(tc);
                if(it!=sr[tr].end())
                    mn=min(mn,*it-tc);
            }
        }
        if(cnt+mn>T)
            return;
        cnt+=mn;
        memset(vis,0,sizeof(vis));
        for(int i=p;i<len;i++)
        {
            point t=bx[i];
            int tr=t.tr,tc=t.tc,flag=t.flag;
            if(flag==0||flag==1)
            {
                tr-=mn;
                gao(tr,tc,1,cnt);
                tr+=mn;
            }
            if(flag==0||flag==2)
            {
                tr+=mn;
                gao(tr,tc,2,cnt);
                tr-=mn;
            }
            if(flag==0||flag==3)
            {
                tc-=mn;
                gao(tr,tc,3,cnt);
                tc+=mn;
            }
            if(flag==0||flag==4)
            {
                tc+=mn;
                gao(tr,tc,4,cnt);
                tc-=mn;
            }
        }
        p=len;
    }
}
int main()
{
    int n;
    while(scanf("%d%d%d%d",&r,&c,&n,&T)!=EOF)
    {
        for(int i=1;i<=r;i++)
            sr[i].clear();
        for(int i=1;i<=c;i++)
            sc[i].clear();
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d%d%d",&hehe[i].tr,&hehe[i].tc,&t);
            sr[hehe[i].tr].insert(hehe[i].tc);
            sc[hehe[i].tc].insert(hehe[i].tr);
            num[hehe[i].tr][hehe[i].tc]=t;
        }
        int tr,tc;
        scanf("%d%d",&tr,&tc);
        bx.clear();
        bx.push_back(point(tr,tc,0));
        work();
        for(int i=0;i<n;i++)
        {
            tr=hehe[i].tr;
            tc=hehe[i].tc;
            int t=num[tr][tc];
            if(t<0)
                printf("0 %d\n",-t);
            else
                printf("1 %d\n",t);
        }
    }
}