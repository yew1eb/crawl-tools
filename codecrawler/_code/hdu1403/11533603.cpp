#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200000+10;

int sa[maxn],rank[maxn],height[maxn],num[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];
char s[maxn];

inline int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

void da(int *r,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wd[i]=0;
    for(i=0;i<n;i++) wd[x[i]=r[i]]++;
    for(i=1;i<m;i++) wd[i]+=wd[i-1];
    for(i=n-1;i>=0;i--) sa[--wd[x[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wd[i]=0;
        for(i=0;i<n;i++) wd[wv[i]]++;
        for(i=1;i<m;i++) wd[i]+=wd[i-1];
        for(i=n-1;i>=0;i--) sa[--wd[wv[i]]]=y[i];
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}

int main()
{
    int i,k,l1,l2;
    cin.sync_with_stdio(false);
    while(cin.getline(s,maxn))
    {
        l1=strlen(s);
        for(k=i=0;i<l1;i++) num[k++]=s[i]-95;//´Ó2¿ªÊ¼
        num[k++]=1;//ÒÔ1·Ö¸ôÁ½¸ö´®
        cin.getline(s,maxn);
        l2=strlen(s);
        for(i=0;i<l2;i++) num[k++]=s[i]-95;
        da(num,l1+l2,30);
        calheight(num,l1+l2);
        int ans=0;
        for(i=2;i<k;i++)
            if((sa[i]<l1)^(sa[i-1]<l1)) ans=ans>height[i]?ans:height[i];
        cout<<ans<<endl;
    }
    return 0;
}
