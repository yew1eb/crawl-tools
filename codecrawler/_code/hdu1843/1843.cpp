// 这题主要求S
// 结论: S = (251^(n+1)-1) * (2^(3n+1)-1) / 250 
// 是两个等比数列和相乘 
// 
// 推理:
// 2008 = 2^3 * 251 
// 所以 2008^N 有 3N 个 2 和 N 个251 
// 所有仅由2组成的因子有
// 2^0 2^1 2^2 ... 2^(3N)
// 设集合 C = {2^0, 2^1, 2^2 ...,2^(3N)};
// SUM(C) =  2^(3n+1)-1

// 跟251组合产生的因子有
// 251^0 * C
// 251^1 * C
// ...
// 251^N * C

// 所有因子和为:
// S = (251^(n+1)-1))/250 * (2^(3n+1)-1)

// 计算S%K:
// S 很大, 不能保存在普通的数据类型中, 需要直接计算S%K
// 因为S有个分母250, 设 S = X/250
// 则S%K = (X/250)%K = (X%(250*K))/250
// 变成先求余数再除法的形式

#include <stdio.h>

// 求 (x^exp)%p 的值  O(LOG(exp))
int ExpMod(int x, int exp, int p) {
     if( exp==0 ) {
          return 1;
     }
     long long ret = ExpMod(x, exp>>1, p);
     ret = (ret*ret)%p;
     if( exp & 1 ) {
          ret = (ret*x)%p;
     }
     return (int)ret;
}

int main() {
     int N, K;
     while( scanf("%d %d", &N, &K), N && K ) {
          long long M = ExpMod(251, N+1, 250*K);
          M = (M+250*K-1)%(250*K);          // M--;

          long long M2 = ExpMod(2, 3*N+1, 250*K);
          M2 = (M2+250*K-1)%(250*K);          // M--;

          M = (M*M2)%(250*K);
          M /= 250;

          printf("%d\n", ExpMod(2008, M, K));
     }

     return 0;
}