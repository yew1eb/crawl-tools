#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<bitset>
#pragma comment(linker, "/STACK:1024000000,1024000000")
template <class T>
bool scanff(T &ret){ //Faster Input
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
#define inf 1073741823
#define llinf 4611686018427387903LL
#define PI acos(-1.0)
#define lth (th<<1)
#define rth (th<<1|1)
#define rep(i,a,b) for(int i=int(a);i<=int(b);i++)
#define drep(i,a,b) for(int i=int(a);i>=int(b);i--)
#define gson(i,root) for(int i=ptx[root];~i;i=ed[i].next)
#define tdata int testnum;scanff(testnum);for(int cas=1;cas<=testnum;cas++)
#define mem(x,val) memset(x,val,sizeof(x))
#define mkp(a,b) make_pair(a,b)
#define findx(x) lower_bound(b+1,b+1+bn,x)-b
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

double eps=1e-7;

int main(){
    tdata{
        double T,v1,v2,t,l,r,x,y,t1,t2;
        scanf("%lf%lf%lf",&T,&v1,&v2);
        printf("Case #%d: ",cas);
        //æä¸è¾¹
        t1=300.0/v2;
        t2=600.0/v2;
        l=t1;
        r=t2;
        t=(300.0*sqrt(2.0))/v1;
        if(t<r){
            rep(i,1,200){
                double m=(l+r)/2.0;
                if((m*v1)*(m*v1)>(300.0*300.0+(m-t1)*v2*(m-t1)*v2))r=m;
                else l=m;
            }
            x=sqrt((l*v1)*(l*v1)-300.0*300.0);
            y=300.0;
            t=x/v1;
            int cot1=1;
            int cot2=1;
            rep(i,2,4){
                t1=(double(i-1)*300.0)/v1+t+l;
                t2=(double(i)*300.0)/v2+T;
                if(t1<t2+eps)cot1++;
                else cot2++;
            }
            if(cot1>cot2){
                printf("Yes\n");
                continue;
            }
        }
        //æå³è¾¹
        t1=600.0/v2;
        t2=900.0/v2;
        l=t1;
        r=t2;
        t=300.0/v1;
        if(t<r){
            rep(i,1,200){
                double m=(l+r)/2.0;
                if((m*v1)*(m*v1)>(300.0*300.0+(t2-m)*v2*(t2-m)*v2))r=m;
                else l=m;
            }
            y=min(sqrt((l*v1)*(l*v1)-300.0*300.0),300.0);
            x=300.0;
            t=sqrt(300.0*300.0+(300.0-y)*(300.0-y))/v1;
            int cot1=1;
            int cot2=2;
            rep(i,3,4){
                t1=(double(i-1)*300.0)/v1+t+l;
                t2=(double(i)*300.0)/v2+T;
                //printf("%lf %lf\n",t1,t2);
                if(t1<t2+eps)cot1++;
                else cot2++;
            }
            if(cot1>cot2){
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");



    }
    return 0;
}