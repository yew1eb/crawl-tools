/* 功能Function Description:
   开发环境Environment:          DEV C++ 4.9.9.1
   技术特点Technique:
   版本Version:
   作者Author:               Myacing
   日期Date:                 20120723
   备注Notes:
*/
#include <stdio.h>
int main()
{
    int n, m, i, j, t, a[100000];
    while(1)
    {
         scanf("%d%d",&n,&m);
         if(n==0&&m==0)
         break;
         for(i=0;i<n;i++)
         scanf("%d",&a[i]);
         for(j=0;j<m;j++)  //这个冒泡其实不用完全比较完的，因为要是比较晚的话就要超时了 ，并且冒泡注意范围的判定 
         for(i=0;i<n-j-1;i++)
         {
             if(a[i]>a[i+1])
             {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
             }
         }
         for(i=n-1;i>n-1-m;i--)
         {
                         if(i==n-1)
                         printf("%d",a[i]);
                         else
                         printf(" %d",a[i]);
         }
         printf("\n");
    }
    return 0;
}
