

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstdlib>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
template<class T>inline T read(T&x)
{
    char c;
    while((c=getchar())<=32)if(c==EOF)return 0;
    bool ok=false;
    if(c=='-')ok=true,c=getchar();
    for(x=0; c>32; c=getchar())
        x=x*10+c-'0';
    if(ok)x=-x;
    return 1;
}
template<class T> inline T read_(T&x,T&y)
{
    return read(x)&&read(y);
}
template<class T> inline T read__(T&x,T&y,T&z)
{
    return read(x)&&read(y)&&read(z);
}
template<class T> inline void write(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<class T>inline void writeln(T x)
{
    write(x);
    putchar('\n');
}
//-------ZCC IO template------
const int maxn=500;
const double inf=999999999;
#define lson (rt<<1),L,M
#define rson (rt<<1|1),M+1,R
#define M ((L+R)>>1)
#define For(i,t,n) for(int i=(t);i<(n);i++)
typedef long long  LL;
typedef double DB;
typedef pair<int,int> P;
#define bug printf("---\n");
#define mod  100007

int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    while(read(n))
    {
        memset(a,0,sizeof(a));
        int maxv=0;
        For(i,0,n)
        {
            int tmp;
            read(tmp);
            a[tmp]++;
            maxv=max(maxv,tmp);
        }
        int k;
        read(k);
        sort(a,a+101,cmp);
        int i=0;
        while(a[i])i++;

        int sum=0;
        For(j,0,i)sum+=a[j];
        sum-=i;
        k-=sum;
        if(k<=0)writeln(i);
        else writeln(i-k<0?0:i-k);

    }
    return 0;
}

