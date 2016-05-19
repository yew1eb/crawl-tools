#include<stdio.h>
#include<algorithm>
using namespace std;
struct bb
{
    double get,pay;
    double ave;
}w[10001];
bool comp(bb x,bb y)
{
    if(x.ave>y.ave) return true;
    return false;
}
int main()
{
    int n,m,i;
    double sum;
    while(scanf("%d %d",&m,&n))
    {
        if(m==-1&&n==-1) break;
        sum=0;
        for(i=0;i<=n-1;i++)
        {
            scanf("%lf %lf",&w[i].get,&w[i].pay);
            w[i].ave=w[i].get/w[i].pay;
        }
        sort(w,w+n,comp);
        for(i=0;i<=n-1;i++)
        {
            if(m>=w[i].pay)
            {
                sum=sum+w[i].get;
                m=m-w[i].pay;
            }
            else
            {
                sum=sum+w[i].ave*m;
                break;
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}