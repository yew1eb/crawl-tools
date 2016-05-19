#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 99999999
#define NN 20010
int RP[NN];
int l,r,max, rp;
int main()
{
    int T,n,a,b,c,i,x;
    scanf("%d",&T);
    while(T--){
    
        scanf("%d",&n);    
        for(i=0;i<NN;i++)RP[i] = -INF;
        l=r= 10000;
        max = 0;
        RP[l]=0;
        while(n--){
            scanf("%d%d%d",&a,&b,&c);
            b +=10000;
            if(a < 0){
                for(i=b;i<=r;i++)
                    if(RP[i] != -INF){
                        x = RP[i] +c;
                        //if(RP[i+a] == -INF)RP[i+a] = 0;
                        if(RP[i+a] < x)
                            RP[i+a] = x;
                    }
                l +=a;
            }
            else if (a>0){
                for(i=b;i>=l;i--){
                    if(RP[i] !=-INF){
                        x = RP[i] +c;
                        //if(RP[i+a] == -INF)RP[i+a] = 0;
                        if(RP[i+a] < x)
                            RP[i+a] = x;
                    }
                }
                r +=a;
            }
        }
        for(i=l;i<=r;i++)
            if(RP[i] > max &&RP[i] != -INF)max = RP[i];
        printf("%d\n",max);
    
    }
    return 0;
}