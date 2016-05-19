#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int cmp(const int a,const int b)
{
    return a>b;
}

int a[3005],sum[3000*3000/2];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        int i,j;
        for(i = 0;i<n;i++)
        {
            cin >> a[i];
        }
        int k = 0;
        for(i = 0;i<n-1;i++)
        {
            for(j = i+1;j<n;j++)
            {
                sum[k++] = a[i]+a[j];
            }
        }
        sort(sum,sum+(n*(n-1))/2,cmp);
        for(i = 0;i<m;i++)
        {
            if(!i)
            cout << sum[i];
            else
            cout << " " << sum[i];
        }
        cout << endl;
    }

    return 0;
}
