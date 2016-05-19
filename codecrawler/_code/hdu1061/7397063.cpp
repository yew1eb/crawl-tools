/*0 0 T=1
  1 1 T=1
  2 2 4 8 6 T=4
  3 3 9 7 1 T=4
  4¡­¡­4 6 T=2 
  5¡­¡­5 T=1
  6¡­¡­6 T=1
  7¡­¡­7 9 3 1 T=4
  8¡­¡­8 4 2 6 T=4
  9¡­¡­9 1 T=2
*/
#include<stdio.h>

int main(){
    __int64 n;
    int t;
    int b;
    int x;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        b=n%10;
        if(b==0)x=0;
        else if(b==1)x=1;
        else if(b==2)
             {if(n%4==1)x=2;else if(n%4==2)x=4;else if(n%4==3)x=8;else if(n%4==0)x=6;}
        else if(b==3)
             {if(n%4==1)x=3;else if(n%4==2)x=9;else if(n%4==3)x=7;else if(n%4==0)x=1;}
        else if(b==4)
             {if(n%2==1)x=4;else x=6;}
        else if(b==5)x=5;
        else if(b==6)x=6;
        else if(b==7)
             {if(n%4==1)x=7;else if(n%4==2)x=9;else if(n%4==3)x=3;else if(n%4==0)x=1;}
        else if(b==8)
             {if(n%4==1)x=8;else if(n%4==2)x=4;else if(n%4==3)x=2;else if(n%4==0)x=6;}
        else if(b==9)
             {if(n%2==1)x=9;else x=1;}
        
        printf("%d\n",x);
    }
    return 0;
}
