#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
vector<int>v[100005];
int get_sg(int u,int pre){
    int ret=0;
    for(int i=0; i<v[u].size(); i++)
        if(v[u][i]!=pre)
            ret^=(1+get_sg(v[u][i],u));
    return ret;
}
int main()
{
    int t,n;
    while(scanf("%d",&t)!=EOF){
        int ret=0,cnt=0;
        while(t--){
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
                v[i].clear();
            for(int i=1; i<n; i++){
                int x,y;
                scanf("%d%d",&x,&y);
                v[x].push_back(y);
                v[y].push_back(x);
            }
            int s=get_sg(1,-1);
            if(s>1)
                cnt++;
            ret^=s;
        }
        if(cnt==0){
            if(ret) puts("QQ");
            else puts("PP");
        }
        else{
            if(ret) puts("PP");
            else puts("QQ");
        }
    }
    return 0;
}
