#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define maxn 200000
int lc[maxn],rc[maxn],size[maxn];
int cnt;
void init(){
    lc[0] = rc[0] = size[0] = 0;
    cnt = 1;
}
void build(int u,int l,int r){
    lc[u] = rc[u] = size[u] = 0;
    if(l == r) return ;
    lc[u] = cnt++;
    rc[u] = cnt++;
    build(lc[u],l,(l+r)/2);
    build(rc[u],(l+r)/2+1,r);
}
vector<int>head[maxn];

void add(int u,int l,int r,int p,int id){
    if(l == r){
        size[u]++;
        head[l].push_back(id);
        return ;
    }
    int mid = (l+r)/2;
    if(p > mid)
        add(rc[u],mid+1,r,p,id);
    else
        add(lc[u],l,mid,p,id);
    size[u]++;
}
struct Point{
    int x,y,r;
};
Point p[maxn];
int isin(Point a,Point b){
    int x = a.x-b.x;
    int y = a.y-b.y;
    if(x*x+y*y<=b.r*b.r) return 1;
    return 0;
}
vector<int> edge[maxn];
int in[maxn];
void query(int u,int l,int r,int id){
    if(size[u] < 0) return;
    if(l > p[id].x+p[id].r) return;
    if(r < p[id].x-p[id].r) return;
    if(l == r){
        for(int  i = 0;i < head[l].size();i++){
            int u = head[l][i];
            if(isin(p[u],p[id])){
                edge[id].push_back(u);
                in[u]++;
                head[l][i] = head[l][head[l].size()-1];
                head[l].pop_back();
                i--;
            }
        }
        return ;
    }
    int mid = (l+r)/2;
    query(lc[u],l,mid,id);
    query(rc[u],mid+1,r,id);
    size[u] = size[rc[u]]+size[lc[u]];
}
int comp(Point a,Point b){
    return a.r < b.r;
}

int dfs(int u){
    int ans = 0;
    for(int i = 0;i < edge[u].size();i++){
        ans ^= (dfs(edge[u][i])+1);
    }
    return ans;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n; i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].r);
            p[i].x += 20000;
            p[i].y += 20000;
        }
        init();
        cnt++;
        build(1,0,40000);
        sort(p,p+n,comp);
        memset(in,0,sizeof(in));
        for(int i = 0;i < maxn; i++){
            head[i].clear();
            edge[i].clear();
        }
        for(int i = 0;i < n; i++){
            query(1,0,40000,i);
              add(1,0,40000,p[i].x,i);
        }
        int ans = 0;
        for(int i = 0;i < n; i++){
            if(in[i] == 0){
                int u = dfs(i);
                ans ^=(u+1);
            }
        }
        if(ans == 0)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
    return 0;
}
