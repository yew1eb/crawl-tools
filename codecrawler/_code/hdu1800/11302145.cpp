#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 3000 + 5;

int num[maxn];
int n;


int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i) {
            scanf("%d", &num[i]);
        }
        sort(num, num+n);
        int ans = 1, cnt = 1;
        for(int i=1; i<n; ++i)
        {
            if( num[i] != num[i-1])
            {
                cnt = 1;
            }else {
                cnt++;
            }
            if(cnt>ans) ans = cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
