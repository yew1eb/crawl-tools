#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define LL long long
struct node{
    LL val;
    node(LL v=0):val(v){}
    bool operator < (const node &a)const{
        return val>a.val;
    }
};
priority_queue <node> que;
int main(){
    LL T,n;scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        while(!que.empty())que.pop();
        for(int i=0;i<n;i++){
            LL val;scanf("%lld",&val);
            que.push(node(val));
        }
        if(n==1){puts("0");continue;}
        LL ans=0;
        while(que.size()>=2){
            LL val=que.top().val;que.pop();
              val+=que.top().val;que.pop();
            ans+=val;
            que.push(node(val));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
