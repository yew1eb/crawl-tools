#include<stdio.h>
int main()
{
 int i=0;
 int n;
 int a;
 int sum,num;
 while(i<10)
 { 
 sum=num=0;
 scanf("%d",&a);
 if(a==-1)break;
 if(a==0) printf("Exactly 3 o'clock\n"); //���4
 else
 {
 sum=a%30;
 num=a/30;
 if(num<3) //���1
 {
 num=3-num;
 if(sum==0)
 printf("Exactly %d o'clock\n",num);
 if(sum!=0)printf("Between %d o'clock and %d o'clock\n",num-1,num);
 }
 if(num>3) //���2
 { 
 num=3-num+12;
 if(sum==0) printf("Exactly %d o'clock\n",num);
 if(sum!=0) printf("Between %d o'clock and %d o'clock\n",num-1,num);
 }
 if(num==3) //���3
 {
 num=3-num;
 if(sum==0) printf("Exactly %d o'clock\n",num);
 if(sum!=0) printf("Between %d o'clock and %d o'clock\n",11,num);
 
 }
 }
 i++;
 
 }
 return 0;
}