#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c, d, e, f;
        scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
        int xt = a * 3600 + b * 60 + c;
        int yt = d * 3600 + e * 60 + f;
        
        a %= 12; d%= 12;
        int xtime = a * 3600 + b * 60 + c;
        int ytime = d * 3600 + e * 60 + f;
        while (xtime < ytime) xtime += 43200;

        int cha = xtime - ytime;
        printf("%02d:%02d:%02d\n", cha/3600, (cha%3600)/60, (cha%3600)%60);
    }
    return 0;
}