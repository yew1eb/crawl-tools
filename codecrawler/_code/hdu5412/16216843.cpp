#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010

int ty[3*N],qr[3*N],ql[3*N],qk[3*N],ans[3*N];
int num[N];
int newid[2*N];//å ä¸ºå¼å°äºï¼æä»¥ä¸ç´wr
int L[4*N],R[4*N];
int c[N];
int mark[N];
vector<int> dp[4*N];
//vector<int> v;
int nid;
int n;
int nowloca;

void lisanhua(){
    sort(newid,newid+nid);
    nid=unique(newid,newid+nid)-newid;
    /*sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());*/
}

int numhash(int x){
    return lower_bound(newid,newid+nid,x)-newid+1;
    //return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

int lowbit(int x){
    return ((~x)+1)&x;
}

void change(int x,int cou){
    while(x<=n){
        //printf("%d ",x);
        if(mark[x]!=nowloca){
            mark[x]=nowloca;
            c[x]=0;
        }
        c[x]+=cou;
        x=x+lowbit(x);
    }
}

int sum(int x){
    int ans=0;

    while(x>0){
        if(mark[x]==nowloca){
           ans+=c[x];
        }
        x=x-lowbit(x);
    }

    return ans;
}

int main(){
    int q;
    int qid;
    int nextloca;

    while(scanf("%d",&n)!=EOF){
        qid=0;
        nid=0;
        //v.clear();
        dp[0].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            newid[nid++]=num[i];
            //v.push_back(num[i]);
            ty[qid]=1;
            ql[qid]=i;
            qr[qid]=num[i];
            dp[0].push_back(qid++);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d%d%d",&ty[qid],&ql[qid],&qr[qid]);
            if(ty[qid]==2){
                scanf("%d",&qk[qid]);
            }
            else{
                dp[0].push_back(qid++);
                ty[qid]=-1;
                ql[qid]=ql[qid-1];
                qr[qid]=num[ql[qid]];
                num[ql[qid]]=qr[qid-1];
                newid[nid++]=qr[qid-1];
                //v.push_back(qr[qid-1]);
            }
            dp[0].push_back(qid++);
        }

        /*for(int i=0;i<qid;i++){
            printf("%d %d\n",i,ql[i]);
        }*/

        lisanhua();
        for(int i=0;i<qid;i++){
            if(ty[i]!=2){
                qr[i]=numhash(qr[i]);
            }
        }

        nowloca=0;nextloca=1;
        L[0]=1;R[0]=nid/*v.size()*/;
        memset(c,0,sizeof(c));
        memset(mark,0,sizeof(mark));
        while(nowloca<nextloca){
            if(L[nowloca]==R[nowloca]){
                for(int i=0;i<dp[nowloca].size();i++){
                    int u=dp[nowloca][i];

                    if(ty[u]==2){
                        ans[u]=newid[L[nowloca]-1];
                    }
                }
            }
            else{
                int l=nextloca++;
                int r=nextloca++;
                int middle=(L[nowloca]+R[nowloca])>>1;
                L[l]=L[nowloca];
                R[l]=middle;
                L[r]=middle+1;
                R[r]=R[nowloca];
                dp[l].clear();
                dp[r].clear();

                //memset(c,0,sizeof(c));//è¿æ ·ä¼è¶æ¶
                for(int i=0;i<dp[nowloca].size();i++){
                    int u=dp[nowloca][i];

                    if(ty[u]==2){
                        int cnt=sum(qr[u])-sum(ql[u]-1);
                        //printf("%d %d\n",cnt,u);
                        if(qk[u]<=cnt){
                            dp[l].push_back(u);
                        }
                        else{
                            qk[u]-=cnt;
                            dp[r].push_back(u);
                        }
                    }
                    else{
                        if(qr[u]>middle){
                            dp[r].push_back(u);
                        }
                        else{
                            //printf("%d %dha ",u,ql[u]);
                            change(ql[u],ty[u]);//è°éï¼å¨changeè¿ä¸ªå½æ°è¿éæ²¡æè¿åæ¥äº
                            dp[l].push_back(u);
                        }
                    }
                }
            }
            nowloca++;//printf("wo shi da hao ren\n");
        }

        for(int i=0;i<qid;i++){
            if(ty[i]==2){
                printf("%d\n",ans[i]);
            }
        }
    }

    return 0;
}
