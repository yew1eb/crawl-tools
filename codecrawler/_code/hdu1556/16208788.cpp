#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100000+10;
int n;
int c[MAX];

int lowbit(int x){
    return x&(-x);
}

void Update(int x,int y){
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}

int Query(int x){
    int sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

int main(){
    int a,b;
    while(~scanf("%d",&n),n){
        for(int i=1;i<=n;++i)c[i]=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&a,&b);
            Update(a,1);
            Update(b+1,-1);
        }
        printf("%d",Query(1));
        for(int i=2;i<=n;++i)printf(" %d",Query(i));
        cout<<endl;
    }
    return 0;
}