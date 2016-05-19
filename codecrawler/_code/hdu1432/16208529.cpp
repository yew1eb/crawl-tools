#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
map<double, int> MP;//ç»è®¡ç¸åæçåºç°çæ¬¡æ°
map<int, int> X;//ç»è®¡ç¸åxåæ åºç°çæ¬¡æ°
int n, x[700], y[700];
int i, j, ans, cnt;
int main(){
    while(~scanf("%d", &n)){
        X.clear();
        ans=0;
        for(i=0; i<n; i++){
            scanf("%d %d", x+i, y+i);
            ans = max(ans, ++X[x[i]]);
            MP.clear();
            cnt=0;
            for(j=0; j<i; j++){
                if(x[j]==x[i])  continue;
                double tmp = (y[i]-y[j])*1.0/(x[i]-x[j]);
                cnt = max(cnt, ++MP[tmp]);
            }
            ans = max(ans, cnt+1);//ä¸è¦å¿è®°æåèç¹æ¬èº«ä¹ç®è¿å»
        }
        printf("%d\n", ans);
    }
    return 0;
}
