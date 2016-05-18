#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>

using namespace std;
const int maxn=1000+10;
const __int64 inf=100000000002;

__int64 L1,L2,L3,L4,C1,C2,C3,C4;
__int64 map[maxn][maxn];
__int64 d[maxn];

int main(){
    int T; cin>>T;
    int cas=1;
    while(T--){
        cin>>L1>>L2>>L3>>L4>>C1>>C2>>C3>>C4;
        int n,m; cin>>n>>m;
        ///初始化
        for(int i=1;i<=n;++i){
            cin>>d[i];
            map[i][i]=0;
            for(int j=1;j<i;++j){
                __int64 s=max(d[i],d[j])-min(d[i],d[j]),v;
                if(s>L4) v=inf;
                else if(s>L3) v=C4;
                else if(s>L2) v=C3;
                else if(s>L1) v=C2;
                else if(s>0)  v=C1;
                else v=0;
                map[i][j]=map[j][i]=v;
            }
        }
        ///floyd算法
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);

        printf("Case %d:\n",cas++);
        while(m--){
            int x,y; cin>>x>>y;
            if(map[x][y]==inf)printf("Station %d and station %d are not attainable.\n",x,y);
            else printf("The minimum cost between station %d and station %d is %I64d.\n",x,y,map[x][y]);
        }
    }
    return 0;
}