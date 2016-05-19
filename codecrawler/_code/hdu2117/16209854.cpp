#include<stdio.h>
int main()
{
int r;
int n,m;
int i,j;
int num[100001];
while(scanf("%d%d",&n,&m)!=EOF)
{
    r=1;
for(i=0;i<=m;i++)
{
    if(r<n)
{
  num[i]=0;
}

if(r>=n)
{
   num[i]=r/n;
   r=r-num[i]*n;
}
r=r*10;

}
printf("%d\n",num[m]);
}
return 0;
}
