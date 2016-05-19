#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define LL long long
#define Rep(a,b,c) for(int a = b ; a <= c ; a ++)
#define Mid int mid = (l + r) >> 1;
#define lson l,mid
#define rson mid+1,r
using namespace std;
int n;
LL read(){
    LL ans = 0,flag = 1;
    char ch = ' ';
    while((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if(ch == '-'){
        flag = -1;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0'){
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * flag;
}
struct node{
    node *ch[2];
    LL res;
    node(){}
    void init(){
        res = 0;
        ch[0] = ch[1] = NULL;
    }
    void update(){
        res = ch[0]->res + ch[1]->res;
    }
}T[N * 20];
struct elem{
    LL S;
    int L,A;
    void add(){S = read();L  = read();A = read();}
    bool operator < (const elem &a)const{return L < a.L;}
};
int qcnt;
LL A2[N],L2[N],size;
struct SegmentTree{
    node *null,*root[N];
    void init(){
        null = &T[qcnt ++];
        null->init();
        null->ch[0] = null->ch[1] = null;
    }
    void __build(node *&y,node *&x,int l,int r,elem t){
        if(x == NULL) x = null;
        y = &T[qcnt++];
        y->init();
        if(l == r){
            *y = *x;
            y->res += t.S;
            return;
        }
        Mid;
        if(t.A <= A2[mid]){
            __build(y->ch[0],x->ch[0],lson,t);
            y->ch[1] = x->ch[1];
            y->update();
        }
        else{
            __build(y->ch[1],x->ch[1],rson,t);
            y->ch[0] = x->ch[0];
            y->update();
        }
    }
    LL __find(node *x1,node *x2,int L,int R,int l,int r){
        if(x1 == NULL) x1 = null;
        if(x2 == NULL) x2 = null;
        if(L <= l && r <= R){
            return x2->res - x1->res;
        }
        Mid;
        LL ans = 0;
        if(L <= mid) ans += __find(x1->ch[0],x2->ch[0],L,R,lson);
        if(mid + 1 <= R) ans += __find(x1->ch[1],x2->ch[1],L,R,rson);
        return ans;
    }
    LL find(int L,int R,int AL,int AR){
        LL ans = 0;
        if(L <= R && AL <= AR) ans = __find(root[L - 1],root[R],AL,AR,1,size);
        return ans;
    }
    void build(int id,elem t){
        __build(root[id],root[id - 1],1,size,t);
    }
}sgt;
elem ss[N];
void init(){
    qcnt = 0;
    sgt.init();
}
void solve(){
    init();
    Rep(i,1,n){
        ss[i].add();
        A2[i] = ss[i].A;
        L2[i] = ss[i].L;
    }
    sort(A2 + 1,A2 + n + 1);
    size = unique(A2 + 1,A2 + n + 1) - A2 - 1;
    sort(L2 + 1,L2 + n + 1);
    sort(ss + 1,ss + n + 1);
    Rep(i,1,n) sgt.build(i,ss[i]);
    int m;
    scanf("%d",&m);
    LL ll,lr,al,ar,k = 0;
    while(m--){
        ll = read();lr = read();al = read();ar = read();
        ll += k;lr -= k;
        al += k;ar -= k;
        if(ll > lr) swap(ll,lr);
        if(al > ar) swap(al,ar);
        ll = lower_bound(L2 + 1,L2 + n + 1,ll) - L2;
        lr = upper_bound(L2 + 1,L2 + n + 1,lr) - L2 - 1;
        al = lower_bound(A2 + 1,A2 + size + 1,al) - A2;
        ar = upper_bound(A2 + 1,A2 + size + 1,ar) - A2 - 1;
        k = sgt.find(ll,lr,al,ar);
        printf("%I64d\n",k);
    }
    return;
}
int main()
{
    while(~scanf("%d",&n)) solve();
}