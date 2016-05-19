#include "stdio.h"
#include "string.h"
#include "math.h"
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1003005
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b
#define abs(a)  a < 0 ? a : (-a)
#define Mem(a,b) memset(a,b,sizeof(a))
int Mod = 1000000007;
double pi = acos(-1.0);
double eps = 1e-6;

typedef struct{
    int f,t,w,next;
}Edge;
Edge edge[MAX];
int head[1005];
int dist[1005];
bool visit[1005];
int kNum;

void addEdge(int f, int t, int w)
{
    edge[kNum].f = f;
    edge[kNum].t = t;
    edge[kNum].w = w;
    edge[kNum].next = head[f];
    head[f] = kNum ++;
}

__int64 gcd(__int64 x, __int64 y)
{
    return y == 0 ? x : gcd(y, x % y);
}

typedef struct{
    __int64 x,y;
}Node;
Node node[1005];
int T,n;
__int64 L;

typedef struct{
    int flag;
}KKK;
KKK kk[1005];

bool comp(KKK a, KKK b)
{
    if( node[a.flag].x == node[b.flag].x )
        return node[a.flag].y < node[b.flag].y;
    return node[a.flag].x < node[b.flag].x;
}

void work()
{
    for(int k = head[0]; k != -1; k = edge[k].next )
        dist[edge[k].t] = edge[k].w;
    visit[0] = true;

    for(int i = 0; i <= n; i ++){
        int t = -1, minV = 50000;
        for(int j = 1; j <= n + 1; j ++){
            if( !visit[j] && minV > dist[j]){
                minV = dist[j];
                t = j;
            }
        }
        if( t == -1 ) break;
//        if( dist[t] == 50000 ) break;
        if( t == n + 1 ) break;
        visit[t] = true;

        for(int k = head[t]; k != -1; k = edge[k].next){
            if( !visit[edge[k].t] && dist[edge[k].t] > dist[t] + edge[k].w){
                dist[edge[k].t] = dist[t] + edge[k].w;
            }
        }

    }

    if( dist[n+1] == 50000 ){
        printf("impossible\n");
    }
    else{
        printf("%d\n",dist[n+1] - 1);
    }
}


void solve()
{
    cin>>node[0].x>>node[0].y;
    cin>>node[n+1].x>>node[n+1].y;

    for(int i = 1; i <= n; i ++){
        cin>>node[i].x>>node[i].y;
    }

    for(int i = 0; i <= n + 1; i ++)
        kk[i].flag = i;

    sort(kk,kk+n+2,comp);

    Mem(head,-1);
    Mem(visit,false);
    fill(dist, dist + 1003, 50000);
    kNum = 0;

    map<__int64,int> ss;
    for(int i = 0; i <= n; i ++){
        int ii = kk[i].flag;
        ss.clear();
        bool flag1 = true;
        bool flag2 = true;
        for(int j = i + 1; j <= n + 1; j ++){
            int jj = kk[j].flag;
            if( ( node[ii].x - node[jj].x ) * ( node[ii].x - node[jj].x ) + ( node[ii].y - node[jj].y ) * ( node[ii].y - node[jj].y ) <= L * L ){
                //å¤çå»ºè¾¹
                __int64 t = ( node[ii].x - node[jj].x ), z = ( node[ii].y - node[jj].y );
                if( t == 0 && flag1 ){
                    addEdge(ii,jj,1);
                    addEdge(jj,ii,1);
                    flag1 = false;
                    continue;
                }
                if( z == 0 && flag2 ){
                    addEdge(ii,jj,1);
                    addEdge(jj,ii,1);
                    flag2 = false;
                    continue;
                }
                if( t == 0 || z == 0 ) continue;


                //æ±æç
                __int64 x = abs(t), y = abs(z);
                if( abs(t) < abs(z) ){
                    x = z;
                    y = t;
                }

                __int64 g = gcd(x,y);
                x /= g, y /= g;

                if( x < 0 ){
                    x *= -1, y *= -1;
                }

                if( !ss.count(x*100001+y) ){
                    addEdge(ii,jj,1);
                    addEdge(jj,ii,1);
                    ss[x*100001+y] = 1;
                }
            }
        }
    }

    work();

}



int main()
{
//    freopen("d:\\test.txt", "r", stdin);

    while( cin>>T ){
        while( T -- ){
            cin>>n>>L;
            solve();
        }
    }

    return 0;
}

