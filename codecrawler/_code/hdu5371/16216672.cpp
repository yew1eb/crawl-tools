#include<cstring>
#include<cstdio>
#include<string>
#include <iostream>
#include<algorithm>
using namespace std;
#define maxn 800007
int lc[maxn],rc[maxn],val[maxn];

int rad[maxn];
int tmp[maxn];
int s[maxn];
int inf = 1000000000;
void manacher(int n){//æ±åæä¸²
    int cnt = 0;
    memset(rad,0,sizeof(rad));
    for(int i=0;i<n;i++){
        s[cnt++] = inf;
        s[cnt++] = tmp[i];
    }
    s[cnt++] = inf;
    n = cnt;
    int i=0,j=1,k;
    while(i<n){
        while(i-j>=0 && i+j<n && s[i-j]==s[i+j])
            j++;
        rad[i]=j-1;
        k=1;
        while(k<=rad[i] && rad[i]-k!=rad[i-k]){
            rad[i+k]=min(rad[i-k],rad[i]-k);
            k++;
        }
        i+=k;
        j=max(j-k,0);
    }
}
int tcnt;
//å»ºæ ï¼å¥æ°ä½å°±æ¯åä¸²çä½ç½®ï¼ä¸è½ä½ä¸ºåå²ç¹
void build(int u,int l,int r){
    if(l == r){
        if(l & 1) val[u] = inf;
        else val[u] = l - rad[l];
        return ;
    }
    lc[u] = tcnt++;
    rc[u] = tcnt++;
    int mid = (l+r)/2;
    build(lc[u],l,mid);
    build(rc[u],mid+1,r);
    val[u] = min(val[lc[u]],val[rc[u]]);

}
//æ¥è¯¢å¨L,Råºé´æ»¡è¶³å°äºç­äºpçæå³è¾¹çä½ç½®
int query(int u,int l,int r,int L,int R, int p){
    if(l == r) return l;
    int mid = (l+r)/2;
    if(l == L && R == r){
        if(val[u] > p) return inf;
        if(val[rc[u]] <= p)
            return query(rc[u],mid+1,r,mid+1,R,p);
        else if(val[lc[u]] <= p) return query(lc[u],l,mid,l,mid,p);
        else return inf;
    }

    if(mid < L)
        return query(rc[u],mid+1,r,L,R,p);
    else if(mid >= R)
        return query(lc[u],l,mid,L,R,p);
    else {
        int ans = query(rc[u],mid+1,r,mid+1,r,p);
        if(ans != inf) return ans;
        return query(lc[u],l,mid,L,mid,p);
    }
    return inf;
}


void init(){
    tcnt = 2;
    memset(rc,0,sizeof(rc));
    memset(lc,0,sizeof(lc));
    memset(val,0x3f,sizeof(val));
}
int main()
{
    int t,tt=1,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n; i++)
            scanf("%d",&tmp[i]);
        manacher(n);
        n = n*2+1;
        init();
        build(1,0,n-1);

        int ans = 0;
        for(int i = 0;i < n; i+=2){ //æä¸¾åå²ä½ç½®
            int p = i + rad[i];
            int q = query(1,0,n-1,i,p,i);
            if(q == inf) continue;
            int res = min(rad[i],q-i);
            ans = max(ans,res/2);//manacherçé¿åº¦å¢å äºä¸åï¼ææè¦/2
        }
        printf("Case #%d: %d\n",tt++,ans*3);
    }
    return 0;
}



/*
22
10
2 3 4 4 3 2 2 3 4 4
20
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
12
1 1 2 2
2 2 1 1
1 1 2 2
*/
















