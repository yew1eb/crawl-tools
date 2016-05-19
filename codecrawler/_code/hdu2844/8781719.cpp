#include <stdio.h>
#include <string.h>
int a[105], c[105];
int f[100005];
int v;

void ZeroOnePack(int cost, int weight)
{
    for (int i = v; i >= cost; i--)
        f[i] = f[i] || f[i - weight];
}
void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= v; i++)
        f[i] = f[i] || f[i - weight];
}
void MultiplePack(int cost, int weight, int amount)
{
    if (cost * amount >= v) CompletePack(cost, weight);
    else {
        for (int k = 1; k < amount;) {
            ZeroOnePack(k * cost, k * weight);
            amount -= k;
            k <<= 1;
        }
        ZeroOnePack(amount * cost, amount * weight);
    }
}
int main()
{
    int i, n, m;
    while (scanf("%d%d", &n, &m), n + m) {
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        for (i = 0; i < n; i++) scanf("%d", &c[i]);
        memset(f, 0, sizeof(f));
        f[0] = 1;
        v = m;
        for (i = 0; i < n; i++)
            MultiplePack(a[i], a[i], c[i]);
        int ans  = 0;
        for (i = 1; i <= m; i++)
            if (f[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
