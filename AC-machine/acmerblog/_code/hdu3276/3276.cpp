#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=50010;
int a[MAXN],n,x,y,Case;
double sum[MAXN],Ldp[MAXN],Rdp[MAXN];//sum[i]存前i个数的Ek；Ldp[i]存前i个数中 满足长度的子序列 中的最大Ek；Rdp[i]存第i个数到第n个个数中 满足长度的子序列 中的最大Ek
bool f(double dt){
    sum[0]=0;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]-dt;
    deque<int> que;
    Ldp[x-1]=-1e10;
    for(int i=x;i<n-x;i++){//求Ldp[]
        while(!que.empty() && sum[i-x]<sum[que.back()])
            que.pop_back();
        que.push_back(i-x);
        while(que.front()<i-y)
            que.pop_front();
        Ldp[i]=max(Ldp[i-1],sum[i]-sum[que.front()]);
    }
    que.clear();
    sum[n+1]=0;
    for(int i=n;i>0;i--)sum[i]=sum[i+1]+a[i]-dt;
    Rdp[n-x+2]=-1e10;
    for(int i=n-x+1;i>x;i--){//求Rdp[]，原理和求Ldp[]一样
        while(!que.empty() && sum[i+x]<sum[que.back()])
            que.pop_back();
        que.push_back(i+x);
        while(que.front()>i+y)
            que.pop_front();
        Rdp[i]=max(Rdp[i+1],sum[i]-sum[que.front()]);
    }
    for(int i=x+1;i<=n-x;i++)//枚举判断
        if(Ldp[i-1]+Rdp[i+1]>=0)return true;
    return false;
}
void work(){
    