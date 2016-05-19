#include<stdio.h>
#include<string.h>
#include<math.h>
#include<set>
#define ll double
using namespace std;
inline ll Max(ll a,ll b){return a>b?a:b;}
inline ll Min(ll a,ll b){return a>b?b:a;}
int main(){
    int n,i;
    while(~scanf("%d",&n)){
        ll len=0,v=9999999,a,b;
        while(n--){
            scanf("%lf%lf",&a,&b);
            v=Min(v,b);
            len+=a;
        }
    printf("%.2lf\n",len/v);
    }
    return 0;
}
