#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100001;
//sè¡¨ç¤ºåæ°ç»,treeè¡¨ç¤ºç¬¬iå±åç´ åºå,sumè¡¨ç¤ºç¬¬iå±L~jåå°å·¦å­æ çåç´ ä¸ªæ° 
int s[MAX],tree[20][MAX],sum[20][MAX];
int n,m;

void BuildTree(int deep,int left,int right){
    if(left == right)return;
    int mid=(left+right)>>1,ln=left,rn=mid+1;//lnè¡¨ç¤ºå­å·¦å­æ å¼å§çä¸æ ,rnè¡¨ç¤ºå­å³å­æ å¼å§çä¸æ  
    int lnum=mid-left+1;//numè¡¨ç¤ºå·¦å­æ åç´ çä¸ªæ°
    for(int i=left;i<=mid;++i){
        if(s[i]<s[mid])--lnum;//lnumå©ä½å¤å°å°±ä»£è¡¨æå¤å°å·¦å­æ åç´ ås[mid]ç¸ç­ 
    }
    for(int i=left;i<=right;++i){
        sum[deep][i]=sum[deep][i-1];//è¡¨ç¤º1~içååå°å·¦å­æ çä¸ªæ° 
        if(tree[deep][i]<s[mid]){
            ++sum[deep][i];
            tree[deep+1][ln++]=tree[deep][i];
        } 
        else if(tree[deep][i]>s[mid]){
            tree[deep+1][rn++]=tree[deep][i];
        }
        else{
            if(lnum){
                --lnum;
                ++sum[deep][i];
                tree[deep+1][ln++]=tree[deep][i];
            }
            else tree[deep+1][rn++]=tree[deep][i];
        }
    }     
    BuildTree(deep+1,left,mid);//éå½ååé¡ºåºä¸è½å,å ä¸ºsumå¿é¡»ä»å·¦å°å³è®°å½æè¡ 
    BuildTree(deep+1,mid+1,right);
}

int Query(int deep,int left,int right,int L,int R,int k){
    if(left == right)return tree[deep][left];
    int a,b;//aä»£è¡¨[left,L)åè¢«ååå°å·¦å­æ çä¸ªæ°,bä»£è¡¨[L,R]....
    int mid=(left+right)>>1;
    a=sum[deep][L-1]-sum[deep][left-1];
    b=sum[deep][R]-sum[deep][L-1];
    if(b>=k){
        return Query(deep+1,left,mid,left+a,left+a+b-1,k);
    }
    else return Query(deep+1,mid+1,right,mid+L-left+1-a,mid+R-left+1-a-b,k-b);
}

int main(){
    int L,R,k,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){scanf("%d",&s[i]);tree[0][i]=s[i];}//åå§åç¬¬0å±åç´ 
        sort(s+1,s+n+1);//å¯¹åæ°ç»æåº
        BuildTree(0,1,n);//å¼å§å»ºæ 
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&L,&R,&k);
            cout<<Query(0,1,n,L,R,k)<<endl;//ä»0å±å¼å§å¨1~nåºé´åæ¥è¯¢åºé´L~Rçç¬¬Kå¤§çæ°å¹¶è¾åº 
        } 
    }
    return 0;
}