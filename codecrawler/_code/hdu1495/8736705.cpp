#include<stdio.h>

int s;
int a;
int b;
int ss;
int aa;
int bb;
int num;

int main()
{
 int i,j;
 while(1)
 {
  scanf("%d %d %d",&s,&i,&j);
  if(s==0 && i==0 && j==0)
   break;
  ss=s;
  aa=0;
  bb=0;
  num=0;
  a=i>j ? i : j;
  b=i<j ? i : j;
  while(1)
  {
   if(ss==b && aa==a && num>1)
   {
    printf("NO\n");
    break;
   }
   if(ss==aa && bb==0)
   {
    printf("%d\n",num);
    break;
   }
   if(bb==b)
   {
    ss+=b;
    bb=0;
    num++;
    continue;
   }
   if(aa>0 && aa<=a)
   {
    if(aa>b-bb)
    {
     aa-=b-bb;
     bb=b;
    }
    else
    {
     bb+=aa;
     aa=0;
    }
    num++;
    continue;
   }
   else
   {
    if(ss>=a)
    {
     ss-=a;
     aa=a;
    }
    else
    {
     ss=0;
     aa=ss;
    }
    num++;
   }
  }
 }
 return 0;
}
