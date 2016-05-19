#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct Point{
    int x, y, h, type, id;//0ä¸ºå»ºç­ 1ä¸ºæ¥è¯¢ç¹
}p[60006];
int ans[30003];
struct Tnode{
    int a[11];
    int num;
}node[30006<<2];
int yy[30006];
priority_queue<int> q;

bool operator<(const Point &a, const Point &b){
    return a.x < b.x || a.x == b.x && a.y < b.y || a.x == b.x && a.y == b.y && a.type < b.type;
}

void inline _insert(int *first, int *last, int key){
    while(last > first && *(last-1) > key) {*last = *(last-1);last--;}
    *last = key;
}
void update(int rt, int l, int r, int y, int key){
    _insert(node[rt].a, node[rt].a+node[rt].num, key);
    if(node[rt].num < 10) node[rt].num++;
    if(l != r){
        int mid = l + r >> 1;
        if(y <= yy[mid]) update(rt<<1, l, mid, y, key);
        else update(rt<<1|1, mid+1, r, y, key);
    }
}


inline void add_queue(int rt, int k){
    for(int i = 0; i < node[rt].num; i++){
        q.push(node[rt].a[i]);
        if(q.size() > k) q.pop();
    }
}
void query(int rt, int l, int r, int y, int k){
    if(y < yy[l]) return;
    if(y >= yy[r]){
        add_queue(rt, k);
        return;
    }
    int mid = l + r >> 1;
    if(y <= yy[mid]) query(rt<<1, l, mid, y, k);
    else{
        query(rt<<1, l, mid, y, k);
        query(rt<<1|1, mid+1, r, y, k);
    }
}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        memset(node, 0, sizeof(node));
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].h);
            p[i].type = 0;
            yy[i] = p[i].y;
        }
        for(int i = n; i < m + n; i++){
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].h);
            p[i].type = 1;
            p[i].id = i - n;
        }
        sort(p, p + n + m);
        sort(yy, yy + n);
        int mm = unique(yy, yy + n) - yy;
        for(int i = 0; i < m + n; i++){
            if(p[i].type == 0){
                update(1, 0, mm-1, p[i].y, p[i].h);
            }else{
                while(!q.empty()) q.pop();
                query(1, 0, mm-1, p[i].y, p[i].h);
                if(q.size() == p[i].h) ans[p[i].id] = q.top();
                else ans[p[i].id] = -1;
            }
        }
        for(int i = 0; i < m; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
