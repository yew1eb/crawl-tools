#include<iostream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int res[16];

int fun(int n)
{
    int ans, flag, sum;
    if(res[n])
        return res[n];
    else
    {
        for(ans = n + 1; ; ++ans)
        {
            flag = 0;
            sum = 2 * n;
            for(int j = ans; ; j += ans - 1) //äººæ°å1
            {
                if(j > sum)
                    j = j % sum ? j % sum : sum; //äººæ°å1
                if(j <= n) 
                    break;
                else    
                    sum--;
                if(sum == n)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                res[n] = ans;
                return res[n];
            }
        }
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        printf("%d\n", fun(n));
    }
    return 0;
}        