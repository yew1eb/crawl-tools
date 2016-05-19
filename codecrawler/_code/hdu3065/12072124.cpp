/*
 * Author: yew1eb
 * Created Time:  2014Äê11ÔÂ04ÈÕ ÐÇÆÚ¶þ 13Ê±55·Ö45Ãë
 * File Name: hdu3065.cpp
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

int sum[1005];
struct Trie{
    int next[maxv][26], fail[maxv], end[maxv];
    int root, L;
    int newnode(){
        for(int i=0; i<26; ++i)
            next[L][i] = -1;
        end[L] = -1;
        return L++;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(char buf[], int id){
        int len = strlen(buf);
        int now = root;
        for(int i=0; i<len; ++i){
            if(next[now][buf[i]-'A']==-1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now] = id;
    }
    void build(){
        queue<int> Q;
        fail[root] = root;
        for(int i=0; i<26; ++i)
            if(next[root][i]==-1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int i=0; i<26; ++i)
                if(next[now][i]==-1)
                    next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void query(char buf[]){
        int len = strlen(buf);
        int now = root;
        memset(sum, 0, sizeof sum );
        for(int i=0; i<len; ++i){
            if(buf[i]<'A' || buf[i]>'Z'){
                now = root;
                continue;
            }
            now = next[now][buf[i]-'A'];
            int temp = now;
            while(temp!=root){
                if(end[temp]!=-1)
                    sum[end[temp]]++;
                temp = fail[temp];
            }
        }
    }
};

char buf[2000010];
char ss[1005][60];
Trie ac;
int main() {
//    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d", &n)){
        ac.init();
        for(int i=0; i<n; ++i){
            scanf("%s", ss[i]);
            ac.insert(ss[i], i);
        }
        ac.build();
        scanf("%s", buf);    
        ac.query(buf);
        for(int i=0; i<n; ++i) if(sum[i]) {
            printf("%s: %d\n", ss[i], sum[i]);
        }
    }
    return 0;
}

