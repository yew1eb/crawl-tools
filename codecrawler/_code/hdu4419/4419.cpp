#include<cstdio>
#include<algorithm>
#define N 20010
using namespace std;
typedef long long ll;

struct Tree{
    int l,r,cover[8];   //len表示区间【l,r】被占用的总长度
    ll len[8];
}tree[5*N];

struct Line{
    ll x,y1,y2;
    int flag,c;
}l[N];
ll y[N];

bool cmp(struct Line a,struct Line b){    //这里表示当2条线段x坐标重合时优先处理是入边的矩形的线段
    if(a.x==b.x)return a.flag>b.flag;
    return a.x<b.x;
}
void build(int s,int t,int id){
    int i;
    tree[id].l=s,tree[id].r=t;
    for(i=1;i<=7;i++)
        tree[id].cover[i]=tree[id].len[i]=0;
    if(s!=t-1){
        int mid=(s+t)>>1;
        build(s,mid,id<<1);
        build(mid,t,id<<1|1);
    }
}
void update(int id,int c){
    if(tree[id].cover[c]>0)
        tree[id].len[c]=y[tree[id].r-1]-y[tree[id].l-1];   //注意这里都要减一
    else if(tree[id].l==tree[id].r-1)
        tree[id].len[c]=0;
    else
        tree[id].len[c]=tree[id<<1].len[c]+tree[id<<1|1].len[c];
}
void query(int s,int t,int flag,int c,int id){
    if(tree[id].l==s && tree[id].r==t){
        tree[id].cover[c]+=flag;
        update(id,c);
        return;
    }
    int mid=(tree[id].l+tree[id].r)>>1;
    if(t<=mid)query(s,t,flag,c,id<<1);
    else if(s>=mid)query(s,t,flag,c,id<<1|1);
    else{
        query(s,mid,flag,c,id<<1);
        query(mid,t,flag,c,id<<1|1);
    }
    update(id,c);
}
int main(){
    int i,n,k;
    ll x1,x2,y1,y2;
    char str[10];
    int tt,T;
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%d",&n);
        int cnt=0;
        for(i=1;i<=n;i++){
            scanf("%s %I64d %I64d %I64d %I64d",str,&x1,&y1,&x2,&y2);
            if(str[0]=='R') l[cnt].c=l[cnt+1].c=1;
            else if(str[0]=='G') l[cnt].c=l[cnt+1].c=2;
            else if(str[0]=='B') l[cnt].c=l[cnt+1].c=4;
            l[cnt].x=x1,l[cnt].y1=y1,l[cnt].y2=y2,l[cnt].flag=1,y[cnt++]=y1;
            l[cnt].x=x2,l[cnt].y1=y1,l[cnt].y2=y2,l[cnt].flag=-1,y[cnt++]=y2;
        }
        sort(y,y+cnt);
        sort(l,l+cnt,cmp);
        int t=unique(y,y+cnt)-y;
        build(1,t,1);

        ll ans[8]={0},last[8]={0};
        for(i=0;i<cnt;i++){
            int lll=lower_bound(y,y+t,l[i].y1)-y+1;
            int rr=lower_bound(y,y+t,l[i].y2)-y+1;
            for(k=1;k<8;k++){
                if((l[i].c & k)) query(lll,rr,l[i].flag,k,1);
                if(i)ans[k]+=(ll)last[k]*(l[i].x-l[i-1].x);
                last[k]=tree[1].len[k];
            }
        }
        /*for(i=0;i<cnt;i++){  //两种写法都可以
            int lll=lower_bound(y,y+t,l[i].y1)-y+1;
            int rr=lower_bound(y,y+t,l[i].y2)-y+1;
            for(k=1;k<8;k++){
                if((l[i].c & k)) query(lll,rr,l[i].flag,k,1);
                if(i+1<cnt)ans[k]+=(ll)tree[1].len[k]*(l[i+1].x-l[i].x);
            }
        }*/
        printf("Case %d:\n",tt);
        printf("%I64d\n",ans[7]-ans[6]);
        printf("%I64d\n",ans[7]-ans[5]);
        printf("%I64d\n",ans[7]-ans[3]);
        printf("%I64d\n",ans[5]+ans[6]-ans[4]-ans[7]);
        printf("%I64d\n",ans[3]+ans[6]-ans[2]-ans[7]);
        printf("%I64d\n",ans[5]+ans[3]-ans[1]-ans[7]);
        printf("%I64d\n",ans[1]+ans[2]+ans[4]-ans[3]-ans[5]-ans[6]+ans[7]);
    }
    return 0;
}
