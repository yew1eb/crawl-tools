#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>
#define maxn 510
#define inf 1000
using namespace std;
int cnt[maxn];
char dis[maxn][maxn];
stack<int> S;

int main()
{
    //freopen("data.in","r",stdin);
    int n,maxe,tp;
    while (1)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%s",dis[i]);
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]=='1')
                    cnt[j]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            maxe=-1;
            for(int j=0;j<n;j++)
            {
                    if(cnt[j]>maxe)
                    {
                        tp=j;
                        maxe=cnt[j];
                    }
            }
            cnt[tp]=-2;
            for(int j=0;j<n;j++)
            {
                if(dis[tp][j]=='1')cnt[j]--;
            }
            S.push(tp);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",S.top()+1);
            S.pop();
        }
        puts("");
        
    }
    return 0;
}