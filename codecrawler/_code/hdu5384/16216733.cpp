#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define sss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a) memset(a,0,sizeof(a))
#define ss(a,b) scanf("%d%d",&a,&b)
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n", a)
#define INF 0x3f3f3f3f
#define w(a) while(a)
#define PI acos(-1.0)
#define LL long long
#define eps 10E-9
#define N 100010
#define mod 258280327
const int SIGMA_SIZE=26;
const int MAXN=100010;
const int MAXNODE=600010;
using namespace std;
void mys(int& res)
{
    int flag=0;
    char ch;
    while(!(((ch=getchar())>='0'&&ch<='9')||ch=='-'))
        if(ch==EOF)  res=INF;
    if(ch=='-')  flag=1;
    else if(ch>='0'&&ch<='9')  res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')  res=res*10+ch-'0';
    res=flag?-res:res;
}
void myp(int a)
{
    if(a>9)
        myp(a/10);
    putchar(a%10+'0');
}
/*************************THE END OF TEMPLATE************************/
char str1[N][10001];
char s[N];
int m, ans;
struct ac_trie{
        int next[500010][26], ed[500010], fail[500010];
        int root, L;
        int newnode(){
            for(int i=0; i<26; i++) next[L][i] = -1;
            ed[L++] = 0;
            return L-1;
        }
        void init(){
            L = 0;
            root = newnode();
        }
        void m_insert(char *s){
            int len = strlen(s);
            int now = root;
            for(int i = 0; i<len; i++){
                if(next[now][s[i]-'a'] == -1) next[now][s[i]-'a'] = newnode();
                now = next[now][s[i]-'a'];
            }
            ed[now]++;
        }
        void getfail(){
            queue<int>Q;
            fail[root] = root;
            for(int i=0; i<26; i++)
                if(next[root][i] == -1) next[root][i] = root;
                else{
                    fail[next[root][i]] = root;
                    Q.push(next[root][i]);
                }
            w(!Q.empty()){
                int now = Q.front();
                Q.pop();
                for(int i=0; i<26; i++){
                    if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                    else{
                        fail[next[now][i]] = next[fail[now]][i];
                        Q.push(next[now][i]);
                    }
                }
            }
        }
        int query(char *s){
            int len = strlen(s);
            int now = root;
            int res = 0;
            for(int i=0; i<len; i++){
                now = next[now][s[i]-'a'];
                int temp = now;
                w(temp!=root){
                   res += ed[temp];
                   //ed[temp] = 0;
                   temp = fail[temp];
                }
            }
            return res;
        }
};
ac_trie ac;
int main(){
    int t, n;
    s(t);
    w(t--){
         ss(n, m);
         ac.init();
         for(int i=0; i<n; i++) scanf("%s",str1[i]);
         for(int i=0; i<m; i++){
            scanf("%s", s);
            ac.m_insert(s);
         }
         ac.getfail();
         for(int i=0; i<n; i++)  p(ac.query(str1[i]));
    }
    return 0;
}
