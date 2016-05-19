#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=50000+10;
int lsum[MAX<<2],rsum[MAX<<2];//åå«è®°å½åºé´åæå¤§è¿ç»­æåº,å·¦ç«¯æå¤§è¿ç»­æåº,å³ç«¯æå¤§è¿ç»­æåº
int s[MAX],size,n,m,a;//sè®°å½ç ´åçæåºç¼å· 
char ch[2];
bool mark[MAX];//markæ è®°æåºæ¯å¦ç ´å,0è¡¨ç¤ºæ²¡ç ´å,1è¡¨ç¤ºç ´å 

void Upfather(int n,int m){//æ´æ°åºé´å·¦å³ç«¯è¿ç»­æåºä¸ªæ° 
    lsum[n]=lsum[n<<1];
    rsum[n]=rsum[n<<1|1];
    if(lsum[n] == m-(m>>1))lsum[n]+=lsum[n<<1|1];
    if(rsum[n] == m>>1)rsum[n]+=rsum[n<<1];
}

void BuildTree(int left,int right,int n){
    lsum[n]=rsum[n]=right-left+1;
    if(left == right)return;
    int mid=left+right>>1;
    BuildTree(left,mid,n<<1);
    BuildTree(mid+1,right,n<<1|1);
}

void Update(int p,int date,int left,int right,int n){
    if(left == right){lsum[n]=(rsum[n]+=date);return;}
    int mid=left+right>>1;
    if(p<=mid)Update(p,date,left,mid,n<<1);
    else Update(p,date,mid+1,right,n<<1|1);
    Upfather(n,right-left+1);
}

int QueryL(int L,int R,int left,int right,int n){//æ¥è¯¢a~nçå·¦ç«¯è¿ç»­æåºä¸ªæ° 
    if(L<=left && right<=R)return lsum[n];
    int mid=left+right>>1,lans,rans;
    if(L<=mid)lans=QueryL(L,R,left,mid,n<<1);
    if(R>mid)rans=QueryL(L,R,mid+1,right,n<<1|1);
    if(R<=mid)return lans;
    if(L>mid)return rans;
    if(lans == mid-L+1)return lans+rans;
    return lans;
}
/*å¦ä¸ç§åæ³æè®¸æ´å¥½çè§£
int QueryL(int L,int R,int left,int right,int n){
    if(L<=left && right<=R)return lsum[n];
    int mid=left+right>>1,lans,rans;
    if(R<=mid)return QueryL(L,R,left,mid,n<<1);
    else if(L>mid)return QueryL(L,R,mid+1,right,n<<1|1);
    else{
        lans=QueryL(L,mid,left,mid,n<<1);
        rans=QueryL(mid+1,R,mid+1,right,n<<1|1);
        if(lans == mid-L+1)return lans+rans;
        return lans;
    }
} 
*/

int QueryR(int L,int R,int left,int right,int n){//æ¥è¯¢1~aå³ç«¯æåºè¿ç»­ä¸ªæ° 
    if(L<=left && right<=R)return rsum[n];
    int mid=left+right>>1,lans,rans;
    if(L<=mid)lans=QueryR(L,R,left,mid,n<<1);
    if(R>mid)rans=QueryR(L,R,mid+1,right,n<<1|1);
    if(R<=mid)return lans;
    if(L>mid)return rans;
    if(rans == R-mid)return lans+rans;
    return rans;
}
/*å¦ä¸ç§åæ³æè®¸æ´å¥½çè§£
int QueryR(int L,int R,int left,int right,int n){
    if(L<=left && right<=R)return rsum[n];
    int mid=left+right>>1,lans,rans;
    if(R<=mid)return QueryR(L,R,left,mid,n<<1);
    else if(L>mid)return QueryR(L,R,mid+1,right,n<<1|1);
    else{
        lans=QueryR(L,mid,left,mid,n<<1);
        rans=QueryR(mid+1,R,mid+1,right,n<<1|1);
        if(rans == R-mid)return lans+rans;
        return rans;
    }
}
*/

int main(){
    while(~scanf("%d%d",&n,&m)){
        BuildTree(1,n,1);
        size=0;
        memset(mark,false,sizeof(bool)*(n+2));
        mark[0]=true;
        for(int i=0;i<m;++i){
            scanf("%s",ch);
            if(ch[0] == 'D'){
                scanf("%d",&a);
                s[++size]=a;
                if(!mark[a])Update(a,-1,1,n,1),mark[a]=true;
            }else if(ch[0] == 'R'){
                while(!mark[s[size]])--size;//å·²ç»è¢«ä¿®å¤è¿äºå°±ä¿®å¤ä¸ä¸ä¸ª,æ¯å¦3 2 2,ç¬¬ä¸æ¬¡ä¿®å¤2,ç°å¨ä¿®å¤3èä¸æ¯2 
                if(size)Update(s[size],1,1,n,1),mark[s[size--]]=false;
            }else{
                scanf("%d",&a);
                int temp=QueryL(a,n,1,n,1)+QueryR(1,a,1,n,1);
                printf("%d\n",temp>0?temp-1:0);
            }
        }
    }
    return 0;
}