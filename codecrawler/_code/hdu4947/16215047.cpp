#include <cstdio>
#include <vector>
using namespace std;

long long node[50005];
int mu[200001],prime[200001],l,Q;
bool check[200001];
vector<int>fact[200001];

void Mobius()
{
    int i,j,cnt;

    cnt=0;
    mu[1]=1;

    for(i=2;i<=200000;i++)
    {
        if(!check[i])
        {
            prime[cnt++]=i;

            mu[i]=-1;
        }

        for(j=0;j<cnt;j++)
        {
            if(i*prime[j]>200000) break;

            check[i*prime[j]]=1;

            if(i%prime[j]) mu[i*prime[j]]=-mu[i];
            else break;
        }
    }

    for(i=1;i<=200000;i++) for(j=i;j<=200000;j+=i) fact[j].push_back(i);//æ±å å­
}

void add(int x,int v)
{
    while(x<=l)
    {
        node[x]+=v;

        x+=x&-x;
    }
}

long long sum(int x)
{
    long long res=0;

    while(x>0)
    {
        res+=node[x];

        x-=x&-x;
    }

    return res;
}

int main()
{
    int cases=1,t,n,d,v,i,last;
    long long ans,temp,lasttemp;

    Mobius();

    while(scanf("%d%d",&l,&Q) && l)
    {
        for(i=0;i<=l;i++) node[i]=0;

        printf("Case #%d:\n",cases++);

        while(Q--)
        {
            scanf("%d",&t);

            if(t==1)
            {
                scanf("%d%d%d",&n,&d,&v);

                if(n%d) continue;

                n/=d;

                for(i=0;i<fact[n].size();i++)
                {
                    t=fact[n][i];

                    add(t*d,mu[t]*v);
                }
            }
            else
            {
                scanf("%d",&n);

                ans=0;
                temp=0;

                for(i=1;i<=n;i=last+1)
                {
                    last=n/(n/i);

                    lasttemp=temp;//ååå é
                    temp=sum(last);

                    ans+=n/i*(temp-lasttemp);
                }

                printf("%I64d\n",ans);
            }
        }
    }
}
