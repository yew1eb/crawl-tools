#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
#include <deque>
using namespace std;
typedef  long long  LL;
#define eps 10e-9
#define inf 0x3f3f3f3f
const int maxn = 1000+100;
const int mod  = 1000000000+7;
int n,m,k;
struct node{
      int b[18];
      int step;
}s_pos;
vector<int > v[10];
int c[maxn];
int a1[maxn],a2[maxn],a3[maxn];
int ans,f;
void solve(node &now,int c1,int c2,int c3){
           now.b[c1]-=2;   if(now.b[c1]<1) now.b[c1]=1;
           now.b[c2]+=1;   if(now.b[c2]>5) {
               f=1; return ;
           }
           now.b[c3]+=1;   if(now.b[c3]>5){
                f=1; return ;
           }
           for(int  i=0;i<v[ c[c2] ].size();i++){
               now.b[ v[ c[c2] ][i] ]++;
               if( now.b[ v[ c[c2] ][i] ]>5 ) {
                   f=1;return;
               }
           }
           for(int  i=0;i<v[ c[c3] ].size();i++){
               now.b[ v[ c[c3] ][i] ]++;
            if( now.b[ v[ c[c3] ][i] ]>5 ){
                 f=1; return;
            }
           }

}
void bfs(){
     queue<node > q;
     q.push(s_pos);
     while(!q.empty()){
           node now = q.front(),next; q.pop();
           if(now.step-1>ans) ans=now.step-1;

           int key=now.step;
           if(now.step>k){
               ans=k;
               return ;
           }
           now.step++;

           f=0; next=now;
           solve(next,a1[key],a2[key],a3[key]);
           if(!f) q.push(next);

           f=0;next=now;
           solve(next,a2[key],a1[key],a3[key]);
           if(!f) q.push(next);

           f=0; next=now;
           solve(next,a3[key],a2[key],a1[key]);
           if(!f) q.push(next);

     }
}
int main(){
    int T,h; scanf("%d",&T);
    int ca=1;
    while(T--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<=6;i++) v[i].clear();
        for(int i=0;i<n;i++) {
            scanf("%d",&h);
            c[i]=h;
            v[h].push_back(i);
        }
        for(int i=0;i<n;i++) scanf("%d",&s_pos.b[i]);
        s_pos.step=1;
        for(int i=1;i<=k;i++) scanf("%d %d %d",&a1[i],&a2[i],&a3[i]);
        ans=0;
        bfs();
        printf("Case #%d: %d\n",ca++,ans);
    }

    return 0;
}


