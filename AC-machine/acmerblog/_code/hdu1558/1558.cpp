#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
const double INF = 1<<30;
const int MAXN = 1010;

struct Node{
    double x1;
    double y1;
    double x2;
    double y2;
};
Node node[MAXN];

int n;
int father[MAXN];
int rank[MAXN];

void init(int m){
    for(int i = 0 ; i <= m ; i++){
        father[i] = i;
        rank[i] = 1;
    }
}

int find(int x){
    if(father[x] != x){
        int fa = father[x];
        father[x] = find(fa);
        rank[x] += rank[fa];
    }
    return father[x];
}

double multiply1(Node a , Node b){
    return (a.x1-a.x2)*(b.y1-a.y1)-(a.y1-a.y2)*(b.x1-a.x1);
}

double multiply2(Node a , Node b){
    return (a.x1-a.x2)*(b.y2-a.y1)-(a.y1-a.y2)*(b.x2-a.x1);
}

bool inter(Node a , Node b){
    if(max(a.x1,a.x2) >= min(b.x1,b.x2) &&
            max(b.x1,b.x2) >= min(a.x1,a.x2) &&
            max(a.y1,a.y2) >= min(b.y1,b.y2) &&
            max(b.y1,b.y2) >= min(a.y1,a.y2) &&
            multiply1(a,b) * multiply2(a,b) <= eps &&
            multiply1(b,a) * multiply2(b,a) <= eps)
        return true;
    else return false;
}
void solve(){
    for(int i = 1 ; i < n ; i++){
        if(inter(node[i] , node[n])){
            int fx = find(i); 
            int fy = find(n);
            if(fx != fy){
                father[fy] = fx;
                rank[fx] += rank[fy];
            }
        }          
    }
}

int main(){
    int cas , m , k;
    bool isFirst = true;
    char c;
    scanf("%d" , &cas);
    while(cas--){
        if(isFirst)
            isFirst = false;
        else
            puts("");
        n = 1;
        scanf("%d%*c" , &m); 
        init(m);
        while(m--){
            c = getchar(); 
            if(c == 'P'){
                scanf("%lf" ,&node[n].x1);       
                scanf("%lf" ,&node[n].y1);       
                scanf("%lf" ,&node[n].x2);       
                scanf("%lf%*c" ,&node[n].y2);       
                if(node[n].x1 > node[n].x2){
                    swap(node[n].x1 , node[n].x2); 
                    swap(node[n].y1 , node[n].y2); 
                }
                solve();
                n++;
            }
            else{
                scanf("%d%*c" , &k); 
                int fa = find(k);
                printf("%d\n" , rank[fa]);
            }
        }
    }
    return 0;
}