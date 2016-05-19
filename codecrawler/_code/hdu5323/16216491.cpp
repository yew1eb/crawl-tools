#include<cstdio>
#include<cstring>
#define LL __int64
LL n;
inline bool check(LL L,LL R,LL mid)
{
    if(L<0) return 0;
    if(mid!=(L+R)/2) return 0;
    if(L>mid) return 0;
    if(mid>=R) return 0;
    return 1;
}
void dfs(LL L,LL R)
{
    if(L==0)
    {
        if(n==-1||R<n) n=R;
        return ;
    }
    LL tmp=R-L+1;
    if(L<tmp) return;
    LL Lt=L-tmp;
    if(check(Lt,R,L-1)) dfs(Lt,R);
    Lt--;
    if(check(Lt,R,L-1)) dfs(Lt,R);
    LL Rt=R+tmp;
    if(check(L,Rt,R)) dfs(L,Rt);
    Rt--;
    if(check(L,Rt,R)) dfs(L,Rt);
}
int main()
{
    LL L,R;
    while(~scanf("%I64d %I64d",&L,&R))
    {
        n=-1;
        dfs(L,R);
        printf("%I64d\n",n);
    }
    return 0;
}
