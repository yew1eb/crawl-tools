#include <stdio.h>
#include <string.h>

const int N = 1e6;
char str[N];
const char *s1 = "doge";

int find () {
    
    int sum = 0;
    char *p = strstr(str, s1);
    while (p != NULL) {
        
        sum++;
        p = p + 4;
        //if (*p == '\0')
        //    break;

        p = strstr (p, s1);
    }
    return sum;
}

int main () {

    int count = 0;
    while (scanf ("%s", str) != EOF) {

        for (int i = 0; i < strlen (str); i++) 
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        count += find ();    
    }
    printf ("%d\n", count);
    return 0;
}
