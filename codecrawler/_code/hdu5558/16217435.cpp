#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int maxn=110000;
struct Suffix{
    Suffix(){}
    char s[maxn];int rk[maxn],h[maxn],c[maxn],t[maxn],sa[maxn];
    void build(){
        int *x=t,*sa2=rk,m=200;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[i]=s[i]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1){
            int p=0;
            for(int i=n-k;i<n;i++)sa2[p++]=i;
            for(int i=0;i<n;i++)if(sa[i]>=k)sa2[p++]=sa[i]-k;
            for(int i=0;i<m;i++)c[i]=0;
            for(int i=0;i<n;i++)c[x[sa2[i]]]++;
            for(int i=1;i<m;i++)c[i]+=c[i-1];
            for(int i=n-1;i>=0;i--)sa[--c[x[sa2[i]]]]=sa2[i];
            swap(x,sa2);
            p=1;x[sa[0]]=0;
            for(int i=1;i<n;i++)
                x[sa[i]]=sa2[sa[i-1]]==sa2[sa[i]]&&sa2[sa[i-1]+k]==sa2[sa[i]+k]?p-1:p++;
            if(p>=n)break;
            m=p;
        }
    }
    int rank[maxn];
    void calheignt(){
        int k=0;
        for(int i=0;i<n;i++)rank[sa[i]]=i;h[0]=0;
        for(int i=0;i<n-1;i++){
            if(k)k--;
            int j=sa[rank[i]-1];
            while(s[i+k]==s[j+k])k++;
            h[rank[i]]=k;
        }
    }
    int _st[maxn][20],pow2[20],n_st[maxn][20];
    void st_build(){
        pow2[0]=1;for(int i=1;i<=19;i++)pow2[i]=pow2[i-1]*2;
        for(int i=n-1;i>=0;i--){
            _st[i][0]=h[i];n_st[i][0]=sa[i];
            for(int j=1,k=1;2*j+i-1<n;j<<=1,k++){
                _st[i][k]=min(_st[i][k-1],_st[i+j][k-1]);
                n_st[i][k]=min(n_st[i][k-1],n_st[i+j][k-1]);
            }
        }
    }
    int st_query(int l,int r){
        int k=(int)log2(r-l+1);
        return min(_st[l][k],_st[r-pow2[k]+1][k]);;
    }
    int n_st_query(int l,int r){
        int k=(int)log2(r-l+1);
        return min(n_st[l][k],n_st[r-pow2[k]+1][k]);
    }
}S;
int queryl(int x){
    int l=1,r=x-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(S.n_st_query(mid,x-1)<S.sa[x])l=mid+1;
        else r=mid-1;
    }
    return l-1;
}
int queryr(int x){
    int l=x+1,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(S.n_st_query(x+1,mid)<S.sa[x])r=mid-1;
        else l=mid+1;
    }
    return l;
}
int queryll(int x,int v){
    int l=1,r=x-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(S.st_query(mid+1,x)<v)l=mid+1;
        else r=mid-1;
    }
    return r+1;
}
int queryrr(int x,int v){
    int l=x+1,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(S.st_query(x+1,mid)<v)r=mid-1;
        else l=mid+1;
    }
    return l-1;
}
void work(int no){
    printf("Case #%d:\n",no);
    scanf("%s",S.s);n=strlen(S.s);S.s[n]='@';n++;
    printf("-1 %d\n",S.s[0]);
    S.build();
    S.calheignt();
    S.st_build();
    for(int i=1;i<n-1;){
        i=S.rank[i];
        int l=queryl(i);
        int x=0;
        if(l>0)x=S.st_query(l+1,i);
        int r=queryr(i);
        int y=0;
        if(r<n)y=S.st_query(i+1,r);
        if(y>x){
            int c=queryrr(i,y);
            int z=S.n_st_query(i,c);
            printf("%d %d\n",y,z);
            i=S.sa[i];i+=y;
        }else if(y<x){
            int c=queryll(i,x);
            int z=S.n_st_query(c,i);
            printf("%d %d\n",x,z);
            i=S.sa[i];i+=x;
        }else if(y==x){
            if(x==0){
                    i=S.sa[i];
                printf("-1 %d\n",S.s[i]);
                i++;
            }else{
                int c=queryll(i,y);
                int z=S.n_st_query(c,i);
                c=queryrr(i,x);
                z=min(z,S.n_st_query(i,c));
                printf("%d %d\n",x,z);
                i=S.sa[i];i+=x;
            }
        }
    }

}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++)work(i);
    return 0;
}