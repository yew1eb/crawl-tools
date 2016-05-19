#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100100

int sa[N],t[N],t2[N],c[N];
char ss[N];
int s[N];
void build_sa(int n,int m)
{
    int *x=t,*y=t2;
    for(int i=0;i<m;++i) c[i]=0;
    for(int i=0;i<n;++i) c[x[i]=s[i]]++;
    for(int i=1;i<m;++i) c[i]+=c[i-1];
    for(int i=n-1;i>=0;--i) sa[--c[x[i]]]=i;

    for(int k=1;k<=n;k<<=1)
    {
        int p=0;
        for(int i=n-k;i<n;++i) y[p++]=i;
        for(int i=0;i<n;++i) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(int i=0;i<m;++i) c[i]=0;
        for(int i=0;i<n;++i) c[x[y[i]]]++;
        for(int i=1;i<m;++i) c[i]+=c[i-1];
        for(int i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;++i)
            x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
int rk[N],height[N];
void cal_height(int n)
{
    for(int i=1;i<=n;++i) rk[sa[i]]=i;// å ä¸ºsa[0]=n
    for(int i=0,k=0;i<n;++i)
    {
        if(k) k--;
        int j=sa[rk[i]-1]; // 1<=rk[i]<=nï¼ä¸ä¼æº¢åº
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;// rk[i]:1-n, i:0-n-1
    }
}
int d[N][30];
void init_RMQ(int n)
{
    for(int i=1;i<=n;++i) d[i][0]=height[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
        d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int query_RMQ(int l,int r) // å¿é¡»æ»¡è¶³l!=r
{
    l=rk[l];r=rk[r];
    if(l>r) swap(l,r); // l,råå¼èå´: 1-n
    l++;
    int k=0;
    while((1<<(1+k))<=r-l+1) k++;
    return min(d[l][k],d[r-(1<<k)+1][k]);
}
int change(int a)
{
    if(a<10) return 1;
    else if(a<100) return 2;
    else if(a<1000) return 3;
    else if(a<10000) return 4;
    else if(a<100000) return 5;
}
int n;
int main ()
{
    while(scanf("%s",ss)!=EOF)
    {
        n=strlen(ss);
        for(int i=0;i<n;++i)
            s[i]=ss[i]-'a'+1;
        s[n]=0;
        build_sa(n+1,30);
        cal_height(n);
        init_RMQ(n);

        int q;scanf("%d",&q);
        long long len1=0,len2=0;
        for(int kk=1,u,v,lcp,preu=-1,prev=-1;kk<=q;++kk)
        {
            scanf("%d%d",&u,&v);
            if(preu>=0)
            {
                if(u==preu)
                    lcp=n-u;
                else lcp=query_RMQ(u,preu);
                lcp=min(lcp,min(v-u,prev-preu));
                len2+=change(lcp)+v-u-lcp;
            }
            else len2+=1+v-u;
            len1+=v-u+1;
            len2+=2;
            preu=u;prev=v;
        }
        cout<<len1<<' '<<len2<<endl;
    }
    return 0;
}
