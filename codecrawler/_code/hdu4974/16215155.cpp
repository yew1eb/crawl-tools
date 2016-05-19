#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
const int maxn=101000;
using namespace std;
int a[maxn];

int main()
{
 int t,n,test=0;
 cin>>t;
 while(t--)
 {
  cin>>n;
  test++;
  if(n==0)
  {
   printf("Case #%d: %d\n",0);   
   continue;
  }
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  sort(a,a+n);

  int cnt=0,temp=a[n-1];
  for(int i=n-2;i>=0;i--)
  {
        if(temp>=a[i])
        {
           cnt+=a[i];
           temp=temp-a[i];
           a[i]=0;
        }
        else
        {
          cnt=cnt+temp;
          a[i]=a[i]-temp;
          temp=a[i];
        }
  }
  cnt+=temp;
  printf("Case #%d: %d\n",test,cnt);
 }
 return 0;
}
