#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof((a)))

void RI (int& x){
    x = 0;
    char c = getchar ();
    while (c == ' '||c == '\n')    c = getchar ();
    bool flag = 1;
    if (c == '-'){
        flag = 0;
        c = getchar ();
    }
    while (c >= '0' && c <= '9'){
        x = x * 10 + c - '0';
        c = getchar ();
    }
    if (!flag)    x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}

const int MAXN = 20;
const int inf = 0x3f3f3f3f;
int mm[MAXN][MAXN];
int dis[20][(1<<MAXN)];
struct Node{
    int s,now;
};
int main(){
    int T;
    RI(T);
    while(T --){
        int n,m;
        RII(n,m);
        mem(mm,inf);
        while(m --){
            int a,b,c;
            RIII(a,b,c);
            mm[a][b] = mm[b][a] = min(mm[a][b],c);
        }

        if(n == 1){
            cout<<0<<endl;
            continue;
        }

        for(int k = 1;k <= n;k ++){
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= n;j ++){
                    mm[i][j] = min(mm[i][k] + mm[k][j],mm[i][j]);
                }
            }
        }
        for(int i = 1;i <= n;i ++)mm[i][i] = 0;

        mem(dis,inf);
        dis[1][1] = 0;
        int ans = inf;
        for(int i = 1;i < (1<<n);i ++){//zhuang tai
            for(int j = 1;j <= n;j ++){//qi dian
                if((i&(1<<(j-1)))){//you qi dian
                    for(int k = 1;k <= n;k ++){//zhong dian
                        if((i&(1<<(k-1))) == 0){
                            int to = (i | (1<<(k-1)));
                            dis[k][to] = min(dis[k][to],dis[j][i] + mm[j][k]);
                            //cout<<k<<' '<<to<<' '<<dis[k][to]<<endl;
                        }
                    }
                }
            }
        }

        for(int i = 2;i <= n;i ++){
            ans = min(ans,dis[i][(1<<n)-1]+mm[i][1]);
            //cout<<dis[i][(1<<n)-1]<<' ';
        }
        cout<<ans<<endl;
    }
    return 0;
}
