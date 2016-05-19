#include<stdio.h>
int main(void){
int n,t,i;
double high[101],maxn;
scanf("%d",&n);
while(n--){
        maxn=0;
    scanf("%d",&t);
    for(i=0;i<t;i++){
            scanf("%lf",&high[i]);
    if(maxn<high[i])maxn=high[i];
    }
    printf("%.2f\n",maxn);
}
return 0;
}