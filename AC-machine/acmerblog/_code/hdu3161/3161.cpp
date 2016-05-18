#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010100;
const int INF = 0x3f3f3f3f;
int n,m,tot;
struct Hash {
        struct Node {int v; int id; Node *next;};
        int mod;
        Node *table[5555],memo[N];
        void init() {
                tot = 0;
                mod = 5501;
                memset(table,0,sizeof(table));
        }
        int operator [] (int x) {
                int idx = x%mod;
                for (Node *i = table[idx]; i ; i = i->next)
                        if (x==i->v) return i->id;
                memo[tot] = (Node) {x,tot,table[idx]};
                table[idx] = &memo[tot];
                return tot ++;
        }
}hash;
char s[55][55];
int mat[55][55][2],f[2][N],*cur,*nex;
int tomin(int &a,int b) { if (a>b)a=b; }
int work() {
        for (int i = 0; i < 2*n+1; i ++)
                for (int j = 0; j < 2*m+1; j ++)
                        if (s[i][j]=='#') s[i][j] = '0';
        for (int i = 0; i < n; i ++)
                for (int j = 0; j < m; j ++) {
                        mat[i][j][0] = s[i*2+1][j*2+2]-'0';
                        mat[i][j][1] = s[i*2+2][j*2+1]-'0';
                }
        cur = f[0]; nex = f[1];
        memset(f,INF,sizeof(f));
        hash.init();
        cur[hash[0]] = 0;

        for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                        for (int st = 0; st < tot; st ++) if (cur[st]!=INF) {
                                int v = hash.memo[st].v;
                                int a = v>>m>>m&3;
                                int b = v>>j>>j&3;

                                if (!a && !b) {
                                        if (j!=m-1) 
                                                tomin(nex[hash[v^2<<m<<m^1<<j<<j]],cur[st]+mat[i][j][0]+mat[i][j][1]);
                                } else if (!a && b) {
                                        tomin(nex[st],cur[st]+mat[i][j][1]);
                                        if (j!=m-1)
                                                tomin(nex[hash[v^b<<m<<m^b<<j<<j]],cur[st]+mat[i][j][0]);
                                } else if (a && !b) {
                                        if (j!=m-1)
                                                tomin(nex[st],cur[st]+mat[i][j][0]);
                                        tomin(nex[hash[v^a<<m<<m^a<<j<<j]],cur[st]+mat[i][j][1]);
                                } else if (a && b) {
                                        int k,cnt;
                                        if (a==1 && b==1) {
                                                for (k = j+1,cnt = 0; k < m; k ++) {
                                                        int vp = v>>k>>k&3;
                                                        if (vp==1) cnt ++;
                                                        else if (vp==2) cnt --;
                                                        if (cnt==-1) break;
                                                }
                                                tomin(nex[hash[v^a<<m<<m^b<<j<<j^3<<k<<k]],cur[st]);
                                        } else if (a==2 && b==2) {
                                                for (k = j-1,cnt = 0; k >= 0; k --) {
                                                        int vp = v>>k>>k&3;
                                                        if (vp==1) cnt ++;
                                                        else if (vp==2) cnt --;
                                                        if (cnt==1) break;
                                                }
                                                tomin(nex[hash[v^a<<m<<m^b<<j<<j^3<<k<<k]],cur[st]);
                                        } else if (a==2 && b==1) {
                                                tomin(nex[hash[v^a<<m<<m^b<<j<<j]],cur[st]);
                                        } else if (a==1 && b==2) {
                                                if (i==n-1 && j==m-1)
                                                        tomin(nex[hash[v^a<<m<<m^b<<j<<j]],cur[st]);
                                        }
                                }
                        }
                        swap(cur,nex);
                        for (int k = 0; k < tot; k ++) nex[k] = INF;
                }
        }
        return cur[0];
}
int main() {
        int cas;
        scanf("%d",&cas);
        while (cas--) {
                scanf("%d%d\n",&n,&m);
                for (int i = 0; i < 2*n+1; i ++) 
                        gets(s[i]);
                printf("%d\n",work());
        }
        return 0;
}