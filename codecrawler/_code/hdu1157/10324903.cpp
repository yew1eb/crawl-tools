#include <iostream>
using namespace std;

int main()
{
    int n, i;
    int a[10000+10];
    while(cin>>n)
{
for(i=0; i<n; ++i) cin>>a[i];
  sort(a,a+n);
  cout<<a[n/2]<<endl;
}
return 0;
}