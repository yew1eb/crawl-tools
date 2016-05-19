#include <stdio.h>
#include <string.h>
const int maxn = 100010;

void getFail(char* P, int* f)
{
    int m = strlen(P);
    f[0] = 0;
    f[1] = 0;
    for(int i=1; i<m; i++) {
        int j = f[i];
        while(j && P[i] != P[j]) j = f[j];
        f[i+1] = P[i] == P[j]? j+1 : 0;
    }
}

int KMP(char* T, char* P, int* f)
{
    int n =strlen(T), m = strlen(P);
    getFail(P, f);
    int j = 0;
    for(int i=0; i<n; i++) {
        while(j && P[j] != T[i]) j = f[j];
        if(P[j] == T[i]) j++;
        //if(j == m) printf("%d\n", i - m+1);
    }
    return j;
}

int main()
{
    int L;
    char str1[maxn], str2[maxn];
    int f[maxn];
    while(~scanf("%s%s",str1,str2))
    {
        L = KMP(str2, str1, f);
        if(0 == L) printf("0\n");
        else
        {
            printf("%s %d\n",str2+strlen(str2)-L, L);
        }
    }
    return 0;
}



