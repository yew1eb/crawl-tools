#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 500005
char s[MAX<<1];
int nextx[MAX<<1],value[30];
int summ[MAX],v[2][MAX];
int n,m;
void get_nextx()
{
    int i=0,j=-1;
    nextx[0]=-1;
    for(;i<m;)
        if(j==-1||s[i]==s[j])
        {
            ++i;++j;
            nextx[i]=j;
        }
        else j=nextx[j];
}
void check(int x)
{
    summ[0]=0;
    for(int i=0;i<n;++i)
        summ[i+1]=summ[i]+value[s[i]-'a'];
    reverse_copy(s,s+n,s+n+1);
    s[n]='#';
    get_nextx();
    memset(v[x],0,sizeof(v[x]));
    int p=m;
    for(;;)
    {
        p=nextx[p];
        if(!~p) break;
        v[x][p]=summ[p];
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(;cas--;)
    {
        int ans=-((1<<25)-1);
        for(int i=0;i<26;++i) scanf("%d",&value[i]);
        scanf("%s",s);
        n=strlen(s);
        m=2*n+1;
        check(0);
        reverse(s,s+n);
        check(1);
        reverse(v[1],v[1]+n+1);
        for(int i=1;i<n;++i)
            ans=max(ans,v[0][i]+v[1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
