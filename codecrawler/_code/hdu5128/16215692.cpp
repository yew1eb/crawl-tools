#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N = 30;
const int M = 210;
map<int, map<int,int> > MP;
vector<int> X[M], Y[M];
typedef vector<int>::iterator vit;
#define all(it, V) for(vit it=V.begin(); it!=V.end(); it++)
struct Point{
    int x, y;
    bool operator < (const Point &A)const{
        return x<A.x || (x==A.x && y<A.y);
    }
}p[N];
int n, ans, a[4], b[4];
bool flag[N];
bool on_seg(int *arr, int i){
    if(p[arr[0]].x==p[i].x){
        return p[arr[0]].y<=p[i].y && p[i].y<=p[arr[1]].y;
    }
    if(p[arr[2]].x==p[i].x){
        return p[arr[2]].y<=p[i].y && p[i].y<=p[arr[3]].y;
    }
    if(p[arr[0]].y==p[i].y){
        return p[arr[0]].x<=p[i].x && p[i].x<=p[arr[2]].x;
    }
    if(p[arr[1]].y==p[i].y){
        return p[arr[1]].x<=p[i].x && p[i].x<=p[arr[3]].x;
    }
    return 0;
}
bool in(int *arr, int i){
    return (p[arr[0]].x<p[i].x && p[i].x<p[arr[2]].x) && (p[arr[0]].y<p[i].y && p[i].y<p[arr[1]].y);
}
bool in2(int *arr, int i){
    return (p[arr[0]].x<=p[i].x && p[i].x<=p[arr[2]].x) && (p[arr[0]].y<=p[i].y && p[i].y<=p[arr[1]].y);
}
int area(int *arr){
    return (p[arr[2]].x-p[arr[0]].x) * (p[arr[1]].y-p[arr[0]].y);
}
void solve1(){
    all(i, X[p[b[0]].x]){
        if(p[*i].y<=p[b[0]].y || flag[*i])    continue;
        if(!in(a, *i))    continue;
        b[1] = *i;
        all(j, Y[p[b[0]].y]){
            if(p[*j].x<=p[b[0]].x || flag[*j])    continue;
            if(!in(a, *j))    continue;
            b[2] = *i;
            if(MP[p[b[2]].x].count(p[b[1]].y)){
                b[3] = MP[p[b[2]].x][p[b[1]].y];
                if(!flag[b[3]])
                    ans = max(ans, area(a));
            }
        }
    }
}
void cal(){
    int cnt = 0;
    for(int i=0; i<4; i++){
        if(in(b, a[i]))    cnt++;
        if(on_seg(b, a[i]))    return;
    }
    if(cnt == 0)    ans = max(ans, area(a)+area(b));
    else if(cnt == 4)    ans = max(ans, area(b));
}
void solve2(){
    all(i, X[p[b[0]].x]){
        if(p[*i].y<=p[b[0]].y || flag[*i])    continue;
        if(in2(a, *i))    continue;
        b[1] = *i;
        all(j, Y[p[b[0]].y]){
            if(p[*j].x<=p[b[0]].x || flag[*j])    continue;
            if(in2(a, *j))    continue;
            b[2] = *j;
            if(MP[p[b[2]].x].count(p[b[1]].y)){
                b[3] = MP[p[b[2]].x][p[b[1]].y];
                if(!in2(a, b[3]) && !flag[b[3]]){
                    cal();
                }
            }
        }
    }
}
void solve(){
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<4; i++)    flag[a[i]] = 1;
    for(int i=0; i<n; i++){
        if(flag[i])    continue;
        if(on_seg(a, i))    continue;
        b[0] = i;
        if(in(a, i))    solve1();
        else    solve2();
    }
}
int main(){
    while(~scanf("%d", &n) && n){
        for(int i=0; i<n; i++){
            scanf("%d %d", &p[i].x, &p[i].y);
            X[p[i].x].clear();
            Y[p[i].y].clear();
        }
        if(n<8){
            puts("imp");
            continue;
        }
        sort(p, p+n);
        MP.clear();
        for(int i=0; i<n; i++){
            MP[p[i].x][p[i].y] = i;
            X[p[i].x].push_back(i);
            Y[p[i].y].push_back(i);
        }
        ans = -1;
        for(int i=0; i<n; i++){
            a[0] = i;
            all(j, X[p[a[0]].x]){
                if(p[*j].y <= p[a[0]].y)    continue;
                a[1] = *j;
                all(k, Y[p[a[0]].y]){
                    if(p[*k].x <= p[a[0]].x)    continue;
                    a[2] = *k;
                    if(MP[p[a[2]].x].count(p[a[1]].y)){
                        a[3] = MP[p[a[2]].x][p[a[1]].y];
                        solve();
                    }
                }
            }
        }
        if(ans==-1)    puts("imp");
        else    printf("%d\n", ans);
    }
    return 0;
}