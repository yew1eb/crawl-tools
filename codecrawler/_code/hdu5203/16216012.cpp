#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>


#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define eps 1e-8
typedef long long ll;

#define fre(i,a,b)  for(i = a; i <b; i++)
#define free(i,b,a) for(i = b; i >= a;i--)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define ssf(n)      scanf("%s", n)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf          printf
#define bug         pf("Hi\n")

using namespace std;

#define INF 0x3f3f3f3f
#define N 400

int n,m;
int le,ri;
int a,b;

void fdd()
{
   a=a+b;
   int i,j;
   ll ans=0;
   for(i=1;i*2<a;i++)
   {
        int t=a-i-i;
        t/=2;
        t++;
        int to=a-i-t;
        if(to<t) continue;
        if(t==0) continue;
        ans+=to-t+1;

   }
  pf("%I64d\n",ans);
}

int judge(int x,int y,int z)
{

    if(x+y<=z||x+z<=y) return 0;
    return 1;
}

void solve()
{
    int i,j;
    if(a==0||b==0)
    {
        fdd();
        return ;
    }
    ll ans=0;
    if(a>b) swap(a,b);

    for(i=1;i<b;i++)
    {
        if(judge(a,i,b-i))
            ans++;

    }
    printf("%I64d\n",ans);
}

int main()
{
   int i,j;
   while(~scanf("%d%d",&n,&m))
   {
       le=INF;
    ri=-1;
    int x;
    while(m--)
    {
        sf(x);
        le=min(le,x);
        ri=max(ri,x);
    }
     a=le-1;
     b=n-ri;

     if(a==b)
     {
         pf("0\n");
         continue;
     }
    
     solve();
   }
   return 0;

}

/*

8 1
1

*/
