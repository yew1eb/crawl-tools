#include <iostream>

using namespace std;

int main()
{
 int N,A,B,cases=0;
 while (cin>>N>>A>>B)
 {
 cases++;
 int i=0,dig[100];
 while (N!=0)
 {
 if (N%B<A)
 {
 dig[i]=N%B+B;
 N=N/B-1;
 }
 else
 {
 dig[i]=N%B;
 N=N/B;
 }
 i++;
 }
 cout<<"Case "<<cases<<":";
 for (int j=i-1;j>=0;j--)
 {
 cout<<" "<<dig[j];
 }
 cout<<endl;
 }
 return 0;
}