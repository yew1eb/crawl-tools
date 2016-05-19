#include <iostream>
using namespace std;
#define N 45
__int64 method[N];

void init(){
    method[0]=1;
    method[1]=3;
    int i;
    for (i=2;i<N;i++)
        method[i]=(method[i-1]+method[i-2])*2;
}

int main(){
    int n;
    init();
    while (scanf("%d",&n)!=EOF)
        printf("%I64d\n",method[n]);
    return 0;
}