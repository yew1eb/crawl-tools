#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;
#define PD(x) (scanf("%d",&x))
#define PP(a,b) (scanf("%d%d",&a,&b))
#define PR(a) (printf("%d\n",a))
#define N 105

vector<int> G;
int p;
bool is(int a,int b,int times,int correct)
{
    int aa = 0;
    int bb = 0;
    int ar[5];
    int arr[5];
    int c[10];
    memset(c,0,sizeof(c));
    for(int i=0;i<4;i++)
    {
        ar[i] = a%10;
        c[ar[i]]++;
        a/=10;
        arr[i] = b%10;
        b/=10;
        if(ar[i]==arr[i]) aa++;
    }
    for(int i=0;i<4;i++)
        if(c[arr[i]]){bb++;c[arr[i]]--;}
    if(times==aa&&correct==bb) return true;
    return false;
}
void deal(int a,int b,int c)
{
    int k = 0;
    for(int i=0;i<p;i++)
    {
        if(is(G[i],a,c,b))
            G[k++] = G[i];
    }
    /*for(int i=0;i<k;i++)
        cout<<G[i]<<" ";
    cout<<endl;*/
    p = k;
}
void reinit()
{
    p = 0;
    if(!G.empty()) G.clear();
    for(int i=1000;i<10000;i++,p++)
        G.push_back(i);
}
void init()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
      if(n==0) break;

      reinit();
      for(int i=0;i<n;i++)
      {
          int a,b,c;
          PP(a,b),PD(c);
          deal(a,b,c);
      }
     // cout<<p<<endl;
      if(p==1)
          PR(G[0]);
      else puts("Not sure");
  }
}
int main()
{
    init();
    return 0;
}
