#include <cstring>
#include <cstdio>
using namespace std;
int n,l;
char ans[82];

bool check(int len)
{
    int flag=false;
    for(int t=len-1; t>=(len+1)/2; t--)
    {
        int i=t;
        int j=len;
        while(j>t)
        {
            if(ans[i]!=ans[j])
                break;
            i--,j--;
        }
        if(j==t)
        {
            flag=true;
            break;
        }
    }
    return flag;
}
int t;
bool dfs(int len)
{
    if(t==n)
        return true;
    if(len==80)
        return false;
    for(int i=0; i<l; i++)
    {
        ans[len+1]='A'+i;
        if(!check(len+1))
        {
            t++;
            if(dfs(len+1))
                return true;
        }
        ans[len+1]='\0';
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&l)==2&&(n!=0||l!=0))
    {
        memset(ans,0,sizeof(ans));
        t=0;
        dfs(0);
        int len=strlen(ans+1);
        for(int i=1; i<=len; i++)
        {
            printf("%c",ans[i]);
            if(i%64==0&&i<len)
            {
                printf("\n");
                continue;
            }
            if(i%4==0&&i<len)
                printf(" ");
        }
        printf("\n");
        printf("%d\n",len);
    }
    return 0;
}
