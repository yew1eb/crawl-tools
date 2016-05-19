1 #include <stdio.h>
 2 #include <string.h>
 3 
 4 int main(){
 5     int n, num[50000], tem, i, j;
 6     while(scanf("%d",&n) != EOF){
 7         memset(num, 0, sizeof(num));
 8         for(i = 1; i <= n; i++){
 9             scanf("%d",&tem);
10             num[tem]++;
11             if(num[tem] >= (n + 1) / 2)
12                 j = tem;
13         }
14         printf("%d\n",j);
15     }
16     return 0;
17 }