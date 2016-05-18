#include <iostream>

#define cl(a) memset(a,0,sizeof(a))
#define ss(a) scanf("%d",&a)
 
using namespace std;
 
struct node
{
    int v;
    int id;
};

const int N=1000100;
node a[N],b[N],c[N];

int main()
{
    int i,n,k,m,zmax,l1,r1,l2,r2,x;
    while (ss(n)!=EOF)
    {
        ss(m);ss(k);
        for (i=1;i<=n;i++) 
        {
            ss(a[i].v);
            a[i].id=i;
        }
        cl(b);cl(c);
        l1=0;r1=1;
        l2=0;r2=1;
        b[0].id=c[0].id=0;
        zmax=0;
        for (i=1;i<=n;i++)
        {
            while (l1<=r1&&b[r1].v<a[i].v) r1--;
            b[++r1]=a[i];
            while (l2<=r2&&c[r2].v>a[i].v) r2--;
            c[++r2]=a[i];
            while (l1<=r1&&l2<=r2&&b[l1].v-c[l2].v>k)
            {
                if (b[l1].id<c[l2].id) l1++;
                else l2++;
            }
            if (l1<=r1&&l2<=r2&&b[l1].v-c[l2].v>=m)
            {
                if (b[l1-1].id>c[l2-1].id) x=b[l1-1].id;
                else x=c[l2-1].id;
                zmax=max(zmax,i-x);
            }
        }
        if (zmax==1&&m>0) zmax=0;
        printf("%d\n",zmax);
    }
    return 0;
}
