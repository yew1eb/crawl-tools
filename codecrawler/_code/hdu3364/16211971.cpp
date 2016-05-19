#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=55;
struct matrix{
    int f[maxn][maxn];
}e,g;
int find(matrix a,int m,int n)//é«æ¯æ¶å
{
    int i=1,j=1,k,r,u;
    while(i<=m&&j<=n)//å¤çç¬¬iä¸ªæ¹ç¨ï¼ç¬¬jä¸ªåé
    {
        r=i;
        for(k=i;k<=m;k++)
        if(a.f[k][j]){r=k;break;}
        if(a.f[r][j])
        {
            if(r!=i)for(k=0;k<=n+1;k++)swap(a.f[r][k],a.f[i][k]);
            for(u=i+1;u<=m;u++)if(a.f[u][j])
                for(k=i;k<=n+1;k++)a.f[u][k]^=a.f[i][k];
            i++;
        }
        j++;
    }
    for(u=i;u<=m;u++)//å¤æ­æ è§£
        if(a.f[u][n+1])return -1;
    return i-1;
}
int main()
{
    int T,tt=0;
    cin>>T;
    while(T--)
    {
        int i,j,k,n,m,a,b,q,r;
        cin>>n>>m;
        memset(e.f,0,sizeof(e.f));
        for(i=1;i<=m;i++)
        {
            cin>>k;
            for(j=0;j<k;j++)
            {
                cin>>a;
                e.f[a][i]=1;
            }
        }
        cout<<"Case "<<++tt<<":"<<endl;
        cin>>q;
        while(q--)
        {
            for(i=1;i<=n;i++)
            {
                cin>>a;
                e.f[i][m+1]=a;
            }
            r=find(e,n,m);//æ±åºæçéåä¸ªæ°r
            if(r==-1)cout<<0<<endl;
            else cout<<(1LL<<(m-r))<<endl;//æ³¨æèå´ï¼è¶int
        }
    }
    return  0;
}
/*
    è®¾mä¸ªå¼å³ç¶æä¸ºxi(1<=i<=m,0<=xi<=1)ï¼å¯åmåä¸æ¬¡æ¹ç¨ç»ãç¨é«æ¯æ¶åæ³æ±å¾èªç±åéä¸ªæ°kãç­æ¡å°±æ¯2^k
*/