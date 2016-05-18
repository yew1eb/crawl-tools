#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 300 + 5;
const int INF = 100000 + 5;

int from[maxn],to[maxn];
int col[20];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++) scanf("%d%d",&from[i],&to[i]);
        int ans = m;
        for(int i = 0;i < (1 << n);i++){
            int tem = i;
            for(int j = 0;j < n;j++){
                col[j] = tem%2;
                tem /= 2;
            }
            int sum = 0;
            for(int j = 0;j < m;j++){
                int x = from[j];
                int y = to[j];
                if(col[x] == col[y]) sum++;
            }
            ans = min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}