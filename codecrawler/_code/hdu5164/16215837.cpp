#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<map>
#include<set>
using namespace std;

int n, m;
int a[100010], b[300010];
int kind;
long long ans;

struct Tree{
    map<int, Tree* >next;
    vector<int>v;
    Tree *fail;
    int cnt;
    Tree(){
        next.clear();
        v.clear();
        cnt = 0;
        fail = NULL;
    }
};
vector<int>e;
Tree *root;
struct node{
    int x,y;
    bool operator < (const node &p)const{
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator == (const node &p)const{
        return x == p.x && y == p.y;
    }
    node(int x = 0, int y = 0):x(x), y(y) {}
};
node alice[100010];
vector<node>idx;

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}
node deal_gcd(int x, int y){
    int r = gcd(x, y);
    x /= r;
    y /= r;
    return node(x, y);
}

void tree_add(){
    Tree *p = root;
    for(int i = 0; i < e.size(); i++){
        if(p->next[e[i]] == NULL){
            p->v.push_back(e[i]);
            p->next[e[i]] = new Tree();
        }
        p = p->next[e[i]];
    }
    p->cnt ++;
}
bool march(node p, node q){
    if(p == q) return 1;
    else return 0;
}
void deal_init_bob(){
    int len;
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
        scanf("%d", &b[i]);

    if(len > n) return;
    if(len == 1){
        ans += n;
        return ;
    }

    e.clear();

    for(int i = 1; i < len; i++){
        node tp =deal_gcd(b[i], b[i - 1]);
        int id = lower_bound(idx.begin(), idx.end(), tp) - idx.begin();
        if(id >=idx.size() || march(tp, idx[id]) == 0) return ;
        e.push_back(id);
    }
    tree_add();
}

void deal_init(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    idx.clear();
    for(int i = 1; i < n; i++){
        alice[i] = deal_gcd(a[i], a[i - 1]);
//        printf("alice[%d] = %d %d\n",i, alice[i].x, alice[i].y);
        idx.push_back(alice[i]);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
//    for(int i = 0; i < idx.size(); i++)
//        printf("i = %d, x=%d, y= %d\n", i, idx[i].x, idx[i].y);

    for(int i = 1; i < n; i++)
        a[i] = lower_bound(idx.begin(), idx.end(), alice[i]) - idx.begin();

    while(m--){
        deal_init_bob();
    }
}

void tree_AC(){
    root->fail = NULL;
    queue<Tree *>que;
    for(int i = 0; i < root->v.size(); i++){
        int x = root->v[i];
        Tree *tp = root->next[x];
        tp->fail = root;
        que.push(tp);
    }
    while(!que.empty()){
        Tree *res = que.front(); que.pop();
        for(int i = 0; i < res->v.size(); i++){
            int x = res->v[i];
            Tree *p = res;
            while(p->fail != NULL){
                p = p->fail;
                if(p->next[x]){
                    p = p->next[x];
                    break;
                }
            }

            res->next[x]->fail = p;
            que.push(res->next[x]);
        }
    }
}
void work(){
    Tree *p = root;
    for(int i = 1; i < n; i++){
        while(p!= root && p->next[a[i]] == NULL) p = p->fail;
        Tree *res = p->next[a[i]];
        if(res == NULL) continue;
        p = res;
        while(res != root){
            ans += res->cnt;
            res = res->fail;

        }
    }
    cout << ans << endl;
}

void debug(){
    queue<Tree *>que;
    que.push(root);
    while(!que.empty()){
        Tree *res = que.front(); que.pop();
        for(int i = 0; i < res->v.size(); i++){
            int x = res->v[i];
            que.push(res->next[x]);
        }
    }
}
int main()
{

//    freopen("in.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        root = new Tree();
        ans = 0;
        deal_init();
        tree_AC();
        work();
//        debug();
    }

    return 0;
}


