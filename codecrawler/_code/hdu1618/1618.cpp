#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>
#define inf 40000
int n,ans[11],opt[11],num[11][11],cas=1,len;
char* cmd[]= {"ADD","DIV","DUP","MUL","SUB"}; //01234
char best[11],res[11];
using namespace std;
bool empty()
{
    for(int i=1; i<=n; i++)
    {
        if(ans[i]!=opt[i])
            return false;
    }
    return true;
}
int calc(int n,int deep)
{
    int stk=1;
    num[n][1]=opt[n];
    for(int i=1; i<=deep; i++)
    {
        if(res[i]=='0')
        {
            num[n][stk-1]=num[n][stk-1]+num[n][stk];
            stk--;
        }
        else if((res[i]=='1'))
        {
            if(!num[n][stk])
                return inf;
            num[n][stk-1]=num[n][stk-1]/num[n][stk];
            stk--;
        }
        else if((res[i]=='2'))
        {
            num[n][stk+1]=num[n][stk];
            stk++;
        }
        else if((res[i]=='3'))
        {
            num[n][stk-1]=num[n][stk-1]*num[n][stk];
            stk--;
        }
        else if((res[i]=='4'))
        {
            num[n][stk-1]=num[n][stk-1]-num[n][stk];
            stk--;
        }
        if(abs(num[n][stk])>30000)
            return inf;
    }
    return num[n][stk];
}
bool check(int deep)
{
    for(int i=1; i<=n; i++)
    {
        if(calc(i,deep)!=ans[i])
            return false;
    }
    return true;
}
void dfs(char inc,int deep,int stk)
{
    if(deep>=len || !stk)
        return;
    res[deep]=inc;
    if(check(deep))
    {
        len=deep;
        strcpy(best+1,res+1);
        return;
    }
    for(int i=0; i<5; i++)
    {
        if(i==2)
            dfs(i+'0',deep+1,stk+1);
        else
            dfs(i+'0',deep+1,stk-1);
    }
}
int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        len=11;
        for(int i=1; i<=n; i++)
            scanf("%d",&opt[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&ans[i]);
        printf("Program %d\n",cas++);
        if(empty())
        {
            printf("Empty sequence\n\n");
            continue;
        }
        dfs('2',1,2);
        if(len==11)
            printf("Impossible\n\n");
        else
        {
            for(int i=1; i<=len; i++)
            {
                if(i>1)
                    printf(" ");
                printf("%s",cmd[best[i]-'0']);
            }
            printf("\n\n");
        }
    }
    return 0;
}