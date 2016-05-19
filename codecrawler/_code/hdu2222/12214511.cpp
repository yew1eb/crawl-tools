/*
 * Author: yew1eb
 * Created Time:  2014Äê11ÔÂ03ÈÕ ÐÇÆÚÒ» 20Ê±24·Ö58Ãë
 * File Name: hdu2222.cpp
 */
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int inf = 0x7fffffff;
const ll  INF = 1e18;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int maxv = 500010;
struct Trie{
    int next[maxv][26], fail[maxv], end[maxv];
    int qu[maxv];
    int root, L;
    int newnode(){
        memset(next[L], -1, sizeof next[L] );
        end[L++] = 0;
        return L-1;
    }
    void init(){
        L = 0;
        root =newnode();
    }
    void insert(char buf[]){
        int len = strlen(buf);
        int now = root;
        for(int i=0; i<len; ++i){
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build(){
        int head = 0, tail = 0;
        fail[root] = root;
        for(int i=0; i<26; ++i)
            if(next[root][i] == -1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                qu[tail++] = next[root][i];
            }
        while(head<tail){
            int now =qu[head++];
            for(int i=0; i<26; ++i)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    qu[tail++] = next[now][i];
                }
        }
    }
    int query(char buf[]){
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i=0; i<len; ++i){
            now = next[now][buf[i]-'a'];
            int temp = now;
            while(temp != root){
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug(){
        for(int i=0; i<L; ++i){
            printf("id = %3d, fail = %3d, end = %3d, chi = [",i,fail[i],end[i]);
            for(int j=0; j<26; ++j)
                printf("%2d", next[i][j]);
            printf("\n");
        }
    }
};

char buf[1000010];
Trie ac;

int main(){
    int T, n;
    char s[55];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        ac.init();
        for(int i=0; i<n; ++i){
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.query(buf));
    }
    return 0;
}