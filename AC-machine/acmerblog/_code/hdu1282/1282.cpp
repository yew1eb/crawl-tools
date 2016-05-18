#include<cstdio>
 bool judge(int k) {          //判断是不是回文数 
     int i = 0,x[10005];      
     while(k) {            //将数先存到数组里面 
         x[i++] = k%10;
         k/=10;
     }
     for(int j = 0;j<i;++j)
     if(x[j] != x[i-j-1])
     return false;
     return true;
 }
 int oper(int k) {       //求数k的倒序数 
     int ans = 0;
     while(k) {
         ans *= 10;
         ans += (k%10);
         k /= 10;
     }
     return ans;
 }
 int main() {
     int n,jilu[1005];
     while(scanf("%d",&n)!=EOF) {
         jilu[0] = n;   //将原来的数先存起来 
         int f = 0;     //计数器 
         while(!judge(n)) {
             n += oper(n);
             jilu[f+1] = n;
             f++;
         }
         printf("%d\n%d",f,jilu[0]);
         for(int i = 1;i<=f;++i)
         printf("--->%d",jilu[i]);
         printf("\n");
     }
     return 0;
 }