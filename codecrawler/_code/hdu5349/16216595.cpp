#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int inf = (1 << 31) - 1;

int main()
{
    int n;
    while(~scanf("%d", &n)){
        int x, counts = 0, maxn = -inf;
        while(n--){
            scanf("%d",&x);
            if(x == 1){
                scanf("%d", &x);
                maxn = x > maxn ? x : maxn;
                counts ++;
            }
            else if(x == 2){
                if(counts){
                    counts --;
                    if(counts == 0)
                        maxn = -inf;
                }
            }
            else if(x == 3){
                if(counts == 0)
                    printf("0\n");
                else
                    printf("%d\n", maxn);
            }
        }
    }
    return 0;
}
