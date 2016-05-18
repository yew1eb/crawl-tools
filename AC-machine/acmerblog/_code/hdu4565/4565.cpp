#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct matrix
{
    long long num[2][2];
}matrix;
matrix m1;
matrix m2;
long long ans[2],ans1[2];
matrix multy(matrix m1,matrix m2,long long c)
{
    matrix temp;
    temp.num[0][0]=temp.num[1][0]=temp.num[0][1]=temp.num[1][1]=0;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                temp.num[i][j]+=m1.num[i][k]*m2.num[k][j]%c;
    return temp;
}
void quickpower(long long n,long long c)
{
    m2.num[0][0]=1,m2.num[0][1]=0,m2.num[1][0]=0,m2.num[1][1]=1;
    while(n)
    {
        if(n&1)
            m2=multy(m1,m2,c);
        m1=multy(m1,m1,c);
        n/=2;
    }
}
void out(matrix a)
{
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
            printf("%I64d ",a.num[i][j]);
        puts("");
    }
}
int main()
{
    long long a,b,n,c;
    while(~scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&c))
    {
        m1.num[0][0]=2*a;
        m1.num[0][1]=1;
        m1.num[1][0]=b-a*a;
        m1.num[1][1]=0;
        ans[1]=(long long)ceil((a+sqrt(b*1.0)))%c;
        ans[0]=(long long)ceil((a+sqrt(b*1.0))*(a+sqrt(b*1.0)))%c;
        if(n==1)
        {
            printf("%I64d\n",ans[1]);
            continue;
        }
        if(n==2)
        {
            printf("%I64d\n",ans[0]);
            continue;
        }
        quickpower(n-2,c);
        ans1[0]=(ans[0]*m2.num[0][0]+ans[1]*m2.num[1][0])%c;
        ans1[1]=(ans[0]*m2.num[0][1]+ans[1]*m2.num[1][1])%c;
        printf("%I64d\n",(ans1[0]%c+c)%c);
    }
    return 0;
}