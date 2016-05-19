#include <iostream>
#include <cstdio>
#define LL __int64
using namespace std;

const LL inf=10000000000000ll;
const int root=0;
LL f[60],ans[60];

int trie[550][10],bit[30],fail[550],que[550],head,tail;
int tot;
int nxt[550][10];
LL dp[15][550];
bool tag[550];

void insert(LL now){
    int len=0;
    while(now){
        bit[++len]=now%10;
        now/=10;
    }
    int p=root,i=len;
    while(i--){
        if(trie[p][bit[i+1]]==-1){
            trie[p][bit[i+1]]=++tot;
        }
        p=trie[p][bit[i+1]];
    }
    tag[p]=true;
}

void build_ac(){
    head=tail=0;
    que[tail++]=root;
    while(head!=tail){
        int tmp=que[head++];
        int p=-1;
        for(int i=0;i<10;i++){
            if(trie[tmp][i]!=-1){
                if(tmp==root) fail[trie[tmp][i]]=root;
                else{
                    p=fail[tmp];
                    while(p!=-1){
                        if(trie[p][i]!=-1){
                            fail[trie[tmp][i]]=trie[p][i];
                            break;
                        }
                        p=fail[p];
                    }
                    if(p==-1) fail[trie[tmp][i]]=root;
                }
                if(tag[fail[trie[tmp][i]]]) tag[trie[tmp][i]]=tag[fail[trie[tmp][i]]];
                que[tail++]=trie[tmp][i];
            }
            else{
                if(tmp==root) trie[tmp][i]=root;
                else{
                    p=fail[tmp];
                    while(p!=-1){
                        if(trie[p][i]!=-1){
                            trie[tmp][i]=trie[p][i];
                            break;
                        }
                        p=fail[p];
                    }
                    if(p==-1) trie[tmp][i]=root;
                }
            }
        }
    }
}

LL dfs(int len,int j,bool flag){
    if(len==0) return 1ll;
    if(!flag&&dp[len][j]!=-1) return dp[len][j];
    LL ans=0;
    int up=flag?bit[len]:9;
    for(int i=0;i<=up;i++){
        if(tag[nxt[j][i]]||nxt[j][i]==-1) continue;
        ans+=dfs(len-1,nxt[j][i],i==up&&flag);
    }
    if(!flag) dp[len][j]=ans;
    return ans;
}

LL cal(LL m){
    LL tm=m+1ll;
    int len=0;
    while(m){
        bit[++len]=m%10;
        m/=10;
    }
    return tm-dfs(len,0,true);
//    return 0;
}

LL bin(LL num){
//    cout<<cal(13)<<endl;
//    system("pause");
    LL l=0,r=inf,ret=-1,tmp;
    while(l<=r){
        LL m=(l+r)>>1;
        if((tmp=cal(m))>=num){
            r=m-1;
            ret=m;
//            cout<<m<<endl;
        }
        else l=m+1;
    }
    return ret;
}

int cal_next(int p,int j){
    if(tag[p]) return -1;
    if(tag[trie[p][j]]) return -1;
    return trie[p][j];
}

void Init(){
    tot=0;
    memset(trie,-1,sizeof(trie));
    memset(tag,false,sizeof(tag));
    memset(fail,-1,sizeof(fail));
    f[1]=1ll; f[2]=1ll;
    for(int i=3;i<=55;i++){
        f[i]=f[i-1]+f[i-2];
        if(f[i]>10){
            insert(f[i]);
        }
    }
    build_ac();
    for(int i=0;i<=tot;i++){
        for(int j=0;j<10;j++)
        nxt[i][j]=cal_next(i,j);
    }
    memset(dp,-1,sizeof(dp));
    int c=0;
    for(int i=2;i<=55;i++){
        ans[c]=bin(f[i]);
//        system("pause");
        if(ans[c]==-1) break;
        c++;
//        printf("%I64d  %d\n",ans[c-1],c);
    }
}

int main(){
    Init();
    LL n;
//    cout<<"YES"<<endl;
    while(scanf("%I64d",&n)!=EOF&&n!=-1){
        LL ret=inf;
        for(int i=0;i<54;i++){
            LL tmp=n-ans[i];
        //    cout<<tmp<<endl;
            if(tmp<0) tmp=-tmp;
            if(ret>tmp) ret=tmp;
        }
        printf("%I64d\n",ret);
    }
    return 0;
}