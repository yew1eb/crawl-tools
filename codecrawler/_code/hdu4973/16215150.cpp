#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
inline void rd(long long &n){   
    n = 0;
    char c = getchar();    
    while(c < '0' || c > '9') c = getchar();    
    while(c >= '0' && c <= '9') n *= 10, n += (c - '0'),c = getchar();    
}    
inline void pt(long long n){       
    int len = 0,data[20];    
    while(n)    
        data[len++] = n%10, n /= 10;     
    if(!len) data[len++] = 0;    
    while(len--) putchar(data[len]+48);    
}  
#define N 51000
typedef long long ll;
inline int Mid(int x, int y){return (x+y)>>1;}
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Lson(x) tree[x].l
#define Rson(x) tree[x].r
#define Siz(x) tree[x].siz
#define Val(x) tree[x].val
#define Lazy(x) tree[x].lazy
#define Max(x) tree[x].maxsize
struct node{
    int l, r, val;
    ll siz, lazy, maxsize;//sizæ¯åºé´åçç¹æ° maxsizeæ¯åºé´åæå¤§ç¹æ° ,valæ¯ç¹çå¼
}tree[N<<2];
ll mul[60];
void push_down(int id){
    if(Lazy(id)) {
        Siz(L(id)) = Siz(L(id)) << Lazy(id);
        Siz(R(id)) = Siz(R(id)) << Lazy(id);
        Max(L(id)) *= mul[Lazy(id)];
        Max(R(id)) *= mul[Lazy(id)];
        Lazy(L(id)) += Lazy(id);
        Lazy(R(id)) += Lazy(id);
        Lazy(id) = 0;
    }
}
void push_up(int id){
    Max(id) = max(Max(L(id)), Max(R(id)));
    Siz(id) = Siz(L(id)) + Siz(R(id));
}
void build(int l, int r, int id){
    Lson(id) = l; Rson(id) = r;    Lazy(id) = 0;
    if(l == r){
        Val(id) = l; Max(id) = Siz(id) = 1;
        return ;
    }
    int mid = Mid(l, r);
    build(l, mid, L(id)); build(mid+1, r, R(id));
    push_up(id);
}
void updata_siz(int pos, ll he, int id){
    push_down(id);
    if(Lson(id) == Rson(id))
    {
        Siz(id) += he;
        Max(id) += he;
        return ;
    }
    int mid = Mid(Lson(id), Rson(id));
    if(mid < pos) 
        updata_siz(pos, he, R(id));
    else
        updata_siz(pos, he, L(id));
    push_up(id);
}
void updata_qujian(int l, int r, int id){
    push_down(id);
    if(l == Lson(id) && Rson(id) == r){
        Lazy(id) ++;
        Max(id) <<= 1LL;
        Siz(id) <<= 1LL;
        return ;
    }
    int mid = Mid(Lson(id), Rson(id));
    if(mid < l)
        updata_qujian(l, r,  R(id));
    else if(r <= mid)
        updata_qujian(l, r,  L(id));
    else {
        updata_qujian(l, mid,  L(id));
        updata_qujian(mid+1, r,  R(id));
    }
    push_up(id);
}
ll query_siz(int l, int r, int id){
    push_down(id);
    if(l == Lson(id) && Rson(id) == r)
        return Siz(id);
  
    int mid = Mid(Lson(id), Rson(id));
    if(mid < l)
        return query_siz(l, r, R(id));
    else if(r <= mid)
        return query_siz(l, r, L(id));
    else 
        return query_siz(l, mid, L(id)) + query_siz(mid+1, r, R(id));
}
ll query_max(int l, int r, int id){
    push_down(id);
    if(l == Lson(id) && Rson(id) == r)
        return Max(id);

    int mid = Mid(Lson(id), Rson(id));
    if(mid < l)
        return query_max(l, r, R(id));
    else if(r <= mid)
        return query_max(l, r, L(id));
    else 
        return max(query_max(l, mid, L(id)), query_max(mid+1, r, R(id)));
}
int n, m;
int find(ll x, int id){
    push_down(id);
    if(Lson(id) == Rson(id))return Val(id);
    if( x <= Siz(L(id)))
        return find(x, L(id));
    return find(x-Siz(L(id)), R(id));
}
char s[2]; ll l, r;
int main() {
    mul[0] = 1; for(int i = 1; i < 60; i++)mul[i] = mul[i-1] * 2LL;
    int T, Cas = 1;   scanf("%d", &T);
    while (T--) {
        scanf("%d %d",&n,&m);
        build(1, n, 1);
        printf("Case #%d:\n", Cas++);
        while(m--){
            scanf("%s", s);
            rd(l); rd(r);
            int z = find(l, 1), y = find(r, 1);
            if(z==y) 
            {
                if(s[0] == 'D')
                    updata_siz(z, r-l+1, 1);
                else 
                {pt(r-l+1);putchar('\n');}  
                continue;
            }
            ll Lsize = query_siz(1, z, 1) - l+1, Rsize = r - query_siz(1, y-1, 1);
            if(s[0] == 'Q') 
            {
                ll ans = max(Lsize, Rsize);
                if(z + 1 <= y -1)
                    ans = max(ans, query_max(z+1, y-1, 1));
                pt(ans); putchar('\n');
            }
            else 
            {
                updata_siz(z, Lsize, 1);
                updata_siz(y, Rsize, 1);
                if(z + 1 <= y -1)
                    updata_qujian(z+1, y-1, 1);
            }
        }
    } 
    return 0;
}
/*
99
10 99
D 1 4
Q 1 14
D 2 7
Q 1 20
D 3 8
Q 1 4
Q 1 12
Q 1 11
Q 10 17
D 1 3
D 1 3
Q 1 18
Q 1 33
D 1 33
D 1 33
D 1 99
D 1 99
Q 1 105
Q 1 200
Q 150 210
Q 75 113
D 1 10
Q 2 8
Q 2 50
D 90 200
Q 1 300
Q 2 50 
Q 90 160
Q 45 65
Q 78 92
Q 100 200

ans:
2
4
4
8
7
5
10
10
105
160
50
39
7
49
71
21
15
101


*/