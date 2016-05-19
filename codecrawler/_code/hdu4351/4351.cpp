#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l , mid , dex<<1
#define rson mid + 1 , r , dex<<1|1
#define havemid int mid = (l + r) >> 1

using namespace std;
const int Max = 100100;
int add[1025][1025];
int pass[10][1025];
//int root_l[Max];
//int root_r[Max];
//int root_a[Max];
//int root[Max<<2];

struct se
{
    int root_l , root_r , root_a , root , dex;
    se(int a = 0 , int b = 0 , int c = 0 , int d = 0 , int e = 0):root_l(a) , root_r(b) , root_a(c) , root(d) , dex(e) {}
    bool check()
    {
        if(!root_l && !root_r && !root_a && !root)
            return true;
        else
            return false;
    }
} seg[Max<<2];

void out_root(int x)
{
    for(int i = 0 ; i <= 9 ; i++)
        if(x & (1 << i))
            printf("%d " , i);
}

int Find_root(int x)
{
    int tem = 0;
    while(x)
    {
        tem += x%10;
        x /= 10;
    }
    if(tem < 10)
        return tem;
    else
        Find_root(tem);
}
inline int handle(int add , int root)
{
    int tem = 0;
    for(int i = 9 ; i >= 0 ; i--)
    {
        if(root & (1<<i))
            tem |= (1 << Find_root(i + add));
    }
    return tem;
}
inline int handle2(int one , int second)
{
    int tem = 0;
    for(int i = 9 ; i >= 0 ; i--)
        if(one & (1 << i))
            tem |= pass[i][second];
    return tem;
}
void init()
{
//    memset(pass , 0 , sizeof(pass));
//    for(int i = 0 ; i <= 9 ; i ++)
//        for(int j = 1 ; j <= 1024 ; j ++)
//            pass[i][j] = j | handle(i , j);

//    for(int i = 0 ; i <= 1024 ; i++)
//        for(int j = i ; j <= 1024 ; j++)
//            add[i][j] = add[j][i] = j | i | handle2(i , j);

    memset(pass , 0 , sizeof(pass));
    for(int i = 0 ; i <= 9 ; i ++)//pay attention! "i" is the root number  "j" is the value of the root number in binary system
        for(int j = 1 ; j <= 1024 ; j ++)
            pass[i][j] = handle(i , j);

//    for(int i = 1 ; i <= 9 ; i ++).
//    {
//        printf("pass[%d][%d]\n" , 1 , (1<<i|1));
//        out_root(pass[1][(1<<i|1)]);
//        printf("\n");
//    }

    for(int i = 0 ; i <= 1024 ; i++)
        for(int j = i ; j <= 1024 ; j++)
            add[i][j] = add[j][i] = handle2(i , j);
//
//    for(int i = 1 ; i <= 9 ; i ++)
//    {
//        printf("add[%d][%d]\n" , 2 , (1<<i|1));
//        out_root(add[2][(1<<i|1)]);
//        printf("\n");
//    }
}

//void Push_up(int dex)
//{
//    seg[dex].root_a = add[seg[dex<<1].root_a][seg[dex<<1|1].root_a];
//    seg[dex].root_l = seg[dex<<1].root_l | add[seg[dex<<1].root_a][seg[dex<<1|1].root_l];
//    seg[dex].root_r = seg[dex<<1|1].root_r | add[seg[dex<<1|1].root_a][seg[dex<<1].root_r];
//    seg[dex].root = seg[dex].root_l | seg[dex].root_r | add[seg[dex<<1].root_r][seg[dex<<1|1].root_l];
//
////    root_a[dex] = add[root_a[dex<<1]][root_a[dex<<1|1]];
////    root_l[dex] = root_l[dex<<1] | add[root_a[dex<<1]][root_l[dex<<1|1]];
////    root_r[dex] = root_r[dex<<1|1] | add[root_a[dex<<1|1]][root_r[dex<<1]];
////    root[dex] = root_l[dex] | root_r[dex] | add[root_r[dex<<1]][root_l[dex<<1|1]];
//}
se Push_up(se lsn , se rsn)
{
    se father;
    if(lsn.check() && !rsn.check()) return father = rsn;
    else if(!lsn.check() && rsn.check()) return father = lsn;
    else if(lsn.check() && rsn.check())   return father;
    father.root_a = add[lsn.root_a][rsn.root_a];
    father.root_l = lsn.root_l | add[lsn.root_a][rsn.root_l];
    father.root_r = rsn.root_r | add[rsn.root_a][lsn.root_r];
    father.root   = father.root_l | father.root_r | add[lsn.root_r][rsn.root_l] | lsn.root | rsn.root;
    return father;
}

void build(int l , int r , int dex)
{
    if(l == r)
    {
        int tem;
        scanf("%d" , &tem);
        seg[dex].root_a = seg[dex].root_l = seg[dex].root_r = seg[dex].root |= (1 << Find_root(tem));
//        root_a[dex] = root_l[dex] = root_r[dex] = root[dex] |= (1 << Find_root(tem));
        return;
    }
    havemid;
    build(lson);
    build(rson);
    seg[dex] = Push_up(seg[dex<<1] , seg[dex<<1|1]);
}

inline void m_out(int x)
{
    int counter = 0;
    int ans[5];
    for(int i = 9 ; i >= 0 ; i--)
    {
        if(counter == 5)    break;
        if(x & (1<<i))
            ans[counter++] = i;
    }
    if(!counter)
        printf("-1 -1 -1 -1 -1");
    else
    {
        printf("%d" , ans[0]);
        for(int i = 1 ; i < counter ; i++)
            printf(" %d" , ans[i]);
        for(int i = counter ; i < 5 ; i++)
            printf(" -1");
    }
    printf("\n");
}

se query(int L , int R , int l , int r , int dex)
{
    if(L <= l && R >= r)
        return seg[dex];
    havemid;
    se tem_L , tem_R , tem_ans;
    if(L <= mid)    tem_L = query(L , R , lson);
    if(R >  mid)    tem_R = query(L , R , rson);
    tem_ans = Push_up(tem_L , tem_R);
    return tem_ans;
}

void out_build(int l , int r , int dex)
{
    if(l == r)
    {
        printf("root[%d]:\n" , dex);
        out_root(seg[dex].root);
        printf("\n");
        return;
    }
    havemid;
    out_build(lson);
    out_build(rson);
    printf("root[%d]:\n" , dex);
    out_root(seg[dex].root);
    printf("\n");
}
int main()
{
//    freopen("DG.txt","r",stdin);
    int t , cases = 1;
    scanf("%d" , &t);
    init();
    while(t--)
    {
        printf("Case #%d:\n" , cases++);
        memset(seg , 0 , sizeof(seg));
        int n;
        scanf("%d" , &n);
        build(1 , n , 1);
//        out_build(1 , n , 1);
        int m;
        scanf("%d" , &m);
        for(int i = 1 ; i <= m ; i++)
        {
            int a , b;
            scanf("%d %d" , &a , &b);
//            cout<<"Bingo"<<endl;
            se ans = query(a , b , 1 , n , 1);
            m_out(ans.root);
        }
        if(t != 0)
            printf("\n");
    }
}