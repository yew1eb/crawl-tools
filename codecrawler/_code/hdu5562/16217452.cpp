#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>

typedef long long ll;
using namespace std;

int a[100100];

int main()
{
    int t;
    int i;
    int n,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&v);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int sum1 = 0;
        int sum = 0;
        for(i=0; i<n; i++)
        {
            if(sum + a[i] > v)
                break;
            sum += a[i];
            sum1++;
        }
        printf("%d\n",sum1);
    }
    return 0;
}