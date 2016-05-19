#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=100010;
struct node
{
    int num0,num1,id;
    double ra;
}p[MAXN];
stack<node> S;
int a[MAXN];
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int l=0,r=n-1;
        while(a[l]==0)
            l++;
        while(a[r]==1)
            r--;
        if(l>r)
        {
            printf("0.000000\n");
            continue;
        }
        int id=0;
        for(i=l;i<=r;)
        {
            int j=0,k=0;
            while(a[i]==1)
            {
                i++;
                j++;
            }
            while(a[i]==0&&i<n) //è¿éå¯è½è¶åºnãå¤ç»è®¡äº0
            {
                i++;
                k++;
            }
            p[id].id=id;
            p[id].num0=k;
            p[id].num1=j;
            p[id++].ra=1.0*j/(j+k);
        }
        for(i=0;i<id;i++)

        {
            if(S.empty())
                S.push(p[i]);
            else
            {
                node temp=S.top();
                if(temp.ra<=p[i].ra)
                {
                    S.push(p[i]);
                    continue;
                }
                node g=p[i];
                while(1)
                {
                    temp=S.top();
                    if(temp.ra>g.ra)
                    {
                        g.num0+=temp.num0;
                        g.num1+=temp.num1;
                        g.ra=1.0*g.num1/(g.num0+g.num1);
                        S.pop();
                    }
                    else
                    {
                        S.push(g);
                        break;
                    }
                    if(S.empty())
                    {
                        S.push(g);
                        break;
                    }
                }
            }
        }
        double ans=0;
        while(!S.empty())
        {
            node temp=S.top();
            S.pop();
            ans+=1.0*temp.num1*(1-temp.ra)*(1-temp.ra)+1.0*temp.num0*temp.ra*temp.ra;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
