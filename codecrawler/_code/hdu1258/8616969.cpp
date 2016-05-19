
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define N 20
int t, n;
int a[N];
int list[N];
bool vis[N];
set<string> s;
bool flag;

void dfs(int k, int sum) {
    int i;
    if(k>=n || sum<0) return;
    if(sum==0) {
        string str;
        for(i=0; i<k; i++)
        {
            str +=(list[i]/10) +'0';
            str +=(list[i]%10) +'0';
        }
        if(s.find(str)==s.end())
        {
            s.insert(str);
            flag = 1;
            for(i=0; i<k-1; i++)
                printf("%d+",list[i]);
            printf("%d\n",list[i]);
        }
        return ;
    }
    for(i=k; i<n; i++)
        if(!vis[i]&&(k==0||a[i]<=list[k-1])) {
            vis[i] = 1;
            list[k] = a[i];
            dfs(k+1,sum-a[i]);
            vis[i] = 0;
        }
}
int main() {
    int i;
    while(scanf("%d%d",&t,&n),t+n) {
        for(i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        memset(vis,0,sizeof(vis));
        printf("Sums of %d:\n",t);
        flag = false;
        s.clear();
        dfs(0,t);
        if(!flag) printf("NONE\n");
    }
    return 0;
}
