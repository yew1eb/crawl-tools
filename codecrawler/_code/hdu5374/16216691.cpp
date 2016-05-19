//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

char op[200010];
bool vis[22][22];
int n,len;
int ma[3][4][4][4],num[200010];


void init()
{
    ma[0][0][0][0]=ma[0][0][0][1]=ma[0][0][1][0]=ma[0][0][1][1]=1;
    ma[0][1][0][0]=ma[0][1][0][1]=ma[0][1][1][0]=ma[0][1][1][1]=1;
    ma[0][2][0][0]=ma[0][2][0][1]=ma[0][2][1][0]=ma[0][2][1][1]=1;
    ma[0][3][0][0]=ma[0][3][0][1]=ma[0][3][1][0]=ma[0][3][1][1]=1;

    ma[1][0][0][0]=ma[1][0][1][0]=ma[1][0][2][0]=ma[1][0][3][0]=1;
    ma[1][1][0][0]=ma[1][1][0][1]=ma[1][1][0][2]=ma[1][1][0][3]=1;
    ma[1][2][0][0]=ma[1][2][1][0]=ma[1][2][2][0]=ma[1][2][3][0]=1;
    ma[1][3][0][0]=ma[1][3][0][1]=ma[1][3][0][2]=ma[1][3][0][3]=1;

    ma[2][0][0][0]=ma[2][0][0][1]=ma[2][0][0][2]=ma[2][0][1][0]=1;
    ma[2][1][0][0]=ma[2][1][1][0]=ma[2][1][2][0]=ma[2][1][2][1]=1;
    ma[2][2][1][0]=ma[2][2][1][1]=ma[2][2][1][2]=ma[2][2][0][2]=1;
    ma[2][3][0][0]=ma[2][3][0][1]=ma[2][3][1][1]=ma[2][3][2][1]=1;
}

bool check(int ty,int now,int x,int y)
{
    if(x<1||x>12||y<1||y>9) return false;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(ma[ty][now][i][j] && (x+i>12||y+j>9||vis[x+i][y+j]))
                return false;
    return true;
}

void full(int ty,int now,int x,int y)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(ma[ty][now][i][j] && x+i<=12 && y+j<=9)
                vis[x+i][y+j]=1;
}

int sorce()
{
    bool tmp[22][22]={0};
    int top=0,sc=0;
    for(int i=1,j;i<=12;i++)
    {
        for(j=1;j<=9;j++)
            if(!vis[i][j])
                break;
        if(j<10)
        {
            top++;
            for(j=1;j<=9;j++)
                tmp[top][j]=vis[i][j];
        }
        else
        {
            sc++;
        }
    }
    CLR(vis,0);
    for(int i=1;i<=top;i++)
        for(int j=1;j<=9;j++)
            vis[i][j]=tmp[i][j];
    return sc;
}

void Print(int ty,int now,int x,int y,int change)
{
    bool tmp[22][22]={0};
    for(int i=1;i<=12;i++)
        for(int j=1;j<=9;j++)
            tmp[i][j]=vis[i][j];
    if(change)
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(ma[ty][now][i][j] && x+i<=12 && y+j<=9)
                    tmp[x+i][y+j]=1;

    for(int i=12;i;--i){
        cout<<i%10<<" : ";
        for(int j=1;j<=9;++j)
            cout<<tmp[i][j];
        printf("\n");
    }
    printf("\n");
}

int solve(int ty,int &t,int x,int y)
{
    int now=0;
    for(;t<len;t++)
    {
        switch(op[t])
        {
            case 'w':
                if(check(ty,(now+1)%4,x,y))
                    now=(now+1)%4;
                break;
            case 'd':
                if(check(ty,now,x,y+1))
                    y++;
                break;
            case 'a':
                if(check(ty,now,x,y-1))
                    y--;
                break;
            case 's':
                if(check(ty,now,x-1,y))
                    x--;
                break;
        }
        //Print(ty,now,x,y,1);
        if(check(ty,now,x-1,y))
        {
            x--;
        }
        else
        {
            full(ty,now,x,y);
            int ans=sorce();t++;
            //Print(ty,now,x,y,0);
            return ans;
        }
    }
    return sorce();
}

int main()
{
    init();
    int T,cas=1;
    read(T);
    while(T--)
    {
        read(n);
        gets(op);len=strlen(op);
        for(int i=0;i<n;i++)
            read(num[i]);
        int ans=0,j=0;
        CLR(vis,0);
        for(int i=0;i<n;i++)
        {

            ans+=solve(num[i],j,9,4);
        }

        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}