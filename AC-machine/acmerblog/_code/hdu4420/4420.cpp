#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int s[10000],hash[200000];
int hit[10000],in[10000];
int a[2],i,j,pot,l_hit,l_in,n,m,flag,flag_pot;

void set()
{
    for(int k=0; k<l_in; k++)
        hash[in[k]]=1;
    while(hash[s[pot]])
        pot++;
    flag=1-flag;
}

void solve()
{
    int sum=0;
    for(int k=0; k<l_in; k++)
        sum+=in[k];
    if(l_hit==0) //没击中球
    {
        a[1-flag]+=s[pot];
    }
    else if(in[0]==0&&l_in!=0) //先判断是否有球入袋
    {
        a[1-flag]+=hit[l_hit-1];
    }
    else if(l_hit>1||(l_hit==1&&hit[0]!=s[pot])) //过多或不是目标球
    {
        a[1-flag]+=hit[l_hit-1];
    }
    else //无犯规
    {
        if(flag_pot) //目标球进了
        {
            a[flag]+=sum;
            flag=1-flag;
            return;
        }
    }
    if(in==0) return;
    a[1-flag]+=sum;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        a[1] = a[0] = 0;
        for(i = 1; i<=n; i++)
            scanf("%d",&s[i]);
        sort(s+1,s+n+1);
        memset(hash,0,sizeof(hash));
        flag = 0;
        pot = 1;
        for(i = 0; i<m; i++)
        {
            flag_pot = 0;
            scanf("%d",&l_hit);
            for(j = 0; j<l_hit; j++)
                scanf("%d",&hit[j]);
            scanf("%d",&l_in);
            for(j = 0; j<l_in; j++)
            {
                scanf("%d",&in[j]);
                if(in[j] == s[pot])
                flag_pot = 1;
            }
            sort(hit,hit+l_hit);
            sort(in,in+l_in);
            solve();
            set();
        }
        printf("%d : %d\n",a[0],a[1]);
    }

    return 0;
}
