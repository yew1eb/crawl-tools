#include <stdio.h>
#include <string.h>
char str[1000];
int main()
{
    int t, i, j, len, a, b;
    char ch;
    scanf("%d", &t);
    getchar();
    while (t--) {
        gets(str);
        len = strlen(str);
        i = 0;
        while (i<len) {
            a = i;
            while(i<len&&str[i]!=' ') i++;
            b = i-1;
            for(j=b; j>=a; j--) printf("%c",str[j]);
            if(i<len) printf("%c",str[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
