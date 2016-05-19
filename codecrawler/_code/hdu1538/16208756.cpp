#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int pri[14]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
int solve(int n,int m,int p){
    int i,m2=2*m;
    if(n<=m2+1){
        if(p!=n&&((p&1)==(n&1)))
        printf("1\n");
        else if(p==n)
        printf("%d\n",m-(n-1)/2);
        else
        printf("0\n");
        return 1;
    }
    int temp=n-m2;
    for(i=0;i<14;i++){
        if(temp==pri[i]){
            printf("0\n");
            return 1;
        }
    }
    for(i=0;i<14;i++){
        if(temp<pri[i]){
            if(p>m2+pri[i-1]&&p<m2+pri[i])
            printf("Thrown\n");
            else printf("0\n");
            return 1;
        }
    }
}
int main()
{
    int tcase,n,m,k;
    scanf("%d",&tcase);
    while(tcase--){
        scanf("%d%d%d",&n,&m,&k);
        solve(n,m,k);
    }
    return 0;
}
