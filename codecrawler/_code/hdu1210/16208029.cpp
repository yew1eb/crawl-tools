#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i=2;
        int sum=1;
        while(i!=1){
            if(i>n){
                i=(i-n)*2-1;
            }else{
                i=i*2;
            }
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
