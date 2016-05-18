#include<stdio.h>
#include<math.h>
int main(){
    int N,M;


    while(scanf("%d%d",&N,&M),N||M){
        int len = (int)sqrt(M*2.0);
        int a1_len=0;//首项a1与len的乘积
        
        for (;len>0;len--){
            a1_len=M-(len-1)*len/2;//a1*N=M-(N+1)N/2;
            if(a1_len%len==0){
                printf("[%d,%d]\n",a1_len/len,a1_len/len+len-1);
            }
        }
        puts("");
    }


    return 0;
}