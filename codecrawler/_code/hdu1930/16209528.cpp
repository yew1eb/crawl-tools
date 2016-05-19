#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LL __int64
using namespace std;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b)
        d=a,x=1,y=0;
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=(a/b)*x;
    }
}
char mark[30]="AABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char s[200];
LL aa[5],bb[5],n,c[55],m1;
LL reminder()
{
    LL m2,r1,r2,c,t,d,x,y;
    m1=aa[0],r1=bb[0];
    for(int i=1;i<4;i++)
    {
        m2=aa[i],r2=bb[i];
        exgcd(m1,m2,d,x,y);
        c=r2-r1;
        t=m2/d;
        x=(c/d*x%t+t)%t;
        r1=m1*x+r1;
        m1=m1*m2/d;
    }
    return r1;
}
int main()
{
    LL temp;
    int i,t,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(i=0;i<4;i++)
            scanf("%I64d",&aa[i]);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&temp);
            for(j=3;j>=0;j--)
            {
                bb[j]=temp%100;
                temp/=100;
            }
            int x=reminder();
            c[i]=x;
        }
        int len=0;
        for(i=0;i<n;i++)
        {
            vector<int> q;
            temp=c[i];
            while(temp)
            {
                q.push_back(temp%100);
                temp/=100;
            }
            while(!q.empty())
            {
                temp=q.back();
                q.pop_back();
                s[len++]=mark[temp];
            }
        }
        while(s[len-1]==' ')
            len--;
        for(i=0;i<len;i++)
        printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
