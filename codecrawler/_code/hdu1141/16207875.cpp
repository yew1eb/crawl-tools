#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        n = (n - 1960)/10+2;
        double bit = (1 << n )*log(2.0);
        double count = 0;int i = 0;
        while(count < bit)
        {
            count +=  log(++i) ;//ç¹å«æ³¨æ i = 1 ,log(i++)ä¸ç¥éä¸ºä»ä¹éäº åªè½i = 0,log(++i) 
        }
        printf("%d\n",i-1);
    }
    return 0;
}
