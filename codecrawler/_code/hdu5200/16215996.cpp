#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define N 50010
int vis[N];

typedef struct node{
     int val;
     int index;
};

typedef struct Q{
     int val;
     int index;
     int ans;
};

node ele[N];
Q q[N];
bool cmp(node a,node b){
     return a.val < b.val;
}

bool cmp1(Q a,Q b){
     return a.val < b.val;
}

bool cmp2(Q a,Q b){
     return a.index < b.index;
}

int judge(int j){
    if(vis[j] == -1) return 0;
    if(vis[j] == 0){
        vis[j] = -1;
        vis[j-1] = 1;
        vis[j+1] = 1;
        return 1;
    }
    if(vis[j] == 1){
      if((vis[j-1] == 0||vis[j-1] == 1)&&vis[j+1] == -1){
        vis[j] = -1;
        vis[j-1] = 1;
        return 0;
      }
      if(vis[j-1] == -1&&(vis[j+1] == 0||vis[j+1] == 1)){
        vis[j] = -1;
        vis[j+1] = 1;
        return 0;
      }
      vis[j] = -1;
      return -1;
    }
}

int main(){
    int n,m,j;
    while(~scanf("%d%d",&n,&m)){
        int ans = 1;
        memset(vis,0,sizeof(vis));
        vis[1] = vis[n] = 1;
        vis[0] = vis[n+1] = -1;
        for(int i = 0;i < n; i++){
            scanf("%d",&ele[i].val);
            ele[i].index = i+1;
        }
        for(int i = 0;i < m; i++){
            scanf("%d",&q[i].val);
            q[i].index = i;
            q[i].ans = 0;
        }
        sort(ele,ele+n,cmp);
        sort(q,q+m,cmp1);
        j = 0;
        for(int i = 0;i < m; i++){
            int tmp = q[i].val;
            for(;j < n;j++){
                if(ele[j].val <= tmp){
                    ans += judge(ele[j].index);
                }
                else break;
            }
            q[i].ans = ans;
        }
        sort(q,q+m,cmp2);
        for(int i = 0; i < m;i++) printf("%d\n",q[i].ans);
    }
    return 0;
}
