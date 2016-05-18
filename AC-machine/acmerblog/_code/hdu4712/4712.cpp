#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<cstdio>

using namespace std;

int a[100005];

int hamming(int x,int y)
{
    x=x^y;
    int count=0;
    while(x)
    {
       x&=x-1;
       count++;
    }
    return   count;
}

int min(int &a,int &b)
{
    return  a<b?a:b;
}
int main()
{
   int T;
   cin>>T;

   srand(time(0));
   int n;
  while(cin>>n)
  {
    for(int i=0;i<n;i++)
      scanf("%x",&a[i]);
    int  test=100000;
    int x,y;
    int ans=100;
    while(test--)
    {
        x=rand()%n;
        y=rand()%n;

        while(x==y)
        x=rand()%n;

        ans=min(ans,hamming(a[x],a[y]));
    }

    cout<<ans<<endl;
  }


}
