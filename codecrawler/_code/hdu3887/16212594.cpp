#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

const int N = 100010;
struct ask{
    int lp,rp,value;
}aa[N];
struct dit{
    int id,num;
}dd[N];
int n,root,cnt[N],timeorder = 0;
bool vis[N];
vector<int> vv[N];
//void dfs(int x){
//    aa[x].lp = timeorder;
//    aa[x].value = x;
//    vis[x] = true;
//    for(int i = 0; i < vv[x].size(); ++i){
//        int y = vv[x][i];
//        if(!vis[y])
//           dfs(y);
//        vis[y] = true;
//    }
//    aa[x].rp = timeorder++;
//}
void dfs(int x){
    stack<int> ss;
    ss.push(x);
    while(!ss.empty()){
       int tt = ss.top();
       if(!vis[tt]){
         vis[tt] = true;
         aa[tt].lp = timeorder;
         aa[tt].value = tt;
       }
       bool flag = false;
       for(int i = 0; i < vv[tt].size(); ++i){
           int y = vv[tt][i];
           if(!vis[y]){
               ss.push(y);
               flag = true;
               break;
           }
       }
       if(flag) continue;
       if(vis[tt]){
         aa[tt].rp = timeorder++;
         ss.pop();
       }
    }
}
bool cmp1(ask a,ask b){
    return a.rp < b.rp;
}
bool cmp2(ask a,ask b){
    return a.value < b.value;
}
int inline lowbit(int x){
    return x & (-x);
}
int inline sum(int x){
    int s = 0;
    while(x > 0){
       s += cnt[x];
       x -= lowbit(x);
    }
    return s;
}
void inline update(int x){
    while(x < N){
        //printf("ss\n");
       cnt[x]++;
       x += lowbit(x);
    }
}
int main(){
    //freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&root) && (n + root)){
       memset(cnt,0,sizeof(cnt));
       memset(vv,0,sizeof(vv));
       memset(vis,0,sizeof(vis));     
       for(int i = 0; i < N; ++i){
          dd[i].id = dd[i].num = -1;
          aa[i].lp = aa[i].rp = aa[i].value = -1;
       }
       int x,y;
       for(int i = 1; i < n; ++i){
          scanf("%d%d",&x,&y);
          vv[x].push_back(y);
          vv[y].push_back(x);
       }
       timeorder = 1;
       dfs(root);
       sort(aa+1,aa+n+1,cmp1);
       for(int i = 1; i <= n; ++i){
           int x = aa[i].value;
          dd[x].id = i;
          dd[i].num = aa[i].value;
       }
       sort(aa+1,aa+n+1,cmp2);
       int ans[N] = {0};
       for(int i = 1; i <= n; ++i){
          ans[i] = sum(aa[i].rp) - sum(aa[i].lp - 1);
          update(dd[i].id);
       }
       for(int i = 1; i < n; ++i)
           printf("%d ",ans[i]);
       printf("%d\n",ans[n]);
    }
    return 0;
}