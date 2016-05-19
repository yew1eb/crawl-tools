#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>

#define eps 1e-8
#define op operator
#define MOD  10009
#define MAXN  100100

#define FOR(i,a,b)  for(int i=a;i<=b;i++)
#define FOV(i,a,b)  for(int i=a;i>=b;i--)
#define REP(i,a,b)  for(int i=a;i<b;i++)
#define REV(i,a,b)  for(int i=a-1;i>=b;i--)
#define MEM(a,x)    memset(a,x,sizeof a)
#define ll __int64

using namespace std;

int a[100010];
int b[100010];
int vis[100010];

int main()
{
//freopen("ceshi.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        MEM(vis,0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]]=i;
        }
//        for(int i=1;i<=n;i++)
//            cout<<b[i]<<"  ";
//        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                printf("(");
                int num=0;
                while(!vis[i])
                {
                    if(num==0)
                        printf("%d",i);
                    else printf(" %d",i);
                    vis[i]=1;
//                    int x=a[i];
//                    cout<<"xxx "<<x<<endl;
//                    i=b[x];
                    i=a[i];
//                    cout<<"ii "<<i<<"    "<<vis[i]<<endl;
                    num++;
                }
                printf(")");
            }

        }
        puts("");
    }
    return 0;
}
