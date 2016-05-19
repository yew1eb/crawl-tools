#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
  int T,n;
  scanf("%d",&T);
  vector< pair<int ,int > >v;
  while(T--)
  {
    scanf("%d",&n);
    v.clear();
    for(int i=0;i<n;i++)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       v.push_back(make_pair(a,1));
       v.push_back(make_pair(b+1,-1));
    }
    sort(v.begin(),v.end());
    int len=v.size(),sum=0,ans=0;
    for(int i=0;i<len;i++)
    {
      sum+=v[i].second;
      if(sum>ans)ans=sum;
    }
    printf("%d\n",ans);
  }
  return 0;
}
