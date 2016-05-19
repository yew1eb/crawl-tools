/*
  题意：这道题估计是太简单，在网上都找不到答案，貌似思路是有的
        就是两个人在一个圆桌上面放硬币，不能重叠，各种，然后最后谁放不下啦就输啦
  思路：大神那儿得来的，我是想不出来，见链接吧。
*/
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    double a,b;
    while(scanf("%lf%lf",&a,&b)!=EOF)
    {
      if(a>=b) cout << "Yes, Mr. Wendy is a ****ing genius!" << endl;
      else cout << "No, Mr. Pian is the real ****ing genius!" << endl;
    }
    return 0;
}