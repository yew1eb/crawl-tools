#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#define OP(s) cout<<#s<<"="<<s<<" ";
#define PP(s) cout<<#s<<"="<<s<<endl;
using namespace std;

int main()
{
    freopen("test.txt","r",stdin);
    static int a[1010],b[1010];
    static char s[3010];
    int N;
    while (scanf("%d",&N),N)
    {
        a[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i] - a[i-1];
        }

        bool ans = true;
        for (int i = 2; i <= N; i++)
        {
            if (ans)
                for (int j = 1; j <= N; j++)
                {
                    scanf("%d",&a[j]);
                    if (j != 1)
                    {
                        if (a[j] - a[j-1] != b[j]) ans = false;
                    }
                }
            else {getchar();gets(s);}
        }

        if (ans) printf("homogeneous\n");
        else printf("not homogeneous\n");
    }

    return 0;
}