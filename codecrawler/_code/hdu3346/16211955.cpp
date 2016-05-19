#include<cstdio>
int main(){
    int t,n,s1,s2;
    scanf("%d",&t);
    while(t--){
        scanf("%D",&n);
        if(n%8==0){
            printf("Lucky number!\n");
            continue;
        }
        for(s1=s2=0;n;){
            s1+=n%10;
            s2+=(n%10)*(n%10);
            n/=10;
        }
        if(s1%8==0||s2%8==0){
            printf("Lucky number!\n");
            continue;
        }
        printf("What a pity!\n");
    }
}