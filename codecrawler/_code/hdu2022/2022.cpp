#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct hx
{
    int fs;
    int hh;
    int lh;
}w[10001];
bool comp(hx x,hx y)
{
    if(abs(x.fs)>abs(y.fs)) return true;
    if(abs(x.fs)==abs(y.fs)&&x.hh<y.hh) return true;
    if(abs(x.fs)==abs(y.fs)&&x.hh==y.hh&&x.lh<y.lh) return true;
    return false;
}
int main()
{
    int n,m,i,j,count,cj;
    while(~scanf("%d %d",&n,&m))
    {
        count=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&cj);
                w[count].hh=i;
                w[count].lh=j;
                w[count].fs=cj;
                count++;
            }
        }
        sort(w,w+count,comp);
        printf("%d %d %d\n",w[0].hh,w[0].lh,w[0].fs);
    }
    return 0;
}