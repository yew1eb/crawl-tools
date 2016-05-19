#include<stdio.h>
#include<math.h>
typedef long long LL ;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL layer,row,col ;
        LL n;
        scanf("%I64d",&n) ;
        layer = (LL)(pow(double(n) * 6.0 , 1.0/3.0)) - 1;
        while(layer*(layer+1)/2*(layer+2)/3 < n ){
            layer ++ ;
        }
         n -= (layer-1)*(layer)/2*(layer+1)/3 ;
        row = (LL )(sqrt(n * 2.0)) ;
        while(row * (row+1)/2 < n)
            row ++ ;
        n -=row*(row-1)/2 ;
        col = n;
        printf("%I64d %I64d %I64d\n",layer,row,col) ; 
    }
    return 0;
}