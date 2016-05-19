 #include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iomanip>
 #include <set>
 #include <map>
 #include <vector>
 #include <queue>
 #define N 100005
 #define llt long long int
 using namespace std;
 
 int num[N << 2];//记录区间的个数 
 llt segtree[N << 2][5];// 
 struct node
 {
     int x;
     char s[4];
 }a[N];
 int b[N];
 map<int, int> mp;//使用map离散化 
 void build(int l, int r, int p)
 {
     memset(segtree[p], 0, sizeof(segtree[p]));
     num[p] = 0;
     if (l < r)
     {
         int mid = (l + r) >> 1, pp = p << 1;
         build(l, mid, pp);
         build(mid + 1, r, pp + 1);
     }
 }
 void update(int l, int r, int p, int pos, int v)
 {
     if (pos == l && pos == r)
     {
         segtree[p][0] += 1ll * v;
         num[p] = v > 0 ? 1 : 0;
         return;
     }
     int mid = (l + r) >> 1, pp = p << 1;
     if (mid >= pos)
         update(l, mid, pp, pos, v);
     else
         update(mid + 1, r, pp + 1, pos, v); 
     for (int i = 0; i < 5; i++)
         segtree[p][i] = segtree[pp][i] + segtree[pp + 1][((i - num[pp]) % 5 + 5) % 5];
     num[p] = num[pp] + num[pp + 1];
 }
 int main()
 {
     int n, i, k;
     while (~scanf("%d", &n))
     {
         k = 1;
         mp.clear();
         for (i = 1; i <= n; i++)
         {
             scanf("%s", a[i].s);
             if (a[i].s[0] == 'a')
             {
                 scanf("%d", &a[i].x);
                 b[k++] = a[i].x;
             }
             else
                 if (a[i].s[0] == 'd')
                 {
                     scanf("%d", &a[i].x);
                     a[i].x = -a[i].x;
                 }    
         }
         build(1, k - 1, 1);
         sort(b + 1, b + k); 
         for (i = 1; i < k; i++)
             mp[b[i]] = i;//重新编号 
         for (i = 1; i <= n; i++)
         {
             if (a[i].s[0] == 's')
                 printf("%I64d\n", segtree[1][2]);
             else
                 update(1, k - 1, 1, mp[abs(a[i].x)], a[i].x);            
         }
     }
     return 0;
 }
