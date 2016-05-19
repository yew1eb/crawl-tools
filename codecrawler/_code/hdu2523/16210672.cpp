#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;

int cmp(const void *x,const void *y)
{
    return (*(int *)x - *(int *)y);
}

int main()
{
    int t,a[1005],hash[2005];
    cin >> t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(hash,0,sizeof(hash));
        int n,k,i,j,m = 0;
        cin >> n >> k;
        for(i = 1;i<=n;i++)
        cin >> a[i];
        int num = 0,flag = 1;
        qsort(a+1,n,sizeof(int),cmp);
        for(i = 1;i<n;i++)
        {
            for(j =  1;i+j<=n;j++)
            {
               hash[a[i+j]-a[j]]++;//a[i+j]-a[j]å°±æ¯é¢ç®ä¸­ç|xi-xj|
            }
        }
        int z = 0;
        for(int x = 0;x<=2000;x++)
        {
            if(hash[x])
            {
                z++;//ç»è®¡ä½ç½®
                if(z == k)
                {
                    cout << x << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
