#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define maxn 1100
int N, sum, M;
int per[maxn];

void init() {
    sum = 0;
    for(int i = 0; i < N; ++i)
        per[i] = i;
}

int find(int x){
    int r = x;
    while( r != per[r])
        r = per[r];
    per[x] = r;
    return r;
}

void join (int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        per[fa] = fb;
    }
    else sum++;
}

int main (){
    while(scanf("%d%d", &N, &M) != EOF){
        init();
        while(M--){
            int a, b;
            scanf("%d%d", &a, &b);
            join(a, b);
        }
        printf("%d\n", sum);
    }
    return 0;
}
