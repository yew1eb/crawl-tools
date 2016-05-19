#include <stdio.h>

int main(){

        int d[902]={0}, x;
        int t, i;

        for(i=1; i<902; i++)
            d[i] = d[i-1] + i * i * i;

        scanf("%d", &t);
        while(t--){
           scanf("%ld", &x);
           for(i=0; i<902; i++){
                        if(d[i]<x && x<=d[i+1]){
                                        printf("%d\n", i+1);
                                        break;
                                    }
                    }
        }

        return 0;
}
