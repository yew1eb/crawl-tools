/****************
*PID:hdu5573
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[65],bit[65],res[65];
int sign[65];
int main()
{
    LL i,j,n,k,T,kcase=1;
    fact[1]=1;
    for(i=2;i<=61;i++)
        fact[i]=fact[i-1]*2;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&k);
        for(i=1;i<=k;i++){
            res[i]=fact[i];sign[i]=1;
        }
        LL d=fact[k+1]-1-n;
        if(n%2==0){
            res[k]++;d++;
        }
        LL x=d/2,cnt=0;
        while(x){
            bit[cnt++]=x%2;x/=2;
        }
        for(i=1,j=0;j<cnt;j++){
            if(bit[j]) sign[i]=0;
            i++;
        }
        printf("Case #%I64d:\n",kcase++);
        for(i=1;i<=k;i++){
            printf("%I64d ",res[i]);
            if(sign[i])
                printf("+\n");
            else printf("-\n");
        }
    }
    return 0;
}