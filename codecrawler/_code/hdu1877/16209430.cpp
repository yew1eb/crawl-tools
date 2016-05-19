#include <cstdio>
#include <cstdlib>

const int maxx = 100;

int digit[maxx];

int solve(long long int num,int base){
    int st = maxx;

    while(num!=0){
        digit[--st] = num%base;
        num /= base;
    }
    return st;
}
int main(){
    int m,a,b,st,i;
    long long int num;

    while(scanf("%d",&m) && m){
        scanf("%d %d",&a,&b);
        num = a+b;
        if(num==0){
            printf("0\n");
            continue;
        }
        st = solve(num,m);
        for(i=st;i<maxx;++i){
            printf("%d",digit[i]);
        }
        printf("\n");
    }

    return 0;
}