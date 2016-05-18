#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
const int N = 50010;
const int M = 200010;
int dit[N];
__int64 num[N];
__int64 ans[M];
struct interval{
    int lp,rp,id;
}rr[M];
bool  cmp(interval a,interval b){
    if(a.rp == b.rp)
        return a.lp < b.lp;
    return a.rp < b.rp;
}
int inline lowbit(int x){
    return x & (-x);
}
void inline update(int x,int add){
    while(x < N){
      num[x] += add;
      x += lowbit(x);
    }
}
__int64 inline sum(int x){
    __int64 s = 0;
    while(x > 0){
      s += num[x];
      x -= lowbit(x);
    }
    return s;
}
int main(){
    int numcase;
    map<int,int> mp;
    scanf("%d",&numcase);
    while(numcase--){
       int n,m;
       scanf("%d",&n);
       memset(dit,0,sizeof(dit));
       for(int i = 1; i <= n; ++i){
          scanf("%d",&dit[i]);
       }
       scanf("%d",&m);
       for(int i = 0; i < m; ++i){
          scanf("%d%d",&rr[i].lp,&rr[i].rp);
          if(rr[i].rp < rr[i].lp)
             swap(rr[i].lp,rr[i].rp);
          rr[i].id = i;
       }
       sort(rr,rr+m,cmp);
       memset(num,0,sizeof(num));
       memset(ans,0,sizeof(ans));
       mp.clear();
       int rp = 1;
       for(int i = 0; i < m; ++i){
           while(rp <= rr[i].rp){
              int x = dit[rp];
              if(mp[x] != 0){
                 update(mp[x],-x);
              }
              update(rp,x);
              mp[x] = rp;
              rp++;
           }
           ans[rr[i].id] = sum(rr[i].rp) - sum(rr[i].lp - 1); 
       }
       for(int i = 0; i < m; ++i){
          printf("%I64d\n",ans[i]);
       }
       
    }
    //system("pause");
    return 0;
}