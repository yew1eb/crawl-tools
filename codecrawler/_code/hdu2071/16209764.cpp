#include<stdio.h>
int main(){
    int n,t,i;
    double s[110],max;
    scanf("%d",&t);
    getchar();
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&s[i]);
        max=s[0];
        for(i=1;i<n;i++)
            if(s[i]>max)
                max=s[i];
        printf("%.2lf\n",max);
    }
    return 0;
}