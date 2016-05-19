#include <cstdio>  
#include <cstdlib>  
#include <map>  
#include <set>  
#include <algorithm>  
#include <cstring>  
#include <iostream>  
#include <vector>  
#include <string>  
#include <queue>  
  
#define mp(x,y) make_pair(x,y)  
#define pii pair<int,int>  
#define pLL pair<long long ,long long>  
#define rep(i,j,k) for(int i = j; i < k;i++)  
#define repn(i,j,k) for(int i = j; i <= k;i++)  
  
using namespace std;  
#define lowbit(t) (t&(-t))  
const int N = 100005;  
long long F[N];  
long long sum[N],a[N],c[N];  
int n,m;  
void update(int pos,long long val){  
    for(; pos <= n; pos += lowbit(pos))  
        sum[pos] += val;  
}  
long long QUERY(int pos){  
    long long s = 0;  
    for( ; pos ; pos -= lowbit(pos)){  
        s += sum[pos];  
        //printf("pos=%d\n",pos);  
    }  
    return s;  
}  
int ts = 1;  
long long fuckIt(int i){  
    long long val = a[i];  
    int pp = lower_bound(F+1,F+ts,val) - F;  
    //printf("pp=%d\n",pp);  
    //printf("a[%d]=%lld F[%d]=%lld F[%d]=%lld\n",i,a[i],pp-1,F[pp-1],pp,F[pp]);  
    if(val == F[pp]){ }  
    else if( val - F[pp-1] > F[pp]-val){  
        val = F[pp]-val;  
        val = a[i] + val;  
    }else{  
        val = F[pp-1]-val;  
        val = a[i] + val;  
    }  
    return val;  
}  
set<int> fs;  
set<int> ks;  
int main(){  
    F[0] = F[1] = 1;  
    do{  
        ts++;  
        F[ts] = F[ts-1]+F[ts-2];  
    }while(F[ts] > 1);  
    int u,v,w;  
    while(scanf("%d %d",&n,&m)!=EOF){  
          
        for(int i=1;i<=n;i++) sum[i] = 0;  
        for(int i=1;i<=n;i++) c[i] = 1 , a[i]=0;  
        fs.clear();  
        for(int i=1;i<=n;i++) fs.insert(i);  
        ks.clear();  
        while(m--){  
            scanf("%d %d %d",&u,&v,&w);  
            if(u == 1){  
                update(v,w);  
                a[v]+=w;  
                c[v]=fuckIt(v);  
                fs.insert(v);  
            }else if(u==3){  
                for(set<int>::iterator it = fs.lower_bound(v); it !=fs.end(); it++){  
                    int i = *it;  
                    if(c[i]!=0 &&  i <= w){  
                        if( a[i] != c[i]) update(i,c[i]-a[i]);  
                        a[i] = c[i];  
                        c[i] = 0;  
                        ks.insert(i);  
                    }  
                    if(i > w) break;  
                }  
                for(set<int>::iterator it =ks.begin(); it!=ks.end(); it++ ){  
                    fs.erase(*it);  
                }  
                ks.clear();  
  
            }else if(u==2){  
                long long ans = QUERY(w)-QUERY(v-1);  
  
                cout << ans <<endl;  
            }  
        }  
    }  
    return 0;  
}  