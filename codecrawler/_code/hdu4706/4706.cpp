#include <stdio.h>
#include <string.h>

int main() {
    int a[12][30][30];
    int i,j,k;
    int z = 97;
    for(i=3; i<=10; i++) {
        for(j=0; j<i; j++) {
            a[i][j][0] = z;
            z++;
            if(z==123)
                z = 97;
        }
        for(j=i-2,k=1; j>=0,k<i; j--,k++) {
            a[i][j][k] = z;
            z++;
            if(z==123)
                z = 97;
        }
        for(j=1; j<i; j++) {
            a[i][j][k-1] = z;
            z++;
            if(z==123)
                z = 97;
        }
    }
    for(i=3; i<=10; i++) {
        for(j=0; j<i; j++) {
            for(k=0; k<i; k++) {
                if(a[i][j][k]>=97 && a[i][j][k]<=122)
                    printf("%c", a[i][j][k]);
                else
                    printf(" ");
            }
            puts("");
        }
    }
    return 0;
}
