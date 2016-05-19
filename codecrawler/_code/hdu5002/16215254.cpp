#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 111111;
const int INF = 1111111111;


int n, m;

class LCT {
private :
    struct node {
        int size, same, rev, val, inc;
        pair<int, int> value[2];
        node *child[2], *father;
        bool isRoot;
        inline void setChild(node *tmp, int dir) {
            child[dir] = tmp;
            tmp->father = this;
        }
        inline int isRc() {
            return father->child[1] == this;
        }
        
        int calc(int v) {
            int res = 0;
            if (val == v) {
                res++;
            }
            
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++) {
                    if (this->child[i]->value[j].first == v) {
                        res += this->child[i]->value[j].second;
                    }
                }
            return res;
        }
        
        inline void update() {
            if (size == 0) {
                return ;
            }
            int maxValue = max(val, max(child[0]->value[0].first, child[1]->value[0].first));
            value[0] = make_pair(maxValue, this->calc(maxValue));
            int sec = -INF;
            if (val != maxValue) {
                sec = max(sec, val);
            }
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++) {
                    if (this->child[i]->value[j].first != maxValue) {
                        sec = max(sec, this->child[i]->value[j].first);
                    }
                }
            value[1] = make_pair(sec, this->calc(sec));
            size = 1 + child[0]->size + child[1]->size;
        }
        
        inline void make(int v) {
            if (size == 0) {
                return ;
            }
            value[0] = make_pair(v, size);
            value[1] = make_pair(-INF, 0);
            same = v;
            inc = 0;
            val = v;
        }
        
        inline void add(int v) {
            if (size == 0) {
                return ;
            }
            inc += v;
            val += v;
            if (value[0].first != -INF) {
                value[0].first += v;
            }
            if (value[1].first != -INF) {
                value[1].first += v;
            }
        } 
        
        inline void reverse() {
            if (size == 0) {
                return ;
            }
            rev ^= 1;
            swap(child[0], child[1]);
        }
        
        inline void push() {
            if (size == 0) {
                return ;
            }
            if (rev) {
                child[0]->reverse();
                child[1]->reverse();
                rev = 0;
            }
            
            if (same != -INF) {
                child[0]->make(same);
                child[1]->make(same);
                same = -INF;
            }
            
            if (inc) {
                child[0]->add(inc);
                child[1]->add(inc);
                inc = 0;
            }
        }
    };
    typedef node *Node;
    node mem[N]; int used;
    Node Null, t[N];
    
    Node newNode(int v) {
        Node temp = &mem[used++];
        temp->size = 1, temp->same = -INF, temp->rev = 0, temp->val = v, temp->inc = 0;
        temp->value[0] = make_pair(v, 1);
        temp->value[1] = make_pair(-INF, 0);
        temp->child[0] = temp->child[1] = temp->father = Null;
        temp->isRoot = true;
        return temp;
    }
    
    
    void rotate(Node root) {
        Node father = root->father;
        father->push(); root->push();
        int dir = root->isRc();
        father->setChild(root->child[!dir], dir);
        if (father->isRoot) {
            father->isRoot = false;
            root->isRoot = true;
            root->father = father->father;
        } else {
            father->father->setChild(root, father->isRc());
        }
        root->setChild(father, !dir);
        father->update();
    }
    void splay(Node root) {
        for(root->push(); !root->isRoot; ) {
            if (root->father->isRoot) {
                rotate(root);
            } else {
                (root->isRc() == root->father->isRc()) ? 
                    (rotate(root->father), rotate(root)) : (rotate(root), rotate(root));
            }
        }
        root->update();
    } 
    void access(Node root, int oper = 0, int val = 0) {
        for(Node tmp(Null); root != Null; ) {
            splay(root);
            if (root->father == Null && oper) {
                if (oper == 1) {
                    tmp->make(val);
                    root->push();
                    root->child[1]->make(val);
                    root->val = val;
                    root->update();
                } else if (oper == 2) {
                    tmp->add(val);
                    root->push();
                    root->child[1]->add(val);
                    root->val += val;
                    root->update();
                }
            }
            root->child[1]->isRoot = true;
            root->child[1] = tmp;
            root->child[1]->isRoot = false;
            root->update();
            tmp = root;
            root = root->father;
        }
    }
public:
    void init(int n, int val[]) {
        used = 0;
        Null = newNode(-INF);
        Null->father = Null->child[0] = Null->child[1] = Null;
        Null->size = 0;
        for(int i = 1; i <= n; i++) {
            t[i] = newNode(val[i]);
        }
    }
    void Link(int son, int father) {
        access(t[son]);
        splay(t[son]);
        t[son]->father = t[father];
        t[son]->reverse();
    }
    void Cut(int u, int v) {
        access(t[v]);
        splay(t[u]);
        if (t[u]->father == t[v]) {
            t[u]->father = Null;
        } else {
            access(t[u]);
            splay(t[v]);
            if (t[v]->father == t[u]) {
                t[v]->father = Null;
            }
        }
    }
    
    void makeSame(int u, int v, int val) {
        access(t[u]);
        access(t[v], 1, val);
    }
    
    void add(int u, int v, int val) {
        access(t[u]);
        access(t[v], 2, val);
    }
    
    pair<int, int> getValue(int u, int v) {
        access(t[u]);
        Node root = t[v];
        pair<int, int> res;
        for(Node tmp(Null); root != Null; ) {
            splay(root);
            if (root->father == Null) {
                root->push();
                Node a = tmp, b = root->child[1];
                vector<int> vv;
                vv.push_back(root->val);
                for(int i = 0; i < 2; i++) {
                    vv.push_back(a->value[i].first);
                    vv.push_back(b->value[i].first);
                } 
                sort(vv.begin(), vv.end());
                vv.erase(unique(vv.begin(), vv.end()), vv.end());
                reverse(vv.begin(), vv.end());
                while(vv.size() && vv.back() == -INF) {
                    vv.pop_back();
                }
                if (vv.size() == 1) {
                    res = make_pair(-INF, 0);
                } else {
                    res = make_pair(vv[1], 0);
                    for(int i = 0; i < 2; i++) {
                        if (a->value[i].first == vv[1]) {
                            res.second += a->value[i].second;
                        }
                        if (b->value[i].first == vv[1]) {
                            res.second += b->value[i].second;
                        }
                    }
                    res.second += (root->val == vv[1]);
                }
            }
            root->child[1]->isRoot = true;
            root->child[1] = tmp;
            root->child[1]->isRoot = false;
            root->update();
            tmp = root;
            root = root->father;
        }
        return res;
    }
}tree;

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        static int testCount = 0;
        printf("Case #%d:\n", ++testCount);
        scanf("%d %d", &n, &m);
        static int val[N];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        tree.init(n, val);
        for(int i = 1; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            tree.Link(a, b);
        }
        for(int i = 1; i <= m; i++) {
            int type, a, b, x, y;
            scanf("%d", &type);
            if (type == 1) {
                scanf("%d %d %d %d", &x, &y, &a, &b);
                tree.Cut(x, y);
                tree.Link(a, b);
            } else if (type == 2) {
                scanf("%d %d %d", &a, &b, &x);
                tree.makeSame(a, b, x);
            } else if (type == 3) {
                scanf("%d %d %d", &a, &b, &x);
                tree.add(a, b, x);
            } else {
                int a, b;
                scanf("%d %d", &a, &b);
                pair<int, int> temp = tree.getValue(a, b);
                if (temp.first == -INF) {
                    printf("ALL SAME\n");
                } else {
                    printf("%d %d\n", temp.first, temp.second);
                }
            }
        }
    }
    return 0;
}