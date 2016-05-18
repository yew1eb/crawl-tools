#include<stdio.h>
#define inf 0x7fffffff
struct node
{
int l;
int r;
__int64 w;
}p[1000000];
__int64 a[1000000];
int main()
{
int t,i,k,n;
scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
scanf("%I64d",&a[i]);
p[i].w=a[i];
p[i].l=p[i].r=i;
 }
    p[0].w=0;
   p[0].l=1;
    __int64 max=-inf;
    for(i=1;i<=n;i++)
{
  if(p[i].w<=p[i-1].w+a[i])
  {
p[i].w=p[i-1].w+a[i];
p[i].l=p[i-1].l;

  }
 if(p[i].w>max)
 {
max=p[i].w;
k=i;
 }
}
  printf("%I64d %d %d\n",max,p[k].l,p[k].r);


  }
}