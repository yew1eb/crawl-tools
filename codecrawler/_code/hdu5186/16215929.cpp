#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 205;
int n, b, length[N];
char str1[N], res[N], str[N][N];

int solve(char c) {
    int temp;
    if (c >= '0' && c <= '9')
        temp = c - '0';
    else
        temp = c + 10 - 'a';
    return temp;
}

int main() {
    while (scanf("%d%d", &n, &b) != EOF) {
        memset(str, '0', sizeof(str));
        int len = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str1);
            length[i] = strlen(str1);
            for (int j = 0, k = length[i] - 1; k >= 0; k--, j++)
                str[i][j] = str1[k];
            len = max(len, length[i]);
        }
        for (int i = 0; i < len; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                char c = str[j][i];
                int temp1 = solve(c);
                temp += temp1;
                temp = temp % b;
            }
            if (temp >= 10)
                res[i] = 'a' + temp - 10;
            else
                res[i] = temp + '0';
        }
        int flag = 1, i = 0;
        for (i = len - 1; i >= 0; i--) {
            if (res[i] != '0')    
                break;
        }
        if (i == -1)
            flag = 0;
        for (int j = i; j >= 0; j--)
            printf("%c", res[j]);
        if (!flag)
            printf("0");
        printf("\n");
    }
    return 0;
}