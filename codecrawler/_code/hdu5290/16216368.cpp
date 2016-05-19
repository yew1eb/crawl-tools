#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#pragma comment(linker, "/STACK:102400000,102400000")//C++
using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399;
const int MAXINT = 0x7fffffff;
const int MAXSIZE = 100000 + 5;


int arr[MAXSIZE];
int w = 0;
int n;
vector<int> e[MAXSIZE];
int F[MAXSIZE][110],G[MAXSIZE][110];
int p[MAXSIZE][110],q[MAXSIZE][110];

void update(int x, int fa){
    for (int i=0;i<e[x].size();++i){
        if (e[x][i] != fa){
            update(e[x][i],x);
        }
    }

    if (e[x].size() == 1){
        G[x][0] = 0;
        F[x][arr[x]] = 1;
        return;
    }

    for (int i=0;i<e[x].size();++i){
        if (e[x][i] == fa) continue;
        p[e[x][i]][0] = F[e[x][i]][0];
        q[e[x][i]][0] = G[e[x][i]][0];
        for (int j=1;j<109;++j){
            p[e[x][i]][j] = min(p[e[x][i]][j-1],F[e[x][i]][j]);
            q[e[x][i]][j] = min(q[e[x][i]][j-1],G[e[x][i]][j]);
        }
    }


    for (int j=0;j<109;++j){
        for (int k=0;k<e[x].size();++k){
            if (e[x][k] == fa) continue;
            if (F[e[x][k]][j+1] == 0x01010101) continue;
            int f = F[e[x][k]][j+1];
            for (int i=0;i<e[x].size();++i){
                if (i == k || e[x][i] == fa) continue;
                if (j!=0) f += min(p[e[x][i]][j+1], q[e[x][i]][j-1]);
                else f += p[e[x][i]][j+1];
            }
            F[x][j] = min(F[x][j], f);
        }
    }

    int g=0;
    for (int k=0;k<e[x].size();++k){
        if (e[x][k] == fa) continue;
        g += F[e[x][k]][0];
    }
    G[x][0] = min(G[x][0], g);

    for (int j=1;j<109;++j){
        for (int k=0;k<e[x].size();++k){
            if (e[x][k] == fa) continue;
            if (G[e[x][k]][j-1] == 0x01010101) continue;
            int g = G[e[x][k]][j-1];
            for (int i=0;i<e[x].size();++i){
                if (i == k || e[x][i] == fa) continue;
                g += min(p[e[x][i]][j], q[e[x][i]][j-1]);
        }
            G[x][j] = min(G[x][j], g);
        }
    }

    int f = 1;
    for (int i=0;i<e[x].size();++i){
        if (e[x][i] == fa) continue;
        if (arr[x]!=0) f += min(p[e[x][i]][arr[x]+1], q[e[x][i]][arr[x]-1]);
        else f += p[e[x][i]][arr[x]+1];
    }
    F[x][arr[x]] = min(F[x][arr[x]], f);

    //cout<<x<<endl;
    //cout<<F[x][0]<<" "<<F[x][1]<<" "<<F[x][2]<<" "<<G[x][0]<<" "<<G[x][1]<<" "<<G[x][2]<<" "<<endl;
    //cout<<"done "<<x<<" "<<fa<<endl;
    return;
}

int main(){
    while (scanf("%d",&n)!=EOF){
        for (int i=1;i<=n;++i) e[i].clear();
        memset(arr,0,sizeof(arr));
        memset(F,0x1,sizeof(F));
        memset(G,0x1,sizeof(G));
        memset(p,0x1,sizeof(p));
        memset(q,0x1,sizeof(q));

        for (int i=1;i<=n;++i){
            scanf("%d",arr+i);
        }
        e[1].push_back(0);
        for (int i=1;i<n;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }

        update(1,0);

        int ans=MAXINT;
        for (int i=0;i<109;++i){
            ans = min(ans, F[1][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
