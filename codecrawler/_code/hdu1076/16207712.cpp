#include <stdio.h>

bool leap(int y){
    return y%4==0&&y%100||y%400==0;
}

int main(){
    int y,T,n,cnt,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&y,&n);
        cnt=0;
        for(i=y;cnt<n;i++)
            if(leap(i))
                cnt++;
        printf("%d\n",i-1);
    }
    return 0;
}