#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=22;
int sg[maxn][maxn],vis[maxn];
void init()
{
    int i,j,k;
    for(k=1;k<=20;k++)
    {
        sg[k][0]=0;
        for(i=1;i<=20;i++)
        {
            memset(vis,0,sizeof(vis));
            for(j=1;j<=min(i,k);j++)
                vis[sg[k][i-j]]=1;
            for(j=0;;j++)if(!vis[j]){sg[k][i]=j;break;}
        }
    }
}
int main()
{
    int n,T;
    init();
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ans=0,a,b,i;
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            ans^=sg[b][a];
        }
        if(ans==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
    ç®ååå¼(ç»åæ¸¸æ)
    è£¸çSGå®ç
*/
