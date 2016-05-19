#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,m;
int next[10011];
int a[1000111];
int b[10011];
void getnext()
{
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while(j<m)
    {
        if(k==-1 || b[j]==b[k])    next[++j]=++k;
        else                    k=next[k];
    }
}
int KMP()
{
    int i,j;
    j=0;
    for(i=0;i<n;)
    {
        if(a[i]==b[j])
        {
            if(j==m-1)    return i-(m-1)+1;
            i++;j++;
        }
        else
        {
            j=next[j];
            if(j==-1)    {i++;j=0;}
        }
    }
    return -1;
}
int main()
{
    int T;
    int i;
    int ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)    scanf("%d",&a[i]);
        for(i=0;i<m;i++)    scanf("%d",&b[i]);

        if(n<m)    {printf("-1\n");continue;}

        getnext();
        ans=KMP();
        printf("%d\n",ans);
    }
    return 0;
}