#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
using namespace std;
LL numx[15];
char num[15];
int len;
LL dfs(int x)
{
    if(x==len-1)
    {
        if(num[x]>='3') return 3;
        else            return (int)(num[x]-'0');
    }
    int idx=(num[x]>'3'?4:(int)(num[x]-'0'));
    LL a=numx[len-x-2]*idx,b=dfs(x+1);
    if(idx>3) return a;
    else      return a+b;
}
int main()
{
    numx[0]=3;
    for(int i=1;i<=10;++i) numx[i]=numx[i-1]*4;
    for(;~scanf("%s",num);)
    {
        LL summ=0;
        len=strlen(num);
        if(len==1)
        {
            if(num[0]>='3') printf("3\n");
            else            printf("%d\n",(int)(num[0]-'0'));
            continue;
        }
        printf("%I64d\n",dfs(0));
    }
    return 0;
}
