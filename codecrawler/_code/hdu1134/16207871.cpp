#include<iostream>
using namespace std;
#define SIZE 100
int n;
int a[101][SIZE]= {0}; //æ°ç»ç¨æ¥å­æ¾ç»æ å¹¶ä¸åå§å
int main()
{
     int i,j,r=0;
     int temp = 0,len = 1;  //len è¡¨ç¤ºå½åæé¿çææä½æ°ï¼åå§åä¸º1
     a[1][0] = 1;
     for(i = 2; i <= 100; i++)//ä»ç¬¬äºé¡¹ å° ç¬¬ä¸ç¾é¡¹ï¼ ç¨å¬å¼è®¡ç®
     {
         for(j = 0; j < len; j ++)// ä¾æ¬¡ä½ä¹æ³
             a[i][j] = a[i-1][j]*(4*i-2);//ä»ä½ä½å°é«ä½
         for(j = 0; j < len; j++)//å¯¹ä¹åºæ¥çç»æ è¿è¡å¤ç
         {
             temp = a[i][j] + r;
             a[i][j] = temp%10;
             r = temp/10;
         }
         while(r)              //å¯¹é«ä½è¿è¡å¤ç
         {
             a[i][len] = r%10;
             r /= 10;
             len++;
         }
         for(j = len-1,r = 0; j >= 0;j--)//æ¨¡æé¤æ³ ä»é«ä½å°ä½ä½
         {
             temp = r*10+a[i][j];
             a[i][j] = temp/(i+1);
             r = temp%(i+1);
         }
         while(!a[i][len-1])     //å¤çé«ä½ç 0 
             len--;
     }
     while(scanf("%d",&n)!=EOF)//
     {
         if(n<0) break;
         for(i = SIZE-1; !a[n][i];i--);
         for(i;i>=0;i--){printf("%d",a[n][i]);}
         printf("\n");
     }
     return 0;
}
