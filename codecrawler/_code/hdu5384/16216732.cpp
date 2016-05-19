#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500010;
const int maxd = 26;
struct Trie{
    int next[maxn][maxd],fail[maxn],end[maxn];
    int root,L;
    int num[101000];
    int newnode(){
        for(int i = 0;i < maxd;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init(){
        L = 0;
        root = newnode();
        memset(num,0,sizeof(num));
    }
    void insert(char s[]){
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++){
            if(next[now][s[i] - 'a'] == -1)
                next[now][s[i] - 'a'] = newnode();
            now = next[now][s[i] - 'a'];
        }
        end[now] ++;
    }
    void build(){
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < maxd;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < maxd;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void query(string &buf,int id){
        int len = buf.size();
        int now = root;
        for(int i = 0;i < len; i++){
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while(temp != root){
                num[id] += end[temp];
                temp = fail[temp];
            }
        }
    }
};
Trie ac;
char cstr[maxn];
vector<string>_find;
string _str;
int main(){
    int n,m;
    int T;
    scanf("%d",&T);
    while(T--){
        ac.init();
        scanf("%d%d",&n,&m);
        _find.clear();
        for(int i = 1; i <= n; i++){
            cin >> _str;
            _find.push_back(_str);
        }
        for(int i = 1; i <= m; i++){
            scanf("%s",cstr);
            ac.insert(cstr);
        }
        ac.build();
        for(int i = 0; i < n; i++)
            ac.query(_find[i],i);
        for(int i = 0; i < n; i++)
            printf("%d\n",ac.num[i]);
    }
    return 0;
}
