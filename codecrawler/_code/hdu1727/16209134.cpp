#include <stdio.h>
char a[21][10]={
"zero","one","two","three","four","five",
"six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen", "fifteen",
"sixteen","seventeen","eighteen","nineteen","twenty"
};
char b[10][10]={
"twenty","thirty","forty","fifty",
"sixty","seventy","eighty","ninety"
};
int main(){
    int n,q;
    while(~scanf("%d",&n)){
        if(!n){
            printf("zero\n");
            continue;
        }
        if(n>=1000){
            q=n/1000;
            printf("%s thousand",a[q]);
            n-=q*1000;
            if(!n){
                printf("\n");
                continue;
            }
            printf(" and ");
        }
        if(n>=100){
            q=n/100;
            printf("%s hundred",a[q]);
            n-=q*100;
            if(!n){
                printf("\n");
                continue;
            }
            printf(" and ");
        }
        if(n){
            if(n<=20)
                printf("%s\n",a[n]);
            else
            {
                q=n/10;
                printf("%s",b[q-2]);
                n-=q*10;
                if(!n){
                    printf("\n");
                    continue;
                }
                printf ("-%s\n", a[n]);
            }
        }
    }
    return 0;
}