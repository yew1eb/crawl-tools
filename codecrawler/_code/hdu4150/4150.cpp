#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char a[1111111], b[11];

int main()
{
    int t, i, j, ans, lena, lenb;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", a, b);
        lena = strlen(a);
        lenb = strlen(b);
        ans = 0;
        for(i = 0; i < lena; i++)
        {
            for(j = 0; j < lenb; j++)
                if(a[i + j] != b[j])
                    break;
            if(j == lenb)
                ans++, i += j - 1;
        }
        printf("%d\n", ans);
    }
}