#include <stdio.h>
#include <string.h>

int solve(char *str)
{
    int len = strlen(str);
    int system = 0, num = 0;
    int i, j = 1, k;
    for(i = len - 2; i >= 0; i --){//æ¥çæ¯å è¿å¶çæ°
        if(str[i] == '(')break;
        system = system + (int)(str[i] - '0')*j;
        j *= 10;
    }
    j = 1;
    for(k = i - 1; k >= 0; k --){//å°è¯¥æ°è½¬æ¢ä¸ºåè¿å¶æ°æ¯å¤å°
        num = num +(int)(str[k]-'0')*j;
        j*=system;
    }
//    printf("system = %d\n", system);
//    printf("num = %d\n", num);
    return num;
}

int main()
{
//    freopen("input.txt","r",stdin);
    int n;
    char str[70];
    while(scanf("%d", &n)!=EOF){
        int sum = 0;
        while(n--){
            scanf("%s", str);
            sum += solve(str);
//            puts(str);
        }
        printf("%d\n", sum);
    }
    return 0;
}