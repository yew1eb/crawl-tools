#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    char a[10001];
    int tot[10001];
    char c[10001];
    int cnt, n;
    int i;
    
    scanf("%d", &n);
    while (n--) {
        memset(tot, 0, sizeof(tot));
        memset(c, 0, sizeof(c));
        getchar();
        scanf("%s", a);
        c[cnt = 0] = a[0]; tot[cnt] = 1;
        for (i = 1; i < strlen(a); i++){
            if (a[i] == c[cnt])
                tot[cnt] ++;
            else{
                c[++cnt] = a[i];
                tot[cnt] = 1;
            }
        }
        for (i = 0; i <=cnt; i++) {
            if (tot[i] > 1)
                printf("%d%c", tot[i], c[i]);
            else 
                printf("%c", c[i]);
        }
        printf("\n");
    }
    return 0;
}