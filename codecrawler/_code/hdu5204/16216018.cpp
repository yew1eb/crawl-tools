#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int SIGMA_SIZE=70;
typedef long long LL;
int N,cnt;
int X[maxn];
LL s[maxn];
int pos[maxn];
bool cmp(int x,int y)
{
    return X[cnt-x]<X[cnt-y];
}
void process(LL x,int c)
{
    for(int i=0;i<=SIGMA_SIZE;i++)
        s[i]+=c*((x+1)/2),x/=2;
}
int main()
{
    int op;
    LL x,y,k;
    while(scanf("%d",&N)!=EOF)
    {
        cnt=0;
        while(N--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                int tmp;
                scanf("%d",&tmp);
                X[++cnt]=tmp;
            }
            else
            {
                scanf("%I64d%I64d%I64d",&x,&y,&k);
                int ans=0;
                for(int i=0;i<=SIGMA_SIZE;i++)
                    s[i]=0;
                process(y,1);
                process(x-1,-1);
                for(int i=0;i<=SIGMA_SIZE;i++)
                    pos[i]=i;
                sort(pos,pos+SIGMA_SIZE+1,cmp);
                LL sum=0;
                for(int i=0;i<=SIGMA_SIZE;i++)
                {
                    if(sum+s[pos[i]]>=k)
                    {
                        printf("%d\n",X[cnt-pos[i]]);
                        break;
                    }
                    else sum+=s[pos[i]];
                }
            }
        }
    }
    return 0;
}
