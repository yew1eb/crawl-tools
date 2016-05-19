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

using namespace std;

int a[1010];
bool flag;
int zai[100010];
int n;

bool bsearch(int begin1,int goal)
{
    int left =begin1,right = n - 1,mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(a[mid] == goal)
            return true;
        else if(a[mid] < goal)
            left = mid + 1;//æ³¨æåå·æ²é
        else
            right = mid - 1;
    }
    return false;
}


int main()
{
    int i,j;
    while(scanf("%d",&n) != EOF)
    {
        memset(zai,0,sizeof(zai));
        flag = false;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                int sum = a[i] + a[j];
                if(bsearch(j+1,sum))
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}