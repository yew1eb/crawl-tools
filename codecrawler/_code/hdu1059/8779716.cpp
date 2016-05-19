#include <stdio.h>
#include <string.h>

int a[7];
int f[100005];
int v, k;

void ZeroOnePack(int cost, int weight)
{
    for (int i = v; i >= cost; i--)
        if (f[i - cost] + weight > f[i])
            f[i] = f[i - cost] + weight;
}
void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= v; i++)
        if (f[i - cost] + weight > f[i])
            f[i] = f[i - cost] + weight;
}
void MultiplePack(int cost, int  weight, int amount)
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
    int sum;
    int cas = 0;
    while (1) {
        sum = 0;
        for (int i = 1; i < 7; i++) {
            scanf("%d", &a[i]);
            sum += a[i] * i;
        }
        if (sum == 0) break;
        if (sum % 2 == 1) {
            printf("Collection #%d:\nCan't be divided.\n\n", ++cas);
            continue;
        } else {
            v = sum / 2;
            memset(f, 0, sizeof(f));
            for (int i = 1; i < 7; i++)
                MultiplePack(i, i, a[i]);
            if (f[v] == v)
                printf("Collection #%d:\nCan be divided.\n\n", ++cas);
            else
                printf("Collection #%d:\nCan't be divided.\n\n", ++cas);
        }
    }
    return 0;
}
