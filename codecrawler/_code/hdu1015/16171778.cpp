#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
bool visit[30] ,judge;
int ans[6] ,N[26] ,total;
long long target ,sum;
void set(char *a)
{
    int i ,len;
    for(i = 0 ;i < 30 ;i++)
        visit[i] = false;
    judge = false;
    len = strlen(a);
    sum = 0 ;
    total = -1;
    for(i = 0 ;i < len ;i++)
        N[++total] = (int)a[i] - 64;
    sort(N ,N + total);
}
void dfs(int n)
{
    int i ,j;
    long num;
    if(n == 6)
    {
        if(target == sum)
            judge = true;
        return ;
    }
    for(i = total ;i >= 0 ;i--)
    {
        if(visit[i] == false)
        {
            num = -1;
            for(j = 1 ;j <= n ;j++)
                num = num * N[i] * (-1);
            sum = sum + num;
            visit[i] = true;
            ans[n] = N[i];
            dfs(n + 1);
            if(judge == true) return ;
            sum = sum - num;
            visit[i] = false;
        }
    }
}
int main()
{
    char str[13];
    while(scanf("%lld %s",&target ,str))
    {
        string s = str;
        if(target == 0 && s == "END") break;
        else
        {
            set(str);
            dfs(1);
            if(judge == true)
                for(int i = 1 ;i <= 5 ;i++)
                    printf("%c",(char)(ans[i] + 64));
            else
                printf("no solution");
            printf("\n");
        }
    }
}