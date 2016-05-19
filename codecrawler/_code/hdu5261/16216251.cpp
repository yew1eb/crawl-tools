#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<cstdio>
#include<cstring>

#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<iostream>
#include<deque>
using namespace std;

#define LL long long
#define ULL unsigned long long
const int maxn = 100005;
int num[maxn*2];
deque<int> Q;
deque<LL> QS;
int n,r,ti=1,t;
int main(void){
    scanf("%d",&t);
    LL ans;
    int ax,ay;
    int tx,ty;
    while(t--){
        ans = 0;
        printf("Case #%d:\n",ti++);
        scanf("%d%d",&n,&r);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]),num[i+n]=num[i];
        while(!Q.empty()) Q.pop_back(),QS.pop_back();
        for(int i=1;i<=2*n;i++){
            while(!Q.empty()&&(i-Q.front())*2>n)  //ä½¿é¿åº¦ä¿æn/2 
                Q.pop_front(),QS.pop_front();
            if(!Q.empty()&&(i-Q.front())*2<=n&&1LL*num[i]+1LL*r*i+QS.front()>=ans){
                tx = Q.front();
                ty = i;
                if(tx>n) tx-=n;
                if(ty>n) ty-=n;
                if(tx>ty) tx=tx^ty,ty=tx^ty,tx=tx^ty;
                if(1LL*num[i]+1LL*r*i+QS.front()>ans)
                    ax = tx,ay=ty,ans = 1LL*num[i]+1LL*r*i+QS.front();
                
                else if(tx<ax||(tx==ax&&ty<ay)) ax=tx,ay=ty;
            }
            LL now = num[i]-1LL*r*i;
            while(!Q.empty()&&now>QS.back())  //ä½¿æ«å°¾è¯å®æ¯ä¸æ æå¤§çï¼é¤å»æ¯å½åç¹ä¸æ å°ä¸è·ç¦»æ²¡å½åç¹è¿çç¹ 
                Q.pop_back(),QS.pop_back();
            Q.push_back(i);
            QS.push_back(now);
        }
        printf("%d %d\n",ax,ay);
    }
    
    return 0;
}
