#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int pre[N],ch[N][2],root,tot1;  //åå«è¡¨ç¤ºç¶ç»ç¹ï¼é®å¼ï¼å·¦å³å­©å­(0ä¸ºå·¦å­©å­ï¼1ä¸ºå³å­©å­),æ ¹ç»ç¹ï¼ç»ç¹æ°é
int size[N];    //åå«è¡¨ç¤ºå­æ è§æ¨¡ï¼åå­æ± ï¼åå­æ± å®¹é
int rev[N];
int n,q;
inline void NewNode(int &r,int father,int k){
    r=k;
    pre[r]=father;
    rev[r]=0;
    size[r]=1;
    ch[r][0]=ch[r][1]=0;  //å·¦å³å­©å­ä¸ºç©º
}
//å°å»¶è¿æ è®°æ´æ°å°å­©å­ç»ç¹
inline void Push_Down(int r){
    if(rev[r]){
        rev[ch[r][0]]^=1;
        rev[ch[r][1]]^=1;
        swap(ch[r][0],ch[r][1]);
        rev[r]=0;
    }
}
//éè¿å­©å­ç»ç¹æ´æ°ç¶ç»ç¹
inline void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
//æè½¬ï¼kindä¸º1ä¸ºå³æï¼kindä¸º0ä¸ºå·¦æ
inline void Rotate(int x,int kind){
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    //ç±»ä¼¼SBTï¼è¦æå¶ä¸­ä¸ä¸ªåæ¯åç»ç¶èç¹
    ch[y][!kind]=ch[x][kind]; 
    pre[ch[x][kind]]=y;
    //å¦æç¶èç¹ä¸æ¯æ ¹ç»ç¹ï¼åè¦åç¶èç¹çç¶èç¹è¿æ¥èµ·æ¥
    pre[x]=pre[y];
    if(pre[x])
        ch[pre[y]][ch[pre[y]][1]==y]=x;
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}inline void zig(int x){
    int y=pre[x], z=pre[y];
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    ch[x][0]=y; pre[y]=x;
    pre[x]=z;
    if(z) ch[z][ch[z][1]==y]=x;
    Push_Up(y);
}
inline void zag(int x){
    int y=pre[x], z=pre[y];
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    ch[x][1]=y; pre[y]=x;
    pre[x]=z;
    if(z) ch[z][ch[z][1]==y]=x;
    Push_Up(y);
}
inline void zigzig(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[z][1]=ch[y][0]; pre[ch[y][0]]=z;
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    pre[z]=y; ch[y][0]=z;
    pre[y]=x; ch[x][0]=y;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zagzag(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[z][0]=ch[y][1]; pre[ch[y][1]]=z;
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    pre[z]=y; ch[y][1]=z;
    pre[y]=x; ch[x][1]=y;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zigzag(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    ch[z][0]=ch[x][1]; pre[ch[x][1]]=z;
    pre[y]=pre[z]=x;
    ch[x][0]=y; ch[x][1]=z;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zagzig(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    ch[z][1]=ch[x][0]; pre[ch[x][0]]=z;
    pre[y]=pre[z]=x;
    ch[x][1]=y; ch[x][0]=z;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
void Splay(int x, int goal){
    int y, z;
    Push_Down(x);
    while(pre[x]!=goal){
        if(pre[pre[x]]==goal){
            y=pre[x]; Push_Down(y); Push_Down(x);
            if(ch[y][1]==x) zig(x);
            else zag(x);
        }
        else{
            y=pre[x]; z=pre[y];
            Push_Down(z); Push_Down(y); Push_Down(x);
            if(ch[z][1]==y){
                if(ch[y][1]==x) zigzig(x);
                else zagzig(x);
            }
            else{
                if(ch[y][0]==x) zagzag(x);
                else zigzag(x);
            }
        }
    }
    Push_Up(x);
    if(pre[x]==0) root=x;
}
//Splayè°æ´ï¼å°æ ¹ä¸ºrçå­æ è°æ´ä¸ºgoal
/*inline void Splay(int r,int goal){
    Push_Down(r);
    while(pre[r]!=goal){
        //ç¶èç¹å³æ¯ç®æ ä½ç½®ï¼goalä¸º0è¡¨ç¤ºï¼ç¶èç¹å°±æ¯æ ¹ç»ç¹
        if(pre[pre[r]]==goal)
            Rotate(r,ch[pre[r]][0]==r);
        else{
            int y=pre[r];
            int kind=(ch[pre[y]][0]==y);
            //ä¸¤ä¸ªæ¹åä¸åï¼ååå·¦æåå³æ
            if(ch[y][kind]==r){
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            //ä¸¤ä¸ªæ¹åç¸åï¼ç¸åæ¹åè¿ç»­ä¸¤æ¬¡
            else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    //æ´æ°æ ¹ç»ç¹
    if(goal==0) root=r;
}
*/
inline int Get_Max(int r){  
    Push_Down(r);
    while(ch[r][1]){
        r=ch[r][1];
        Push_Down(r); 
    }
    return r;  
}  
inline void Remove(){ // erase the root
    if(ch[root][0]==0){
        root=ch[root][1];
        pre[root]=0;
    }
    else{
        int m=Get_Max(ch[root][0]);
            Splay(m,root);
        ch[m][1]=ch[root][1];
        pre[ch[root][1]]=m;
        root=m;
        pre[root]=0;
        Push_Up(root);
    }
}
inline void BulidTree(int &x,int l,int r,int father){
    if(l>r)
        return;
    int mid=(l+r)>>1;
    NewNode(x,father,mid);
    BulidTree(ch[x][0],l,mid-1,x);
    BulidTree(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
 
struct Node{
    int idx,num;
}a[N];
inline bool cmp(Node n1,Node n2){
    return n1.num!=n2.num?n1.num<n2.num:n1.idx<n2.idx;
}
inline void Init(){
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        a[i].idx=i;
    }
    sort(a+1,a+1+n,cmp);
    ch[0][0]=ch[0][1]=pre[0]=size[0]=rev[0]=0;
    root=tot1=0;
    BulidTree(root,1,n,0); 
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        Init();
        for(int i=1;i<n;i++){        
            Splay(a[i].idx,0);
            rev[ch[root][0]]^=1;            
            printf("%d ",i+size[ch[root][0]]);            
            Remove();            
        }
        printf("%d\n",n);
    }
    return 0;
}