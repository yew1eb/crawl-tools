#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long 
using namespace std;

char str[1005];
int len;
int flag;

int judge() {
    for(int i = 0; i <= len / 2; i++) {
        if(str[i] != str[len - i - 1]) return 1;
    }
    return 0;
}

void dfs(int x) {
    if(flag == 0) return;
    if(x == len) {
        if(judge()) {
            printf("%s\n", str);
            flag = 0;
        }
        return;
    }
    if(str[x] <= 'z' && str[x] >= 'a') {
        dfs(x + 1);
        return;
    }
    
    if(str[x] == '?') {
        for(int i = 'a'; i <= 'z'; i++) {
            str[x] = (char)i;
            dfs(x + 1);
            str[x] = '?';
        }
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        scanf("%s", str);
        len = strlen(str);
        flag = 1;
        dfs(0);
        if(flag) {
            printf("QwQ\n");
        }
    }
    return 0;
}