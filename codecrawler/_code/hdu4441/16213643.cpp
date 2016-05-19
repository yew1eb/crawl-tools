#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<30
#define M 200005
#define N 200005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct Splay_tree{
    LL sum[N];
    int size[N],pre[N],val[N],tot;
    int ch[N][2],tot1,root,s[N],tot2,cnt[N][2];    //cnt[0]è¡¨ç¤ºçæ¯æ­£æ°ä¸ªæ°ï¼cnt[1]è¡¨ç¤ºçæ¯è´æ°ä¸ªæ°
    //debugé¨åcopy from hh
    void Treaval(int x) {
        if(x) {
            Treaval(ch[x][0]);
            printf("ç»ç¹%2d:å·¦å¿å­ %2d å³å¿å­ %2d ç¶ç»ç¹ %2d size = %2d ,val = %2c \n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x]);
            Treaval(ch[x][1]);
        }
    }
    void debug() {printf("%d\n",root);Treaval(root);}
    //ä»¥ä¸Debug
    inline void NewNode(int &r,int k,int father){
        r=++tot1;
        ch[r][0]=ch[r][1]=0;
        cnt[r][0]=k>0;
        cnt[r][1]=k<0;
        sum[r]=k;
        pre[r]=father;
        size[r]=1;
        val[r]=k;
    }
    inline void Push_Up(int x){
        if(x==0) return ;
        int l=ch[x][0],r=ch[x][1];
        size[x]=size[l]+size[r]+1;
        cnt[x][0]=cnt[l][0]+cnt[r][0]+(val[x]>0);
        cnt[x][1]=cnt[l][1]+cnt[r][1]+(val[x]<0);
        sum[x]=(LL)sum[l]+sum[r]+val[x];
    }
    inline void Init(){
        tot1=tot2=root=tot=0;
        ch[root][0]=ch[root][1]=pre[root]=size[root]=sum[0]=cnt[0][0]=cnt[0][1]=0;
        val[root]=0;
        NewNode(root,0,0);
        NewNode(ch[root][1],0,root);
        Push_Up(ch[root][1]);
        Push_Up(root);
    }
    inline void Rotate(int x,int kind){
        int y=pre[x];
        ch[y][!kind]=ch[x][kind];
        pre[ch[x][kind]]=y;
        if(pre[y])
            ch[pre[y]][ch[pre[y]][1]==y]=x;
        pre[x]=pre[y];
        ch[x][kind]=y;
        pre[y]=x;
        Push_Up(y);
    }
    inline void Splay(int r,int goal){
        while(pre[r]!=goal){
            if(pre[pre[r]]==goal)
                Rotate(r,ch[pre[r]][0]==r);
            else{
                int y=pre[r];
                int kind=(ch[pre[y]][0]==y);
                if(ch[y][kind]==r){
                    Rotate(r,!kind);
                    Rotate(r,kind);
                }
                else{
                    Rotate(y,kind);
                    Rotate(r,kind);
                }
            }
        }
        Push_Up(r);
        if(goal==0) root=r;
    }
    inline void RotateTo(int k, int goal) {
        int x=root;
        while(k!=size[ch[x][0]]+1){
            if (k<=size[ch[x][0]]){
                x=ch[x][0];
            }else{
                k-=(size[ch[x][0]]+1);
                x=ch[x][1];
            }
        }
        Splay(x,goal);
    }
    inline int Get_Kth(int r,int k){
        int t=size[ch[r][0]]+1;
        if(t==k) return r;
        if(t>k) return Get_Kth(ch[r][0],k);
        else return Get_Kth(ch[r][1],k-t);
    }
    inline int Insert(int pos,int k){
        tot++;
        RotateTo(pos,0);
        RotateTo(pos+1,root);
        NewNode(Key_value,k,ch[root][1]);
        Push_Up(ch[root][1]);
        Push_Up(root);
        return Key_value;
    }
    inline void Delete(int r){
        tot--;
        Splay(r,0);
        int pos=size[ch[r][0]];
        RotateTo(pos,0);
        RotateTo(pos+2,root);
        s[tot2++]=Key_value;
        Key_value=0;
        Push_Up(ch[root][1]);
        Push_Up(root);
    }
    //æ¾ç¬¬n+1ä¸ªè´æ°çä½ç½®
    inline int find(int x,int n){
        int l=ch[x][0],r=ch[x][1];
        if(cnt[l][1]==n&&val[x]<0) {Splay(x,0);return size[ch[root][0]];}
        else if(cnt[l][1]>=n+1) return find(l,n);
        else return find(r,n-cnt[l][1]-(val[x]<0));
    }
    inline void InOrder(int r){
        if(r==0)
            return;
        InOrder(ch[r][0]);
        printf("%d ",val[r]);
        InOrder(ch[r][1]);
    }
    inline void Print(){
        RotateTo(1,0);
        RotateTo(tot+2,root);
        InOrder(Key_value);
        printf("\n");
    }
}splay;
struct Segment_tree{
    int left,right,mmin;
}L[N*4];
int position[N][2];
void Push_Up(int step){
    L[step].mmin=min(L[lson].mmin,L[rson].mmin);
}
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    if(l==r){
        L[step].mmin=l;
        return;
    }
    int m=(l+r)/2;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
    Push_Up(step);
}
//flagä¸º1è¡¨ç¤ºæ¯æå¥ï¼flagä¸º0è¡¨ç¤ºæ¯å é¤
void Update(int step,int pos,int flag){
    if(L[step].left==pos&&pos==L[step].right){
        if(flag) L[step].mmin=inf;
        else L[step].mmin=L[step].left;
        return ;
    }
    int m=(L[step].left+L[step].right)/2;
    if(pos<=m) Update(lson,pos,flag);
    else Update(rson,pos,flag);
    Push_Up(step);
}
void Insert(int pos){
    int num=L[1].mmin;
    position[num][0]=splay.Insert(pos+1,num);
    splay.Splay(position[num][0],0);
    int n=splay.cnt[splay.ch[splay.root][0]][0];  //è¡¨ç¤ºå¨+iä¹åæå¤å°ä¸ªæ­£æ°
    //å°-iæå¥å°ç¬¬n+1ä¸ªè´æ°å·¦è¾¹
    if(splay.cnt[splay.root][1]<=n){
        int m=splay.size[splay.root]-2+1;
        position[num][1]=splay.Insert(m,-num);
        Update(1,num,1);  //æå¥çº¿æ®µæ 
    }
    else{
        int m=splay.find(splay.root,n);   //è¡¨ç¤ºç¬¬n+1ä¸ªè´æ°æ¯ç¬¬mä¸ªæ°
        position[num][1]=splay.Insert(m,-num);
        Update(1,num,1);  //æå¥çº¿æ®µæ 
    }
}
void Remove(int k){
    splay.Delete(position[k][0]);
    splay.Delete(position[k][1]);
    Update(1,k,0);   //ä»çº¿æ®µæ ä¸­ç§»é¤
}
LL Query(int k){
    splay.Splay(position[k][0],0);
    splay.Splay(position[k][1],splay.root);
    return splay.sum[splay.ch[splay.ch[splay.root][1]][0]];
}
int main(){
    int cas=0,q;
    while(scanf("%d",&q)!=EOF){
        printf("Case #%d:\n",++cas);
        splay.Init();
        Bulid(1,1,q);
        while(q--){
            char str[10];int k;
            scanf("%s%d",str,&k);
            if(str[0]=='i') Insert(k);
            else if(str[0]=='r') Remove(k);
            else printf("%I64d\n",Query(k));
           // splay.Print();
        }
    }
    return 0;
}