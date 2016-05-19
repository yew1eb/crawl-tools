#include <cstdio>
#include <cstring>

char s[200], t[] = "anniversary";
int len;


bool ok(int x, int y) {
    int f1 = 0, f2 = 0, f3 = 0;
    for(int i = 0; i < len; i++) {
        if(!f1) {
            if(s[i] == t[0]) {
                int f = 1;
                for(int j = 1; j <= x && f; j++)
                    if(s[i+j] != t[j]) f = 0;
                if(f) {
                    i = i+x;
                    f1 = 1;
                }
            }
        }
        else if(!f2) {
            if(s[i] == t[x+1]) {
                int f = 1;
                for(int j = x+2; j <= y && f; j++)
                    if(s[i+j-x-1] != t[j]) f = 0;
                if(f) {
                    i = i+y-x-1;
                    f2 = 1;
                }
            }

        }
        else if(!f3) {
            if(s[i] == t[y+1]) {
                int f = 1;
                for(int j = y+2; j <= 10 && f; j++)
                    if(s[i+j-y-1] != t[j]) f = 0;
                if(f) return true;
            }
        }
    }
    return false;
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        len = strlen(s);
        int flag = 0;
        for(int i = 0; i < 9 && !flag; i++)
            for(int j = i+1; j < 10 && !flag; j++)
                if(ok(i, j)) flag = 1;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
