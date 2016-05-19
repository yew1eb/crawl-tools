#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define LL unsigned long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define clr(x,a) memset(x,a,sizeof(x))
#define read(x) scanf("%d",&x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define gc getchar()
#define next(x) (x=='9'?'a':x+1)
//#define OUT
const int N = 50005;
const LL MOD=998244353;
const int MAX=0x3f3f3f3f;
double esp=1e-6;
int n,m;
queue<int> Q;
int cas=1;
LL ans;
void solve(queue<int> &q,int num){
  //  cout<<num<<endl;
     if(q.size()==0) return;
     queue<int> q1,q2;
     int tmp=(1<<num);
     while(!q.empty()){
        int x=q.front();
        q.pop();
        if(tmp&x){
            q2.push(x);
        }else{
            q1.push(x);
        }


        }
        ans=(ans+(LL)q1.size()*q2.size()*tmp)%MOD;
        if(num>=29 )return;
        solve(q1,num+1);
        solve(q2,num+1);





}
int main(){
  #ifndef ONLINE_JUDGE
 freopen("aaa.txt", "r", stdin);
  #endif
  int T,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++){
          scanf("%d",&x);
          Q.push(x);

        }
        ans=0;
        solve(Q,0);
        ans=ans*2%MOD;
        printf("Case #%d: %d\n",cas++,ans);



    }

  return 0;
}

