#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <queue>
#define MAX 1000000
using namespace std;

int gcd(int m,int n){
    int r;
    while(r=m%n){
        m=n;
        n=r;
    }
    return n;
}

int main(){
    int n,a,b,c,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        a/=b;
        for(i=2;i<=MAX;i++){
            if(gcd(i,a)==1){
                c=i*b;
                break;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}