#include<iostream>  
#include<algorithm>  
#include<string>  
#include<map>  
#include<set>  
#include<cmath>  
#include<vector>
#include<queue>
#include<deque>
#include<string.h>  
#include<stdlib.h>  
#include<cstdio> 
#define ll long long 
using namespace std; 
int x[200002];
int n,r,dis,st,ed;
deque<pair<int,ll> > q;
void pushh(int i){
    while(!q.empty()&&q.back().second+dis<x[i]) 
        q.pop_back();
    q.push_back(make_pair(i,x[i]-dis));
}
int main(){
    int t;
    scanf("%d",&t);
    int Case=1;
    while(t--){
        q.clear();
        scanf("%d%d", &n, &r);
        for(int i=0;i<n;++i)
            scanf("%d", &x[i]),x[i+n]=x[i];
        dis=0;
        ll s=0;
        for(int i=0;i<n/2;++i,dis+=r)
            pushh(i);
        for(int i=n/2;i<n+n/2;++i,dis+=r){
            int a=q.front().first%n;
            int b=i%n;
            if(a>b)
                swap(a,b);
            ll ss=q.front().second+x[i]+dis;
            if(ss>s){
                s=ss;
                st=a;
                ed=b;
            } 
            else if(ss==s&&(a<st||(a==st&&b<ed))){
                st=a;
                ed=b;
            }
            if(!q.empty()&&q.front().first<=i-n/2) //åªæ«å°ån/2ä¸ºæ­¢ 
                q.pop_front();
            pushh(i);
        }
        printf("Case #%d:\n",Case++);  
        printf("%d %d\n",st+1,ed+1);  
    } 
    return 0;
} 