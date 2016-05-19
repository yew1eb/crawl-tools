#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 10005;
LL arr[maxn];
LL m,k;
int n;
int main(){
    int T,Case = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%I64d%I64d",&n,&m,&k);
        for(int i = 0; i < n; i++)
            scanf("%I64d",&arr[i]);
        sort(arr,arr + n);
        LL now = m;
        int ok = 0;
        printf("Case #%d:\n",Case++);
        if(m < arr[0]){
            printf("madan!\n");
            continue;
        }
        for(int i = 0; i < n; ){
            if(arr[i] <= now) i ++;
            else{
                now = arr[i - 1] + k;
                if(now < arr[i]) break;
                else i++;
                k --;
            }
            if(i == n){
                ok = 1;
                break;
            }
        }
        if(ok)
            printf("why am I so diao?\n");
        else
            printf("madan!\n");
    }
    return 0;
}
