#include <stdio.h>
#include <string.h>
const int maxn=  100010;
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
    char str1[maxn], str2[maxn];
    int next1[maxn], next2[maxn];
    int k1, k2;
    while(~scanf("%s %s",str1, str2)) {
       getFail(str1, next1);
       getFail(str2, next2);
       k1 = KMP(str1, str2, next1);
       k2 = KMP(str2, str1, next2);
//       printf("%d %d\n",k1, k2);
        if(k1==k2)
        {
            if(strcmp(str1,str2)<=0)
                printf("%s%s\n",str1, str2+k1);
            else
                printf("%s%s\n",str2, str1+k2);
        }
        else if(k1<k2)
            printf("%s%s\n",str2,str1+k2);
        else
            printf("%s%s\n",str1,str2+k1);
    }
    return 0;
}






