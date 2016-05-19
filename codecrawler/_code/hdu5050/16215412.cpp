#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define clr0(x) memset(x,0,sizeof(x))

const int maxn = 1010;

struct Num
{
    int num[1100];
};

void print(const Num &hold)
{
    int k;

    for (k = maxn; k >= 0; k --)
    if (hold.num[k])
    break;

    for (int i = k; i >= 0; i --)
    printf("%d", hold.num[i]);
}

Num operator+(const Num &a, const Num &b)
{
    Num ret;
    int temp;

    clr0(ret.num);

    for (int i = 0; i <= maxn; i ++)
    {
        temp = ret.num[i];

        ret.num[i] = (temp + a.num[i] + b.num[i]) % 2;
        ret.num[i + 1] = (temp + a.num[i] + b.num[i]) / 2;
    }

    return ret;
}

bool operator==(const Num &a, int num)
{
    for (int i = 0; i <= maxn; i ++)
    if (a.num[i] != num)
    return false;

    return true;
}

bool operator<(const Num &a, const Num &b)
{
    for (int i = maxn; i >= 0; i --)
    {
        if (a.num[i] < b.num[i])
        return true;
        else if (a.num[i] > b.num[i])
        return false;
    }

    return true;
}

Num Complement(Num hold)
{
    char str[1100];
    Num ret, temp;

    strcpy(str, "1");

    clr0(temp.num);
    int bit = 0,lls = strlen(str);
    for (int i = lls - 1; i >= 0; i --)
        temp.num[bit ++] = str[i] - '0';

    ret = hold;


    for (int i = 0; i <= maxn; i ++)
    {
        if (ret.num[i])
        ret.num[i] = 0;
        else
        ret.num[i] = 1;
    }

    ret = ret + temp;

    return ret;
}

Num operator-(const Num &a, const Num &b)
{
    Num c, ret;

    c = Complement(b);

    ret = a + c;

    return ret;
}


Num operator/(const Num &hold, int num)
{
    Num ret;

    clr0(ret.num);

    for (int i = 0; i < maxn; i ++)
    ret.num[i] = hold.num[i + 1];

    return ret;
}

int operator%(const Num &hold, int num)
{
    return hold.num[0];
}

Num gcd(Num a, Num b, int &counter)
{
    while (true)
    {
        if (a < b)
        swap(a, b);

        if (b == 0)
        break;

        if (a % 2 == 0 && b % 2 == 0)
        {
            counter ++;

            a = a / 2;
            b = b / 2;
        }
        else if (a % 2 == 0 && b % 2 != 0)
        {
            a = a / 2;
            b = b;
        }
        else if (a % 2 != 0 && b % 2 == 0)
        {
            a = a;
            b = b / 2;
        }
        else
        {
            a = a - b;
            b = b;
        }
    }

    return a;
}

int main()
{
    int _;RD(_);
    char ta[1100], tb[1100];
    int counter;
    Num a, b, ans ;
    int bit,cas = 1;
    while (_--)
    {
        printf("Case #%d: ",cas++);
        scanf("%s%s", ta, tb);

        int lla = strlen(ta),llb = strlen(tb);

        clr0(a.num);
        bit = 0;
        for (int i = lla - 1; i >= 0; i --)
            a.num[bit ++] = ta[i] - '0';
        clr0(b.num);
        bit = 0;
        for (int i = llb - 1; i >= 0; i --)
            b.num[bit ++] = tb[i] - '0';

        counter = 0;
        ans = gcd(a, b, counter);

        print(ans);

        while(counter--)
            printf("0");

        puts("");
    }

    return 0;
}