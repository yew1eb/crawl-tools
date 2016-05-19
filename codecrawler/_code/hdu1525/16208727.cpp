#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#define LL long long
#define N 1000000
#define inf 1<<20
using namespace std;
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF&&a+b){
        if(a<b)
            swap(a,b);
        bool stan=true;
        while(1){            
            if(b==0||a%b==0||a/b>=2) break;
            int t=a;
            a=b;
            b=t-a;
            stan=!stan;
        }
        if(stan)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
    