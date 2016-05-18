#include<iostream>
 #include<stdio.h>
 #include<algorithm>
 #include<iomanip>
 #include<cmath>
 #include<cstring>
 #include<vector>
 #define ll __int64
 #define pi acos(-1.0)
 using namespace std;
 const int MAX = 200002;
 //复数结构体
 struct complex{
     double r,i;
     complex(double R=0,double I=0){
         r=R;i=I;
     }
     complex operator+(const complex &a){
         return complex(r+a.r,i+a.i);
     }
     complex operator-(const complex &a){
         return complex(r-a.r,i-a.i);
     }
     complex operator*(const complex &a){
         return complex(r*a.r-i*a.i,r*a.i+i*a.r);
     }
 };
 /*
  *进行FFT和IFFT前的反转变换
  *位置i和i的二进制反转后位置互换，(如001反转后就是100)
  *len必须去2的幂
  */
 void change(complex x[],int len){
     int i,j,k;
     for(i = 1, j = len/2; i <len-1; i++){
         if (i < j) swap(x[i],x[j]);
         //交换互为小标反转的元素，i<j保证交换一次
         //i做正常的+1,j做反转类型的+1，始终i和j是反转的
         k = len/2;
         while (j >= k){
             j -= k;
             k /= 2;
         }
         if (j < k) j += k;
     }
 }
 /*
  *做FFT
  *len必须为2^n形式，不足则补0
  *on=1时是DFT，on=-1时是IDFT
  */
 void fft (complex x[],int len,int on){
     change(x,len);
     for (int i=2;i<=len;i<<=1){
         complex wn(cos(-on*2*pi/i),sin(-on*2*pi/i));
         for (int j=0;j<len;j+=i){
             complex w(1,0);
             for (int k=j;k<j+i/2;k++){
                 complex u = x[k];
                 complex t = w*x[k+i/2];
                 x[k] = u+t;
                 x[k+i/2] = u-t;
                 w = w*wn;
             }
         }
     }
     if (on == -1){
         for (int i=0;i<len;i++){
             x[i].r /= len;
         }
     }
 }
 complex x1[MAX],x2[MAX];
 char str1[MAX/2],str2[MAX/2];
 ll num[MAX],sum[MAX];
 int main()
 {
     int i,j,k,len1,len2,len;
     while(scanf("%s%s",&str1,&str2)!=EOF){
         len1 = strlen(str1);
         len2 = strlen(str2);
         len = 1;
         while (len < 2*len1 || len < 2*len2) len<<=1;
         for (i=0;i<len1;i++){
             x1[i] = complex(str1[len1-1-i]-'0',0);
         }
         for (i=len1;i<len;i++){
             x1[i] = complex(0,0);
         }
         for (i=0;i<len2;i++){
             x2[i] = complex(str2[len2-1-i]-'0',0);
         }
         for (i=len2;i<len;i++){
             x2[i] = complex(0,0);
         }
         fft(x1,len,1);
         fft(x2,len,1);
         for (i=0;i<len;i++){
             x1[i] = x1[i]*x2[i];
         }
         fft(x1,len,-1);
         for (i=0;i<len;i++){
             sum[i] = (int)(x1[i].r+0.5);
         }
         for (i=0;i<len;i++){
             sum[i+1]+=sum[i]/10;
             sum[i]%=10;
         }
         len = len1+len2-1;
         while (sum[len]<=0 && len>0) len--;
         for (i=len;i>=0;i--){
             printf("%c",sum[i]+'0');
         }
         printf("\n");
     }
     return 0;
 }