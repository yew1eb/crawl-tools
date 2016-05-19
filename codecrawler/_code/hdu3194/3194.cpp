#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000

int a[N], n, i;
int main(){
    int m, ans;
    while( scanf("%d%d",&n,&m) != EOF){
        ans = 0;
        for(i=1; i<=n; i++)
            scanf("%d", a+i);
        sort(a+1, a+1+n);
        while(a[(n+1)/2] != m){
            a[++n] = m;
            sort(a+1, a+1+n);
            ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}