#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a, d;
 int A[12], D[12];
 int i,j, k;
 while(cin>>a>>d)
 {
  if(a==d&&d==0) break;
  for(i=0;i<a;i++)
   cin>>A[i];
  for(i=0;i<d;i++)
   cin>>D[i];
  sort(A,A+a);
  sort(D,D+d);
  if(A[0]<D[1]) 
  {
   cout<<"Y\n";
   continue;
  }
  else
  {
   cout<<"N\n";
  }
 }
 return 0;
}