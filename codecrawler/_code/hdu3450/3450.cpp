#include <cstdio>
 #include <cstring>
 #include <algorithm>
 
 const int mod = 9901;
 const int maxn = 100000 + 100;
 
 int a[maxn];
 int val[maxn];
 int c[maxn];
 int N,D,num;
 
 int binary_find1(int x,int l,int r)
 {
     int ans = r;
     while(l <= r)
     {
         int mid = (l + r) / 2;
         if(val[mid] <= x) l = mid + 1,ans = mid;
         else r = mid - 1;
     }
 
     return ans;
 }
 
 int binary_find2(int x,int l,int r)
 {
     int ans = l;
     while(l <= r)
     {
         int mid = (l + r) / 2;
         if(val[mid] < x) l = mid + 1;
         else r = mid - 1,ans = mid;
     }
     return ans;
 }
 int get_sum(int x)
 {
     int sum = 0;
     while(x > 0)
     {
         sum += c[x];
         sum = sum % mod;
         x -= (x & (-x));
     }
 
     return sum;
 }
 
 void insert(int x,int v)
 {
     while(x < num)
     {
         c[x] += v;
         c[x] = c[x] % mod;
         x += (x & (-x));
     }
 }
 
 int main()
 {
     while(scanf("%d%d",&N,&D) == 2)
     {
         for(int i = 1;i <= N;i ++)
         {
             scanf("%d",&a[i]);
             val[i] = a[i];
         }
         std::sort(val + 1,val + N + 1);
         num = 2;
         for(int i = 2;i <= N; i ++)
         {
             if(val[i] != val[i -1])
                 val[num ++] = val[i];
         }
         memset(c,0,sizeof(c));
         for(int i = 1;i <= N;i ++)
         {
             int k = binary_find1(a[i],1,num - 1);
             int x = binary_find1(a[i]+ D,1,num -1);
             int y = binary_find2(a[i] - D,1,num-1); 
             int ans = 1;
             ans += get_sum(x);
             ans -= get_sum(y - 1);
             ans %= mod;
             insert(k,ans);
         }
 
         printf("%d\n",((get_sum(num-1) - N)%mod +mod)%mod);
     }
 
     return 0;
 }