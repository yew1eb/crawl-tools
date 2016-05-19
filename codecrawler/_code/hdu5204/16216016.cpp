/*hdu 5204 Rikka with sequence
  é¢æï¼
  ä¼æå¨ç¥ï¼èèåå­è±ä¸æé¿æ°å­¦ï¼æä»¥åå¤ªç»äºå¥¹ä¸äºæ°å­¦é®é¢åç»ä¹ ï¼å¶ä¸­æä¸éæ¯è¿æ ·çï¼
  å¦æä¸ä¸ªæ éè¾¹æ èªç¯çæ åå¾çæ¯ä¸ªèéåé½å­å¨ä¸æ¡åè·¯ç»è¿è¿ä¸ªèéåéææè¾¹ä¸æ¬¡ä¸ä»ä¸æ¬¡ï¼é£ä¹å°±ç§°è¿ä¸ªæ åå¾æ¯ä¼ç¾çãè¯·é®ænä¸ªç¹ä¸è¾¹æ°ä¸å°äºmçä¼ç¾çå¾æå¤å°ä¸ªï¼ï¼å¨è¿é¢ä¸­ï¼æä»¬è®¤ä¸ºè¿nä¸ªç¹æ¯æ¬è´¨ä¸åçï¼
  å½ç¶ï¼è¿ä¸ªé®é¢å¯¹äºèèåå­è±æ¥è¯´å®å¨æ¯å¤ªé¾äºï¼ä½ å¯ä»¥å¸®å¸®å¥¹åï¼
  éå¶ï¼
  1 <= n <= 1e5; 1 <= L <= R <= 1e18; 1 <= w <= 1e9ã
  æè·¯ï¼
  å¶å®å°±60å·¦å³ä¸ªä¸åçæ°ã
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
void In(int &x){
    char c; x=0; c=getchar();
    int sign=1;
    while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
    if(c=='-') sign=-1,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    x*=sign;
}
void In(LL &x){
    char c; x=0; c=getchar();
    int sign=1;
    while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
    if(c=='-') sign=-1,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    x*=sign;
}
void Out(LL x){
    if(x<0){ x=-x; putchar('-');}
    if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

LL add[100005];
int cnt;
struct Dt{
    LL x;
    LL cnt;
}ele[100005];
bool cmp(Dt a,Dt b){
    return a.x<b.x;
}
LL getC(LL x){
    if(x<0) return 0;
    LL ret=x/2;
    if(x%2) ++ret;
    return ret;
}

void gao(LL l,LL r,LL k){
    for(int i=cnt-1;i>=max(0,cnt-65);--i){
        ele[cnt-1-i].x=add[i];
        ele[cnt-1-i].cnt=getC(r)-getC(l-1);
        r/=2;
        l=(l+1)/2;
    }
    sort(ele,ele+min(cnt,65),cmp);
    LL ans=0;
    for(int i=0;i<min(cnt,65);++i){
        if(ele[i].cnt<k){
            k-=ele[i].cnt;
        }
        else{
            ans=ele[i].x;
            break;
        }
    }
    Out(ans);
    puts("");
}

int main(){
    int n;
    int op;
    LL w,l,r,k;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        for(int i=0;i<n;++i){
            In(op);
            if(op==1){
                In(w);
                add[cnt++]=w;
            }
            else{
                In(l);
                In(r);
                In(k);
                gao(l,r,k);
            }
        }
    }
    return 0;
}