#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=100010;
ll bit[MAX];
ll f[100];
int del[MAX];
int n,m;
inline int lowbit(int t){return t&-t;}
ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=lowbit(i);
    }
    return s;
}
void add(int i,ll v){
    while(i<=n){
        bit[i]+=v;
        i+=lowbit(i);
    }
}
void init(){
    CLR(f);
    f[0]=1;f[1]=1;
    for(int i=2;i<=91;i++) f[i]=f[i-1]+f[i-2];
}
int main(){
    init();
    while(~scanf("%d%d",&n,&m)){
        CLR(bit);
        set<int>st;
        set<int>::iterator it;
        for(int i=1;i<=n;i++) st.insert(i);
        while(m--){
            int ord,a,b;
            scanf("%d%d%d",&ord,&a,&b);
            switch(ord){
                case 1:
                    add(a,b);
                    st.insert(a);
                    break;
                case 2:
                    printf("%I64d\n",sum(b)-sum(a-1));
                    break;
                case 3:
                    it=lower_bound(st.begin(),st.end(),a);
                    del[0]=0;
                    for(;it!=st.end()&&((*it)<=b);it++){
                        int p=*it;
                        del[++del[0]]=p;
                        ll u=sum(p)-sum(p-1),k;
                        int t=lower_bound(f+1,f+92,u)-f;
                        if(abs(f[t]-u)<abs(f[t-1]-u)) k=f[t];
                        else k=f[t-1];
                        add(p,-u);add(p,k);
                    }
                    for(int i=1;i<=del[0];i++) st.erase(del[i]);
                    break;
                default:;
            }
        }
    }
    return 0;
}
