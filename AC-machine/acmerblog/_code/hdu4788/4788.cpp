#include<stdio.h>
#include<math.h>
int main() {
    int a, n, m = 0;
    double d = 1000;
    char s[10], ch;
    for(int i = 1; i <= 10; i++)
      d /= 2;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        n = 0;
        for(int i = 0; s[i]; i++) {
            if(s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0';
            else {
                if(s[i] == '[')
                    continue;
                ch = s[i];
                break;
            }
        }
        printf("Case #%d: ", ++m);
        if(ch == 'B') printf("%.2f%%\n", (1 - pow(d, 0)) * 100);
        if(ch == 'K') printf("%.2f%%\n", (1 - pow(d, 1)) * 100);
        if(ch == 'M') printf("%.2f%%\n", (1 - pow(d, 2)) * 100);
        if(ch == 'G') printf("%.2f%%\n", (1 - pow(d, 3)) * 100);
        if(ch == 'T') printf("%.2f%%\n", (1 - pow(d, 4)) * 100);
        if(ch == 'P') printf("%.2f%%\n", (1 - pow(d, 5)) * 100);
        if(ch == 'E') printf("%.2f%%\n", (1 - pow(d, 6)) * 100);
        if(ch == 'Z') printf("%.2f%%\n", (1 - pow(d, 7)) * 100);
        if(ch == 'Y') printf("%.2f%%\n", (1 - pow(d, 8)) * 100);
    }
    return 0;
}
