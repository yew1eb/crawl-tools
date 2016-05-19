#include <stdio.h>
int a[105];

int count(int x)
{
    int c = 0;
    for(;x;x>>=1) if(x&1) c++;
    return c;
}

int main()
{
    int b, i, j, n, m, k, min, t,cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++) scanf("%d",&a[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d",&b);
            min = count(b^a[0]);
            k = 0;
            for(j=1; j<n; j++)
            {
                t = count(b^a[j]);
                if(t<min||t==min&&a[j]<a[k]){ min = t;k = j;}
            }
            printf("%d\n",a[k]);
        }
    }
    return 0;
}







