#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 750;

int main()
{
    int n;
    int i, j, k;
    int x[MAXN], y[MAXN];

    while (cin>>n && n)
    {
        for (i=0; i<n; i++)
            cin>>x[i]>>y[i];
        int sum = 0;
        for (i=0; i<n; i++)
        {
            for (j=i+1; j<n; j++)
            {
                int num = 0;
                for (k=j+1; k<n; k++)
                    if ((x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]) == 0)
                        num++;
                sum = sum > num ? sum : num;
            }
        }
        cout<<sum+2<<endl;
    }
    return 0;
}