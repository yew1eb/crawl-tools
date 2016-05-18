#define prog 1
 
 #if prog == 1
 
 #include <cstdio>
 #include <cmath>
 #include <ctime>
 #include <cstdlib>
 #include <algorithm>
 
 using namespace std;
 
 int main() {
     int T;
 
     freopen("in", "w", stdout);
     scanf("%d", &T);
     srand(time(NULL));
     while (T--) {
         int n = 100;
         int m = rand() % 20 + 11;
         int init = rand() % 900 + 101;
 
         printf("%d %d %d\n", n, m, init);
         while (m--) {
             int s = rand() % n + 1;
             int t = rand() % n + 1;
 
             if (s > t) swap(s, t);
             printf("%d %d %d %d\n", (rand() % 4) % 3 + 1, s, t, rand() % 1000 + 1);
         }
         puts("");
     }
     puts("0 0 0");
 
     return 0;
 }
 
 #endif
 
 #if prog == 2
 
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <cstdlib>
 
 using namespace std;
 
 const int maxn = 100001;
 bool Break[maxn];
 int Dur[maxn], INIT;
 
 void init(int size) {
     for (int i = 1; i <= size; i++) {
         Break[i] = false;
         Dur[i] = INIT;
     }
 }
 
 bool can(int l, int r) {
     while (l <= r) {
         if (Break[l]) return false;
         l++;
     }
 
     return true;
 }
 
 void mod(int l, int r, int d) {
     while (l <= r) {
         Dur[l] = max(Dur[l], d);
         if (Dur[l] <= 0) Break[l] = true;
         l++;
     }
 }
 
 void add(int l, int r, int d) {
     while (l <= r) {
         Dur[l] += d;
         if (Dur[l] <= 0) Break[l] = true;
         l++;
     }
 }
 
 int main() {
     int N, M;
 
     freopen("in", "r", stdin);
     freopen("cmp", "w", stdout);
     while (~scanf("%d%d%d", &N, &M, &INIT) && (N + M + INIT)) {
         init(N);
 
         int cnt = 0;
 
         for (int i = 1; i <= M; i++) {
             int s, t, d, op;
 
             scanf("%d%d%d%d", &op, &s, &t, &d);
             switch (op) {
             case 1 :
                 if (can(s, t)) {
                     printf("Pass %d\n", i);
                     cnt++;
                     add(s, t, -d);
                 }
                 break;
             case 2 :
                 add(s, t, d);
                 break;
             case 3 :
                 mod(s, t, d);
                 break;
             }
         }
         printf("%d\n", cnt);
     }
 
     return 0;
 }
 
 
 #endif