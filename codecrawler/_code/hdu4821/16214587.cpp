#include<stdio.h>
#include<string.h>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define rep(i,s,t) for(int i=s;i<t;i++)
typedef unsigned long long ull;
const ull B=100000007;
int m,l,len;
char s[100005];
ull ll[100005];
ull a,t;
ull b[100005],c[100005];
int cnt;
map<ull,bool>mp;

inline int solve(int i,int len){
    mp.clear();
    cnt=0;
    int ans=0;
    for(int j=i;j<len;j+=l){
        b[cnt++]=ll[j];
    }
    //rep(j,0,cnt) printf("%llu\n",b[j]);
    int s=0,t=0;
    rep(j,0,cnt){
        c[t++]=b[j];
        if(mp[b[j]]){
            while(s<t && c[s]!=b[j]) mp[c[s++]]=0;
            mp[c[s++]]=0;
        }    
        mp[b[j]]=1;
        while(t-s>m) mp[c[s++]]=0;
        //printf("%d %d\n",t,s);
        if(t-s==m) ans++;
    }
    return ans;
}
int main(){
    while(~scanf("%d%d",&m,&l)){
        scanf("%s",s);len=strlen(s);
        t=1;rep(i,0,l) t*=B;
        a=0;rep(i,0,l) a=a*B+s[i];
        ll[l-1]=a;
        rep(i,l,len) ll[i]=ll[i-1]*B+s[i]-s[i-l]*t;
        int ans=0;
        rep(i,l-1,l*2-1){
            ans+=solve(i,len);
            //printf("\n");
        }
        printf("%d\n",ans);
    }    
    return 0;
}