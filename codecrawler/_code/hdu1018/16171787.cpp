#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,f;
    double sum ;
    cin >> n;
    int i = 0;
    //å©ç¨æ°å­¦å¬å¼lg(n!)=lg(2)+lg(3)+....+lg(n) æ±è§£ 
    while(cin >> f)
    {
      sum = 0;
    for(int i = 2;i<=f;++i)
            sum+=log10(i);
    cout << (int)sum +1 << endl;
    ++i;
    if (i==n)break;
    }

    return 0 ;

}