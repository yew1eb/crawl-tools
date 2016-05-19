#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define mod 20090717
#define pb push_back
#define lowbit(x) ((x)&(-x))
struct node{
    int son[26],fail;
    int cnt;//二进制状态,标记包括自己和前面,有哪些给定字串
    node(){memset(son,0,sizeof(son));fail=0;cnt=0;}
};
vector<node> ac;
int hash[256];
int dp[30][1<<11][110];
int n,m,K;
int map[1<<11];//预处理出二进制数中1的个数

void init() {
    memset(map,0,sizeof(map));
    for(int i=0;i<(1<<10);++i) {
        map[i]=map[i>>1]+(i&1);
    }
    for(int i=0;i<26;++i) hash['a'+i]=i;
}

void insert(const char *str,int num) {
    int p=0,i=0;
    while(str[p]) {
        if(!ac[i].son[hash[str[p]]]) {
            ac[i].son[hash[str[p]]]=ac.size();
            ac.pb(node());
        }
        i=ac[i].son[hash[str[p]]];
        ++p;
    }
    ac[i].cnt=1<<num;
}

void getFail() {
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()) {
        int cur=qu.front();qu.pop();
        for(int i=0;i<26;++i) {
            int nex=ac[cur].son[i];
            int p=ac[cur].fail;
//            while(~p&&!ac[p].son[i]) p=ac[p].son[i];//这部没必要,浅层节点必有儿子
            if(nex) {
                qu.push(nex);
                if(~p) ac[nex].fail=ac[p].son[i],ac[nex].cnt|=ac[ac[p].son[i]].cnt;
                else ac[nex].fail=0;
            }
            else {
                if(~p) ac[cur].son[i]=ac[p].son[i];//空儿子不是指向根,就是指向实儿子
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    while(cin >> n >> m >> K,n||m||K) {
        ac.clear();
        ac.pb(node());
        ac[0].fail=-1;
        for(int i=0;i<m;++i) {
            char str[20];
            cin >> str;
            insert(str,i);
        }
        getFail();
//        memset(dp,0,sizeof(dp));//dp数组太大,全部清0太耗时
        for(int i=0;i<=n;++i)
            for(int j=0;j<(1<<m);++j)
                for(int k=0;k<ac.size();++k)
                    dp[i][j][k]=0;
        dp[0][0][0]=1;
        int ans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<(1<<m);++j)
                for(int k=0;k<ac.size();++k) {
                    if(!dp[i][j][k]) continue;
                    for(int p=0;p<26;++p) {
                        int spos=ac[k].son[p],sta=j|ac[spos].cnt;
                        dp[i+1][sta][spos]+=dp[i][j][k];
                        dp[i+1][sta][spos]%=mod;
                    }
                }
        for(int i=0;i<(1<<m);++i)
            for(int j=0;j<ac.size();++j)
                if(map[i]>=K) {ans+=dp[n][i][j];ans%=mod;}//这里不要忘记取模
        cout << ans << endl;
    }
    return 0;
}