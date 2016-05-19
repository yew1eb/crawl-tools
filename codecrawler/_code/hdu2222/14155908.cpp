#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 523333;
struct AC_Automata { //AhoCorasickAutomata
    int next[MAXN][26], fail[MAXN], end[MAXN];
    int root, L;
    int newnode() {
        for(int i=0; i<26; ++i)
            next[L][i] = -1;
        end[L] = 0;
        return L++;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) {//Trie
        int len = strlen(buf);
        int now = root;
        for(int i=0; i<len; ++i) {
            if(next[now][buf[i]-'a'] == -1) 
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build() { //getFail
        queue<int> Q;
        fail[root] = root;
        for(int i=0; i<26; ++i)
            if(next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() ) {
            int now = Q.front();
            Q.pop();
            for(int i=0; i<26; ++i)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i=0; i<len; ++i) {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while ( temp != root ) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};


char buf[MAXN*2];
AC_Automata ac;
int main() {
    int T;
    int n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ac.init();
        for(int i=0; i<n; ++i) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.query(buf));
    }
    return 0;
}
