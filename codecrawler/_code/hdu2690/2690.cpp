#include <stdio.h>
#include <string.h>
int main()
{
 int hash[11111];
 int i,j;
 int t,n;
 int a;
  scanf("%d",&t);
   while(t--) {
    scanf("%d",&n);
   //hash 下标是每个人说的数字,对应的值为说该数的人的个数
    memset(hash,0,sizeof(hash));
    //mim 来记录女生个数
    //cnt 来记录有几类人( 全男全女,或有男有女 )
    int cnt=0;
    int min=99999;
    for(i=1;i<=n;i++){
     scanf("%d",&a);
      if(!hash[a]) {
       min=a<min?a:min;
       cnt++;
      }
     hash[a]++;
    }
    //如果说的人数有大于2种的,或者n=1的
    if(cnt>2||n==1) puts("Impossible!");
    else {
     //cnt=1 说明是全男,全女的情况
     if(cnt==1) {
      if(min==0)          //就是全是男的,看到的女生就是0
        printf("0/n");
      else if(min+1==n)   //全是女的,并且看到的都是 n-1 个
        printf("%d/n",n);
      else
        puts("Impossible!");
     }
     //cnt=2,有男友女的情况
     else  {
      //如果 女的看到的个数和男的看到的个数相差 1
      if(hash[min]+hash[min+1]==n) {
        //如果女的看到的个数是 看到的人数+1 个
         if(hash[min]==min+1)
           printf("%d/n",min+1);
         else
           puts("Impossible!");
      }
      else  puts("Impossible!");
     }
    }
   }
}