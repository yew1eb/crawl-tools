#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
char c[200005],f[100005];
int r[200005],bit[200005];
int d[200005];
LL s[200005],s1[200005];
int low(int n){return n&(-n);}
void merg(int p,int n,int k){
    while(p<=n){
        bit[p]+=k;
        p=p+low(p);
    }
}
int sum(int p){
    int s=0;
    while(p>0){
        s+=bit[p];
        p=p-low(p);
    }
    return s;
}
void mancher(int n){
    int i,id,mx;
    r[0]=1;
    mx=0;
    id=0;
    for(i=1;i<=2*n;i++){
        if(i>=mx) r[i]=1;
        else r[i]=min(r[id-(i-id)],mx-i);
        while(i-r[i]>=0&&i+r[i]<=2*n&&c[i-r[i]]==c[i+r[i]]) r[i]++;
        if(i+r[i]>mx){
            mx=i+r[i];
            id=i;
        }
    }
}
void get_back(int n){
    int i,j,p;
    memset(bit,0,sizeof(bit));
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s1));
    for(i=1;i<=2*n;i++){
        p=i+r[i]-1;
        if(i%2==0){
            if(p>i){
                merg(i/2+1,n,1);
                merg(p/2+1,n,-1);
            }
        }
        else{
                merg((i+1)/2,n,1);
                merg(p/2+1,n,-1);
        }
    }
    s[0]=0;
    s1[0]=0;
    for(i=1;i<=n;i++){
        d[i]=sum(i);
        s[i]=s[i-1]+d[i];
        s1[i]=s1[i-1]+s[i];
    }
}
void work(int n){
    LL s=0;
    int i,j;
    for(i=1;i<=2*n;i++){
        if(i%2==0){
            if(r[i]>1){
                if((i-r[i]+1)/2!=0)
                s+=s1[i/2-1]-s1[(i-r[i]+1)/2-1];
                else s+=s1[i/2-1];
            }
        }
        else{
            if((i-r[i]+1)/2!=0)
            s+=s1[(i+1)/2-1]-s1[(i-r[i]+1)/2-1];
            else s+=s1[(i+1)/2-1];
        }
    }
    cout<<s<<endl;
}
int main()
{
    int i,j,n;
    while(scanf("%s",f)!=EOF){
        n=strlen(f);
        c[0]='#';
        for(i=1;i<=n;i++){
            c[2*i]='#';
            c[2*i-1]=f[i-1];
        }
        mancher(n);
        get_back(n);
        work(n);
    }
}