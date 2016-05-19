#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
//#pragma comment (linker,"/STACK:1024000000000,102400000000")
#define INF 0x3f3f3f3f
#define MAXN 66666
using namespace std;
int n,curcnt,anscnt,da[11];
bool done[MAXN];
string ans,curans;

struct node
{
    int d,yu,pre,cnt;
    node(int dd=0,int vv=0,int pp=0,int cc=0)
    {
        d=dd;yu=vv;pre=pp;cnt=cc;
    }
}q[MAXN];

bool dfs(int k)
{
    int st=0,en=0;
    memset(done,0,sizeof done);
    q[en++]=node(0,0,-1,0);
    while(st<en)
    {
        node x=q[st++];
        if(x.cnt==anscnt)return 0;
        for(int i=0;i<k;i++)
        {
            if(x.yu==0&&da[i]==0)continue;
            int curyu=(x.yu*10+da[i])%n;
            if(done[curyu])continue;
            if(curyu==0)
            {
                curans="";
                curcnt=x.cnt+1;
                curans+=da[i]+'0';
                int ii=st-1;
                while(q[ii].pre!=-1)
                {
                    curans+=q[ii].d+'0';
                    ii=q[ii].pre;
                }
                reverse(curans.begin(),curans.end());
                return 1;
            }
            done[curyu]=1;
            q[en++]=node(da[i],curyu,st-1,x.cnt+1);
        }
    }
    return 0;
}
int main()
{
    int i,j;
    while(~scanf("%d",&n)&&n)
    {
        anscnt=70000;
        for(da[0]=1;da[0]<=9;da[0]++)
            if(dfs(1))
            {
                if(anscnt>curcnt)
                {
                    ans=curans;
                    anscnt=curcnt;
                }
            }
        if(anscnt==70000)
        for(da[0]=0;da[0]<=9;da[0]++)
            for(da[1]=da[0]+1;da[1]<=9;da[1]++)
                if(dfs(2))
                {
                    if(anscnt>curcnt)
                    {
                        ans=curans;
                        anscnt=curcnt;
                    }
                    else if(anscnt==curcnt&&curans<ans)
                    {
                        ans=curans;
                    }
                }
        cout<<ans<<endl;
    }
    return 0;
}
