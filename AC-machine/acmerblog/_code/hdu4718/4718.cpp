#include<map>
#include<cstdio>
#include<iostream>
using namespace std;
#define ll  unsigned long long
#define mod 123
#define maxn 111111
map<ll,int>mp;
ll wei[maxn],h[maxn];
char ss[maxn];
int m,l,sum=0;
int main(){
    wei[1]=1;
    for(int i=2;i<=100011;++i)wei[i]=wei[i-1]*mod;
    
    while(~scanf("%d%d%s",&m,&l,ss+1)){
        sum=0;
        int len=(int)strlen(ss+1);
        int duan=m*l;
        h[0]=0;
        for(int i=1;i<=len;++i){
            h[i]=(ss[i]-'a'+1)+h[i-1]*mod;
        }
        ll ans;
        
        for(int i=1;i+duan-1<=len&&i<=l;++i){
            mp.clear();
            int st=i-1,ed=i-1;
            while(ed+=l){
                ans=h[ed]-h[ed-l]*wei[l+1];
                mp[ans]++;
                if(ed-st==duan){break;}
            }
            if(mp.size()==m){
                sum++;
            }
            while(1){
                if(ed+l>len)break;
                st+=l;
                ans=h[st]-h[st-l]*wei[l+1];
                mp[ans]--;
                if(mp[ans]==0)mp.erase(ans);
                ed+=l;
                ans=h[ed]-h[ed-l]*wei[l+1];
                mp[ans]++;
                if(mp.size()==m)sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}