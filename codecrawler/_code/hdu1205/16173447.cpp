#include <iostream>
using namespace std;

int main()
{
 int ncases;
 scanf("%d",&ncases);

 while(ncases--)
 {
  __int64 maxvalue=-1,sweetkinds,sum=0;
  scanf("%I64u",&sweetkinds);

  __int64 i,n;
  for(i=0;i<sweetkinds;i++)
  {
   scanf("%I64u",&n);
   sum+=n;
   if(maxvalue<n)
    maxvalue=n;
  }
  if((sum-maxvalue)>=(maxvalue-1))
   printf("Yes\n");
  else
   printf("No\n");
 }
 return 0;
}