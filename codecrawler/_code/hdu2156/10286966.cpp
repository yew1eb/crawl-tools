#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    double ans;
    int n;
    int i;
    while(~scanf("%d",&n),n)
    {
        ans =n;
        for(i=2; i<=n; ++i)
            ans += (1.0/i) *(n-i+1)*2;
        printf("%.2f\n",ans);
    }
    return 0;
}
