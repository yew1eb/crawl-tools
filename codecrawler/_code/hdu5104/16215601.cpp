#include <cstdio>
#include <iostream>
#include <cstring>
int p[10017];
void init()
{
    memset(p,0,sizeof(p));
    for(int i = 2; i <= 10000; i++)
    {
        if(p[i] == 0)
        {
            for(int j = i*i; j <= 10000; j+=i)
            {
                p[j] = 1;
            }
        }
    }
}
int main()
{
    int a[10017];
    int n;
    init();
    while(~scanf("%d",&n))
    {
        int cont = 0;
        for(int i = 2; i <= n; i++)
        {
            if(p[i] == 0)
                for(int j = i; j <= n; j++)
                {
                    if(p[j] == 0 && p[n-i-j] == 0)
                        if(n-i-j>=i && n-i-j>=j)
                        {
                            cont++;
                        }
                }
        }
        printf("%d\n",cont);
    }
    return 0;
}
