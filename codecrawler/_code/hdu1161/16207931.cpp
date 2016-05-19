#include <stdio.h>
#include <string.h>

int main() {
    char st[1005];
    int i;
    while(gets(st)) {
        for(i=0; st[i]!='\0'; i++) {
            if(st[i]>='A' && st[i]<='Z')
                //st[i] = st[i] + 32;
                st[i] += 32;
        }
        printf("%s\n",st);
    }
    return 0;
}
