#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int maxn = 2000000 + 5;
const int INF = 1000000000;

int cnt;
int fa[maxn],id[maxn];

int Find(int x){return fa[x]==x?fa[x]:fa[x]=Find(fa[x]);}
set<int> S;

int main(){
    int n,m;
    int kase = 0;
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0) break;
        kase++;
        cnt = n;
        for(int i = 0;i < maxn;i++) fa[i] = i;
        for(int i = 0;i < n;i++) id[i] = i;
        while(m--){
            char s[5];
            int a,b;
            scanf("%s",s);
            if(s[0] == 'M'){
                scanf("%d%d",&a,&b);
                int X = Find(id[a]);
                int Y = Find(id[b]);
                if(X != Y) fa[X] = Y;
            }
            else{
                scanf("%d",&a);
                id[a] = cnt++;
            }
        }
        S.clear();
        for(int i = 0;i < n;i++){
            S.insert(Find(id[i]));
        }
        printf("Case #%d: %d\n",kase,S.size());
    }
    return 0;
}
