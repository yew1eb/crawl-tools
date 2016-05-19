#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
#define eps 1e-7
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
LL ans,n;
int i;
void dfs(int idx,int num,int k){
    if(k==0){
        LL temp=pow(n,1.0/num);
        if(pow(temp,0.0+num)>n)  temp--;
        temp--;
        if(temp>0)
            ans+=temp*(i&1?1:-1);
        return ;
    }
    if(idx>=17) return;
    if(num*prime[idx]<60)  dfs(idx+1,num*prime[idx],k-1);
    dfs(idx+1,num,k);
}
int main(){
    while(scanf("%I64d",&n)!=EOF){
        ans=0;
        for(i=1;i<=3;i++)
            dfs(0,1,i);
        printf("%I64d\n",ans+1);
    }
    return 0;

}
