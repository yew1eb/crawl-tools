#include<cstdio>
#include<iostream>
using namespace std;
const int N=110;
const int M=100001;
double safety[N],bag[M];
int money[N];
int sum,n;

void beibao()
{
 int i,j;
 for(i=0;i<=sum;i++)
  bag[i]=0.0;
 bag[0]=1.0;
 for(i=1;i<=n;i++)
  for(j=sum;j>=money[i];j--)
  {
   bag[j]=bag[j]>(bag[j-money[i]]*safety[i])?bag[j]:(bag[j-money[i]]*safety[i]);
  }
}

int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  double p;
  scanf("%lf%d",&p,&n);
  int i,j;
  sum=0;
  for(i=1;i<=n;i++)
  {
   scanf("%d%lf",&money[i],&safety[i]);
   safety[i]=1.0-safety[i];
   sum+=money[i];
  }
  beibao();
  p=1.0-p;
  for(i=sum;bag[i]<p;i--);
  printf("%d/n",i);
 }
 return 0;
}