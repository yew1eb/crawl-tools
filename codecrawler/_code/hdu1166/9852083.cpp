#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define N 50005

using namespace std;

int num[N];
struct Tree
{
    int l;
    int r;
    int sum;
}tree[N*4];

void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if(tree[root].l == tree[root].r)
    {
        tree[root].sum = num[l];
        return;
    }
    int mid = (l+r)>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

 void update(int root, int pos, int val)
 {
     if(tree[root].l == tree[root].r)
     {
         tree[root].sum = val;
         return ;
     }
     int mid = (tree[root].l + tree[root].r)>>1;
     if(pos <= mid)
         update(root<<1, pos, val);
     else
         update(root<<1|1, pos, val);
     tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
 }

 int query(int root, int L, int R)
 {
     if(L <=tree[root].l && R >= tree[root].r)
         return tree[root].sum;
     int mid = (tree[root].l + tree[root].r)>>1, ret = 0;
     if(L <= mid) ret += query(root<<1, L, R);
     if(R > mid)  ret += query(root<<1|1, L, R);
     return ret;
 }

 int main()
 {
     int ca, cas = 1, n, Q, a, b;
     char str[10];

     scanf("%d",&ca);
     while(ca--)
     {
         scanf("%d",&n);
         for(int i=1; i<=n; ++i)
             scanf("%d",&num[i]);
         build(1,1,N);
         printf("Case %d:\n", cas++);
         while(1)
         {
             scanf("%s",str);
             if(str[0] == 'E') break;
             scanf("%d%d",&a,&b);
             if(str[0] == 'Q')
             {
                 if(a > b) swap(a,b);
                 printf("%d\n", query(1,a,b));
             }
             else if(str[0] == 'A')
             {
                 num[a] = num[a] + b;
                 update(1, a, num[a]);
             }
             else if(str[0] == 'S')
             {
                 num[a] = num[a] - b;
                 update(1,a,num[a]);
             }
         }
     }
     return 0;
 }
