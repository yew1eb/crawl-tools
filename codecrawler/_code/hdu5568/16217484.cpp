#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5;

int T, cas = 0;
int n, k;
int a[N];

 #define MAXN 9999
 #define MAXSIZE 10
 #define DLEN 4
 const long long MOD = 258280327;
  class BigInteger
 {
 private:
     int a[300];   // Width 
     int len;       // Length
 public:
     BigInteger(){ len = 1; memset(a, 0, sizeof(a)); }   //Init
     BigInteger(const int);       // Int -> BigInt
     BigInteger(const char*);     // String -> BigInt
     BigInteger(const BigInteger &);  // copy
     BigInteger &operator=(const BigInteger &);   // =
 
     friend istream& operator>>(istream&, BigInteger&);   // >>
     friend ostream& operator<<(ostream&, BigInteger&);   // <<
 
     BigInteger operator+(const BigInteger &) const;   // +
     BigInteger operator-(const BigInteger &) const;   // -
     BigInteger operator*(const BigInteger &) const;   // *
     BigInteger operator/(const int   &) const;        // /
 
     BigInteger operator^(const int  &) const;    //BigInt Pow
     long long    operator%(const long long  &) const;    //Mod Int
     bool   operator>(const BigInteger & T)const;   //Compare with BigInt
     bool   operator<(const BigInteger & T)const;
     bool   operator>(const int & t)const;      //Compare with Int
 
     void print();       //è¾åºå¤§æ°
 };
 BigInteger::BigInteger(const int b)     //Int - > BigInt
 {
     int c, d = b;
     len = 0;
     memset(a, 0, sizeof(a));
     while (d > MAXN)
     {
         c = d - (d / (MAXN + 1)) * (MAXN + 1);
         d = d / (MAXN + 1);
         a[len++] = c;
     }
     a[len++] = d;
 }
 BigInteger::BigInteger(const char*s)     //String -> BigInt
 {
     int t, k, index, l, i;
     memset(a, 0, sizeof(a));
     l = strlen(s);
     len = l / DLEN;
     if (l%DLEN)
         len++;
     index = 0;
     for (i = l - 1; i >= 0; i -= DLEN)
     {
         t = 0;
         k = i - DLEN + 1;
         if (k<0)
             k = 0;
         for (int j = k; j <= i; j++)
             t = t * 10 + s[j] - '0';
         a[index++] = t;
     }
 }
 BigInteger::BigInteger(const BigInteger & T) : len(T.len)  // copy
 {
     int i;
      memset(a, 0, sizeof(a));
     for (i = 0; i < len; i++)
         a[i] = T.a[i];
 }
 BigInteger & BigInteger::operator=(const BigInteger & n)   //=
 {
     int i;
     len = n.len;
     memset(a, 0, sizeof(a));
     for (i = 0; i < len; i++)
         a[i] = n.a[i];
     return *this;
 }
 istream& operator>>(istream & in, BigInteger & b)   //>>
 {
     char ch[MAXSIZE * 4];
     int i = -1;
     in >> ch;
     int l = strlen(ch);
     int count = 0, sum = 0;
     for (i = l - 1; i >= 0;)
     {
         sum = 0;
         int t = 1;
         for (int j = 0; j<4 && i >= 0; j++, i--, t *= 10)
         {
             sum += (ch[i] - '0')*t;
         }
         b.a[count] = sum;
         count++;
     }
     b.len = count++;
     return in;
 }
 ostream& operator<<(ostream& out, BigInteger& b)   // <<
 {
     int i;
     cout << b.a[b.len - 1];
     for (i = b.len - 2; i >= 0; i--)
     {
         cout.width(DLEN);
         cout.fill('0');
         cout << b.a[i];
     }
     return out;
 }

 BigInteger BigInteger::operator+(const BigInteger & T) const   //+
 {
     BigInteger t(*this);
     int i, big;      //ä½æ°
     big = T.len > len ? T.len : len;
     for (i = 0; i < big; i++)
     {
         t.a[i] += T.a[i];
         if (t.a[i] > MAXN)
         {
             t.a[i + 1]++;
             t.a[i] -= MAXN + 1;
         }
     }
     if (t.a[big] != 0)
         t.len = big + 1;
     else
         t.len = big;
     return t;
 }
 BigInteger BigInteger::operator-(const BigInteger & T) const   // -
 {
     int i, j, big;
     bool flag;
     BigInteger t1, t2;
     if (*this>T)
     {
         t1 = *this;
         t2 = T;
         flag = 0;
     }
     else
     {
         t1 = T;
         t2 = *this;
         flag = 1;
     }
     big = t1.len;
     for (i = 0; i < big; i++)
     {
         if (t1.a[i] < t2.a[i])
         {
             j = i + 1;
             while (t1.a[j] == 0)
                 j++;
             t1.a[j--]--;
             while (j > i)
                 t1.a[j--] += MAXN;
             t1.a[i] += MAXN + 1 - t2.a[i];
         }
         else
             t1.a[i] -= t2.a[i];
     }
     t1.len = big;
     while (t1.a[t1.len - 1] == 0 && t1.len > 1)
     {
         t1.len--;
         big--;
     }
     if (flag)
         t1.a[big - 1] = 0 - t1.a[big - 1];
     return t1;
 }
 
 BigInteger BigInteger::operator*(const BigInteger & T) const   //Mutiply with BigInteger
 {
     BigInteger ret;
     int i, j, up;
     int temp, temp1;
     for (i = 0; i < len; i++)
     {
         up = 0;
         for (j = 0; j < T.len; j++)
         {
             temp = a[i] * T.a[j] + ret.a[i + j] + up;
             if (temp > MAXN)
             {
                 temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                 up = temp / (MAXN + 1);
                 ret.a[i + j] = temp1;
             }
             else
             {
                 up = 0;
                 ret.a[i + j] = temp;
             }
         }
         if (up != 0)
             ret.a[i + j] = up;
     }
     ret.len = i + j;
     while (ret.a[ret.len - 1] == 0 && ret.len > 1)
         ret.len--;
     return ret;
 }
 BigInteger BigInteger::operator/(const int & b) const   //Divide Int
 {
     BigInteger ret;
     int i, down = 0;
     for (i = len - 1; i >= 0; i--)
     {
         ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
         down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
     }
     ret.len = len;
     while (ret.a[ret.len - 1] == 0 && ret.len > 1)
         ret.len--;
     return ret;
 }
 long long BigInteger::operator %(const long long & b) const    //Mod Int
 {
     int i;
     long long d = 0;
     for (i = len - 1; i >= 0; i--)
     {
         d = ((d * (MAXN + 1)) % b + (long long)(a[i])) % b;
     }
     return d;
 }
 BigInteger BigInteger::operator^(const int & n) const    //Pow of BigInteger
 {
     BigInteger t, ret(1);
     int i;
     if (n<0)
         exit(-1);
     if (n == 0)
         return 1;
     if (n == 1)
         return *this;
     int m = n;
     while (m>1)
     {
         t = *this;
         for (i = 1; i << 1 <= m; i <<= 1)
         {
             t = t*t;
         }
         m -= i;
         ret = ret*t;
         if (m == 1)
             ret = ret*(*this);
     }
     return ret;
 }
 bool BigInteger::operator>(const BigInteger & T) const   //Compare with BigInteger
 {
     int ln;
     if (len > T.len)
         return true;
     else if (len == T.len)
     {
         ln = len - 1;
         while (a[ln] == T.a[ln] && ln >= 0)
             ln--;
         if (ln >= 0 && a[ln] > T.a[ln])
             return true;
         else
             return false;
     }
     else
         return false;
 }
 bool BigInteger::operator<(const BigInteger & T) const   //Compare with BigInteger
 {
     int ln;
     if (len > T.len)
         return true;
     else if (len == T.len)
     {
         ln = len - 1;
         while (a[ln] == T.a[ln] && ln >= 0)
             ln--;
         if (ln >= 0 && a[ln] < T.a[ln])
             return true;
         else
             return false;
     }
     else
         return false;
 }
 bool BigInteger::operator >(const int & t) const    //Compare with Int
 {
     BigInteger b(t);
     return *this>b;
 }
 
 void BigInteger::print()    //Print BigInteger
 {
     int i;
     cout << a[len - 1];
     for (i = len - 2; i >= 0; i--)
     {
         cout.width(DLEN);
         cout.fill('0');
         cout << a[i];
     }
     cout << endl;
 }
BigInteger dp[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//    freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, k) != EOF) {
        mem(dp, 0);
        for(int i = 1; i <= n; i ++) si(a[i]), dp[i][1] = 1;
        for(int i = 1; i <= n; i ++) {
            for(int j = 2; j <= k; j ++) {
                dp[i][j] = 0;
                for(int k = 1; k < i; k ++) {
                    if(a[k] < a[i]) {
                        dp[i][j] = dp[i][j] + dp[k][j-1];
                    }
                }
            }
        }
        BigInteger ans = 0;
        for(int i = 1; i <= n; i ++) ans = ans + dp[i][k];
        cout << ans << endl;
    }
    
    return 0;
}