#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int a[1002], b;
vector <int> ans;
int main()
{
 int test; scanf("%d", &test);
 for (int cas=1; cas<=test; cas++)
 {
 ans.clear();
 int n; scanf("%d", &n);
 for (int i=0; i<n; i++)
 {
 for (int j=0; j<n; j++)
 {
 scanf("%d", &b);
 if (b==1) a[i]=j;
 }
 }
 for (int i=0; i<n; i++)
 {
 for (int j=i+1; j<n; j++)
 {
 if (a[j]==i)
 {
 for (int k=j-1; k>=i; k--)
 a[k+1]=a[k], ans.push_back(k);
 break;
 }
 }
 a[i]=i;
 // for (int j=0; j<n; j++)
 // printf("%d ", a[j]);
 // putchar(10);
 }
 printf("Case %d: %d\n", cas, (int)ans.size());
 for (int i=0; i<ans.size(); i++)
 if (i==ans.size()-1) printf("%d", ans[i]);
 else printf("%d ", ans[i]);
 putchar(10);
 }
 return 0;
}