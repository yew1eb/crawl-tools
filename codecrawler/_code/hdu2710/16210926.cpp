#include <iostream>
#include <string.h>
using namespace std;
#define N 20010
int main()
{
    int n,a[N],s[N],i,j;
    memset(s,1,sizeof(s));
    for(i = 2;i<N;i++)
    {
        if(s[i])
        for(j = i+i;j<N;j+=i)
        s[j] = 0;
    }
    for(i = 2,j = 2;i<N;i++)
    {
        if(s[i])
        a[j++] = i;
    }
    a[1] = 1;
    memset(s,0,sizeof(s));
    while(cin >> n)
    {
        int max = 0,flag;
        for(i = 1;i<=n;i++)
        cin >> s[i];
        for(i = 1;i<=n;i++)
        {
            for(j = 1;a[j]<=s[i];j++)
            {
                if(s[i]%a[j] == 0)
                {
                    if(max < a[j])
                    {
                    max = a[j];
                    flag = i;
                    }
                }
            }
        }
        cout << s[flag] << endl;
    }


    return 0;
}
