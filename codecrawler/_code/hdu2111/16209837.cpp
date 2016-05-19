#include <iostream>
#include <stdlib.h>
using namespace std;

struct bb
{
    int p[105];
    int m[105];
} bao;

int main()
{
    int v,n;
    while(cin >> v,v)
    {
        cin >> n;
        int i,j,t;
        for(i = 0; i<n; i++)
        {
            cin >> bao.p[i] >> bao.m[i];
        }
        for(i = 0; i<n-1; i++)
        {
            int k = i;
            for(j = i+1; j<n; j++)
            {
                if(bao.p[j]>bao.p[k])
                    k = j;
            }
            t = bao.p[i];
            bao.p[i] = bao.p[k];
            bao.p[k] = t;
            t = bao.m[i];
            bao.m[i] = bao.m[k];
            bao.m[k] = t;
        }
        int sum_v = 0,sum = 0;
        for(i = 0; i<n; i++)
        {
            sum_v+=bao.m[i];
            if(sum_v<=v)
                sum+=bao.p[i]*bao.m[i];
            else
            {
                int t = sum_v-v;
                sum+=bao.p[i]*(bao.m[i]-t);
                break;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
