#include <cstdio>
#include <cstring>
const int MAXN = 1005;
int a[MAXN];

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k)){
        for(int i=1;i<=n;++i){
            scanf("%d", &a[i]);
        }
        if(k == 1){
            printf("Alice\n");
        }
        else{
            int g;
            if(n & 1){
                g = a[1] - (k == 2);//
                for(int i=2;i<n;i+=2){
                    g ^= (a[i+1] - a[i] - 1);
                }
            }else{
                g = 0;
                for(int i=1;i<n;i+=2){
                    g ^= (a[i+1] - a[i] - 1);
                }
            }
            if(g){
                printf("Alice\n");
            }else{
                printf("Bob\n");
            }
        }
    }
    return 0;
}
