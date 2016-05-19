#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
int n,b,q;
void work()
{
    scanf("%d%d%d",&n,&b,&q);
    if (q != 1 && q != 10 && q != 100 && q != 1000) {
        printf("%.5f\n" , log10(1 + 1.0 / n));
    }else{
        if(q == 1){
            if (b==n||b/10==n||b/100==n||b/1000==n)
                puts("1.00000");
            else
                puts("0.00000");
            }else{
                if (b==n||b/10==n||b/100==n||b/1000==n||b*10==n||b*100==n||b*1000==n)
                    puts("1.00000");
                else
                    puts("0.00000");
            }
    }
}
int main() {
    int _,cas = 1;
    RD(_);
    while(_--){
        printf("Case #%d: ",cas++);
        work();
    }
    return 0;
}