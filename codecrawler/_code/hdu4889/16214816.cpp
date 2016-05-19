//tpl
//ipqhjjybj_tpl.h
//header.h
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <assert.h>

#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pLL pair<long long ,long long>
#define rep(i,j,k) for(int i = j; i < k;i++)
#define repn(i,j,k) for(int i = j; i <= k;i++)

using namespace std;

const int INF = 0x3f3f3f3f;
int c;
void print(){
    int n = 51;
    printf("%d %d\n",n,75);
    int ind = n;
    int w1 = 0 , w2 = -2;
    int cnt = 0;
    for(int i=n-2;i >= 1;i -=2){
        printf("%d %d %d\n",i,i+1,0);
        printf("%d %d %d\n",i+1,i+2,w2);
        printf("%d %d %d\n",i,i+2,w1);
        
        w1 = w2;
        w2 *= 2;
        cnt+=3;
    }
    //printf("cnt=%d n+2=%d\n",cnt,n+2);
    assert(cnt == 75);
}
int main(){
    
    while(scanf("%d",&c)!=EOF){
        print();
    }
    return 0;
}