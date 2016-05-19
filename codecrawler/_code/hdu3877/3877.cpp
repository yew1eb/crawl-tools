#include<stdio.h>
#include<algorithm>
typedef long long ll;

using namespace std;

struct node
{
    ll a;
    ll b;
    ll ans;
    ll level;
};
node E[10005];

bool cmp(node x,node y)
{
    if((x.ans>y.ans)||(x.ans==y.ans&&x.level>y.level))
        return true;
    return false;
}

int main()
{
    ll t,n,i;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&E[i].a,&E[i].b);
            E[i].ans=E[i].a+E[i].b;
            if(E[i].a>E[i].b)
                E[i].level=3;
            else if(E[i].a==E[i].b)
                E[i].level=2;
            else
                E[i].level=1;
        }
        stable_sort(E+1,E+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            if(E[i].level==3)
                printf("%I64d+%I64d=[>%I64d]\n",E[i].a,E[i].b,E[i].ans);
            if(E[i].level==2)
                printf("%I64d+%I64d=[=%I64d]\n",E[i].a,E[i].b,E[i].ans);
            if(E[i].level==1)
                printf("%I64d+%I64d=[<%I64d]\n",E[i].a,E[i].b,E[i].ans);
        }
        printf("\n");
    }
    return 0;
}
