/************************************************
 * Author: yew1eb
 * Created Time: 2014/4/16 0:23:35
 * File Name: t.cpp
 *************************************************/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;

struct node 
{
    int a;
    int step;
};

int v1[10000], v2[10000];
struct tt
{
    int x[5];
};
tt numTOarray(int a)
{
    tt tmp;
    tmp.x[4] = a / 1000;
    tmp.x[3] = (a / 100) % 10;
    tmp.x[2] = (a/10) % 10;
    tmp.x[1] = a % 10;
    return tmp;
}
int arrayTOnum(tt a)
{
    return a.x[4]*1000 + a.x[3]*100 + a.x[2]*10 + a.x[1];
}
int Add(int a, int i)
{
    tt tmp = numTOarray(a);
    tmp.x[i] = tmp.x[i]==9 ? 1:tmp.x[i]+1;
    int ret = arrayTOnum(tmp);
    return ret;
}
int Sub(int a, int i)
{
    tt tmp = numTOarray(a);
    tmp.x[i] = tmp.x[i]==1 ? 9:tmp.x[i]-1;
    int ret = arrayTOnum(tmp);
    return ret;
}
int Swap(int a, int i)
{
    tt tmp = numTOarray(a);
    int t = tmp.x[i];
    tmp.x[i] = tmp.x[i+1];
    tmp.x[i+1] = t;
    int ret = arrayTOnum(tmp);
    return ret;
}
int dbfs(int n, int m)
{
    queue<node> q1, q2;
    node now, next;
    memset(v1, -1, sizeof v1 );
    memset(v2, -1, sizeof v2 );
    now.a = n, now.step = 0, q1.push(now), v1[n] = 0;
    now.a = m, now.step = 0, q2.push(now), v2[m] = 0;
    int Floor = 0;
    while(true)
    {
        while(!q1.empty() && q1.front().step == Floor)
        {
            now = q1.front(), q1.pop();
            if(v2[now.a]!=-1) return now.step + v2[now.a];
            
            next.step = now.step + 1;
            for(int i=1; i<=4; ++i)
            {
                next.a = Add(now.a, i);
                if(v1[next.a]==-1)
                {
                    v1[next.a] = next.step;
                    q1.push(next);
                }
            }

            for(int i=1; i<=4; ++i)
            {
                next.a = Sub(now.a, i);
                if(v1[next.a]==-1)
                {
                   v1[next.a] = next.step;
                    q1.push(next);
                }
            }

            for(int i=1; i<=3; ++i)
            {
                next.a = Swap(now.a, i);
                if(v1[next.a] ==-1)
                {
                    v1[next.a] = next.step;
                    q1.push(next);
                }
            }
        }

        while(!q2.empty() && q2.front().step == Floor)
        {
            now = q2.front(), q2.pop();
            if(v1[now.a]!=-1) return now.step + v1[now.a];

            next.step = now.step + 1;
            for(int i=1; i<=4; ++i)
            {
                next.a = Add(now.a, i);
                if(v2[next.a]==-1)
                {
                    v2[next.a] = next.step;
                    q2.push(next);
                }
            }

            for(int i=1; i<=4; ++i)
            {
                next.a = Sub(now.a, i);
                if(v2[next.a]==-1)
                {
                    v2[next.a] = next.step;
                    q2.push(next);
                }
            }

            for(int i=1; i<=3; ++i)
            {
                next.a = Swap(now.a, i);
                if(v2[next.a] ==-1)
                {
                    v2[next.a] = next.step;
                    q2.push(next);
                }
            }
        }
        Floor++;
    }
}
int main()
{
    int t;
    int n, m;
    // freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int ans = dbfs(n, m);
        printf("%d\n",ans);
    }
    return 0;
};
