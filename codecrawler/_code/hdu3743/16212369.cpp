#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 1000010;
const int N = 100010;
const int INF = 0x7fffffff;

struct node {
    int id, v;
}a[MAX_];

int C[MAX_];

inline int lowbit(int x){
    return x&(-x);
}

inline void add(int x,int num){
    while(x < MAX_){
        C[x] += num;
        x += lowbit(x);
    }
}

inline int sum(int x){
    int cnt = 0;
    while(x > 0){
        cnt += C[x];
        x -= lowbit(x);
    }
    return cnt;
}

int cmp(const node& a, const node& b ){
    return a.v < b.v;
}

int main(){
    int n;
    long long ans;
    while(scanf("%d",&n) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d",&a[i].v);
            a[i].id = i;
        }
        mst(C,0);
        sort(a+1,a+n+1,cmp);
        ans = 0;
        for(int i = n; i > 0; --i){
            ans += sum(a[i].id);
            add(a[i].id, 1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
