#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct
{
    int p,th;
}price;
price a[2000000];
bool cmp1(price a,price b)
{
    if(a.p<b.p) return true;
    if(a.p>b.p) return false;
    return a.th<b.th;
}
bool cmp11(price a,price b)
{
    return a.th<b.th;
}
bool cmp22(price a,price b)
{
    return a.th>b.th;
}
int main()
{
    int n,p,q,count(0);
    while(scanf("%d%d%d",&n,&p,&q)!=EOF&&n&&p&&q)
    {
        for(int i=0;i<n;i++)
            a[i].th=i+1,scanf("%d",&a[i].p);
        printf("Case %d\n",++count);
        sort(a,a+n,cmp1);
        sort(a,a+p,cmp11);
        sort(a+n-q,a+n,cmp22);
        for(int i=0;i<p;i++)
            if(p-1-i) printf("%d ",a[i].th);
                else printf("%d\n",a[i].th);
        for(int i=0;i<q;i++)
            if(q-1-i) printf("%d ",a[n-q+i].th);
            else printf("%d\n",a[n-q+i].th);
    }
    return 0;
}