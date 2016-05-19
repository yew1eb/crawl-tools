#include<iostream>
using namespace std;
int main()
{
    int k;
    int n;
    scanf("%d",&k);
    while (k--)
    {
          scanf("%d",&n);
          int a = 1;
          while ( n > a )
          {
                n -= a;   //a = sn; æå n==a æ¶ï¼å°±ä¸ºæåä¸è¡ 
                a++;
          }
          n%=9;  if(n==0) n=9;   //sn çåx*9ä¸å®æ¯123456789 ï¼æä»¥ç£¨9åå¾å°ç¬¬nä½çæ°ã 
          printf("%d\n",n);
    } 
    return 0;
}
