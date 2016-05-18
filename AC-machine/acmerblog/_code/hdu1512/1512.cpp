#define N 100010
struct node{
    int dis,v;
    int l,r;
}k[N];
int n,m,pre[N];
void init(){
    int i;
    for(i=0;i<=n;i++){
        pre[i] = i;
    }
    memset(k,'\0',sizeof(k));
}
int Merge(int a,int b){//  左偏树合并（重要）！
    if(a == 0)return b;
    if(b == 0)return a;
    if(k[b].v>k[a].v)swap(a,b);
    k[a].r = Merge(k[a].r,b);
    pre[k[a].r] = a;
    if(k[k[a].l].dis < k[k[a].r].dis)swap(k[a].r,k[a].l);
    if(k[a].r == 0)k[a].dis = 0;
    else k[a].dis = k[k[a].r].dis + 1;
    return a;
}
int Max(int a){//  合并左右子树后返回最大结点编号
    return Merge(k[a].l,k[a].r);
}
int find(int x){//  寻找前驱
    while(x!=pre[x]){
        x = pre[x];
    }
    return x;
}
int solve(int a,int b){
    int x = find(a),y = find(b);//寻找各自根结点(这里也就是最大值的结点)
    int p,xx,yy,tmp;
    pre[a] = x,pre[b] = y;
    if(x == y)return -1;//同一棵树

    k[x].v /= 2;//修改根结点后要重新合并，具体是先合并两个儿子，再插入自己
    tmp = Max(x);//合并两个儿子——————— ①
    k[x].r = k[x].l = k[x].dis = 0;//自己脱离出来
    xx = Merge(tmp,x);// 合并修改后的节点和上面两个儿子的新树①

    k[y].v /= 2;
    tmp = Max(y);
    k[y].r = k[y].l = k[y].dis = 0;
    yy = Merge(tmp,y);

    p = Merge(xx,yy);// 合并上面的两棵树

    pre[xx] = pre[yy] = pre[x] = pre[y] = pre[a] = pre[b] = p;//更改前驱
    return k[p].v;
}
int main(){
    int i,j;
    while(scanf("%d",&n) != -1){
        init();
        for(i=1;i<=n;i++){
            scanf("%d",&k[i].v);
        }
        scanf("%d",&m);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            int ans = solve(a,b);
            printf("%d\n",ans);
        }
    }
    return 0;
}