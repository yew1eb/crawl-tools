#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1005

int m,n;
char a[N];
char num[N];
int f[N][N];

int min(int i,int j)
{
    return a[i]<=a[j] ? i:j;
}

void ST()
{
    int i,j;
    for(i=0;i<n;i++)
       f[i][0]=i;
    for(j=1;j<=(int)(log((double)n)/log(2.0));j++)
    {
        for(i=0;i+(1<<j)-1<n;i++)
           f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
}

int query(int L,int R)
{
    int x=(int)(log(double(R-L+1))/log(2.0));
    return min(f[L][x],f[R-(1<<x)+1][x]);
}

int main()
{
    int i,j,L,R;
    while(~scanf("%s%d",a,&m))
    {
        int len=strlen(a);
        n=len;
        m=len-m;
        ST();
        i=j=0;
        while(m--)
        {
            i=query(i,len-m-1);
            num[j++]=a[i++];
        }
        for(i=0;i<j;i++)
        {
            if(num[i]!='0')
               break;
        }
        if(i==j)
        {
            puts("0");
            continue;
        }
        while(i<j)
        {
            printf("%c",num[i]);
            i++;
        }
        puts("");
    }
    return 0;
}
