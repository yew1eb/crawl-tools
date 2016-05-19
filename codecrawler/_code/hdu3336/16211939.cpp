#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 200005
#define mod 10007
int next[MAX],num[MAX];
char s[MAX];
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    for(; s[i];)
        if(j==-1||s[i]==s[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else  j=next[j];
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(;t--;)
    {
        int summ=0;
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        scanf("%s",s);
        get_next();
        for(int i=1;i<=n;++i)
           num[next[i]]=(num[next[i]]+1)%mod;
        for(int i=1;i<=n;++i)
           if(num[i])
              summ=(summ+num[i]+1)%mod;
            else
              summ=(summ+1)%mod;
        printf("%d\n",summ);
    }
    return 0;
}
