#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
int main(){
    int i,n;
    while(scanf("%d",&n)!=EOF){
        for(i=2;i<=(int)sqrt((double)n);i++){ 
            int k=n%i; 
            if(k==0){ 
                printf("%d*",i); 
                n=n/i;i=1; 
            } 
        }
        printf("%d",n); 
        printf("\n"); 
    }
    return 0;
}
