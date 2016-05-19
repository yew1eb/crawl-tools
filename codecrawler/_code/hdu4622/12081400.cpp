#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int HASH = 10007;
const int MAXN = 2010;
struct HASHMAP{
    int head[HASH], next[MAXN], size;
    ull state[MAXN];
    int f[MAXN];
    void init(){
        size = 0;
        memset(head, -1, sizeof head );
    }
    int insert(ull val, int _id){
        int h = val % HASH;
        for(int i=head[h]; ~i; i=next[i])
            if(val == state[i]){
                int tmp = f[i];
                f[i] = _id;
                return tmp;
            }
        f[size] = _id;
        state[size] = val;
        next[size] = head[h];
        head[h] = size++;
        return 0;
    }
}H;    

const int SEED = 13331;
ull base[MAXN];
ull S[MAXN];
char str[MAXN];
int ans[MAXN][MAXN];
int main(){
    //freopen("in.txt","r", stdin);
    base[0] = 1;
    for(int i=1; i<MAXN; ++i)
        base[i] = base[i-1]*SEED;
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        int n = strlen(str);
        S[0] = 0;
        for(int i=1; i<=n; ++i)
            S[i] = S[i-1]*SEED + str[i-1];
        memset(ans, 0, sizeof ans );
        for(int L=1; L<=n; ++L){
            H.init();
            for(int i=1; i+L-1<=n; ++i){
                int l = H.insert(S[i+L-1]-S[i-1]*base[L], i);
                ans[i][i+L-1]++;
                ans[l][i+L-1]--;
            }
        }
        for(int i=n; i>=0; --i)
            for(int j=i; j<=n; ++j)
                ans[i][j] += ans[i+1][j] + ans[i][j-1] - ans[i+1][j-1];
        int m, u, v;
        scanf("%d", &m);
        while(m--){
            scanf("%d%d", &u, &v);
            printf("%d\n", ans[u][v]);
        }
    }
    return 0;
}

