#include <cstdio>
 #include <cstring>

 typedef __int64 ll;
 const int maxn = 20;
 const ll maxsum = 500000000;
 ll tri[maxn << 1][maxn << 1];
 ll sum[maxn], rec[maxn];
 int cur, l[maxn], r[maxn];

 void build(){
     memset(tri, 0, sizeof(tri));
     tri[0][0] = 1;
     for (int i = 1; i < maxn << 1; i++){
         tri[i][0] = 1;
         for (int j = 1; j <= i; j++){
             tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
         }
     }
     sum[0] = rec[0] = 1;
     for (int i = 1; i < maxn; i++){
         rec[i] = tri[i << 1][i] / (i + 1);
         sum[i] = sum[i - 1] + rec[i];
 #ifndef ONLINE_JUDGE
         printf("%2d : %12I64d %12I64d\n", i, sum[i], rec[i]);
 #endif
     }
 }

 void con(int rt, int rest, int cnt){
     if (rest == 1 && cnt == 1){
         return ;
     }
     cnt--;
     for (int i = 0; i <= cnt; i++){
         int tmp = rec[i] * rec[cnt - i];

         if (rest > tmp) rest -= tmp;
         else{
             int lrest = (rest - 1) / rec[cnt - i] + 1;
             int rrest = (rest - 1) % rec[cnt - i] + 1;

             if (i){
                 l[rt] = ++cur;
                 con(cur, lrest, i);
             }
             if (cnt - i){
                 r[rt] = ++cur;
                 con(cur, rrest, cnt - i);
             }

             break;
         }
     }
 }

 void print(int rt){
     if (~l[rt]){
         putchar('(');
         print(l[rt]);
         putchar(')');
     }
     putchar('X');
     if (~r[rt]){
         putchar('(');
         print(r[rt]);
         putchar(')');
     }
 }

 void deal(int n){
     int cnt = 0;

     while (n >= sum[cnt]) cnt++;
 #ifndef ONLINE_JUDGE
     printf("%d\n", cnt);
 #endif
     for (int i = 0; i < cnt; i++)
         l[i] = r[i] = -1;
     cur = 0;
     n -= sum[cnt - 1] - 1;
     con(0, n, cnt);
     print(0);
     puts("");
 }

 int main(){
     int n;

     build();
     while (~scanf("%d", &n) && n)
         deal(n);

     return 0;
 }