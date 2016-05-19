#include<cstdio>
#include<cstring>
#define maxn 1010
int n;
char str1[maxn], str2[maxn];
int mark[maxn];
bool check(char *s) {
    for(int i = 0; i < n / 2; i++) 
        if(s[i] != s[n - 1 - i])
            return false;
    return true;
}

int main() {

    while(scanf("%d", &n) == 1) {
        scanf("%s", str1);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            str2[i] = str1[i];
            if(str1[i] == '?') {
                str2[i] = 'a';
                mark[cnt++] = i;
            }
        }
        str2[n] = '\0';

        if(n == 1 && str1[0] == '?') {
            printf("QwQ\n");
            continue;   
        }
        if(cnt == 0 && check(str1)) {
            printf("QwQ\n") ;
            continue;
        }

        if( !check(str2)) {
            printf("%s\n",str2);
            continue;
        }

        str2[mark[cnt-1]] = 'b';
        if( !check(str2)) {
            printf("%s\n",str2);    
            continue;
        }

        if(cnt == 1) {
            printf("QwQ\n");
            continue;   
        }

        str2[mark[cnt-2]] = 'b';
        str2[mark[cnt-1]] = 'a';
        printf("%s\n",str2);

    }
    return 0;
}
