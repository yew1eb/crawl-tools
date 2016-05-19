#include<stdio.h>
#include<string.h>
char a[7][40];
int main()
{
int t,i,j,c,n,d,h,m,s;
char b[50];
strcpy(a[0],"S.H.E");
strcpy(a[1],"Jay");
strcpy(a[2],"Elva");
strcpy(a[3],"Jolin");
strcpy(a[4],"Aska");
strcpy(a[5],"Yoga");
scanf("%d",&t);
while(t--)
{
h=m=s=0;
scanf("%d",&n);
getchar();
while(n--)
{
memset(b,'\0',sizeof(b));
scanf("%s %d:%d",b,&c,&d);
getchar();
for(i=0;i<=5;i++)
{
if(strcmp(b,a[i])==0)
{
s=s+d;
if(s>=60)
{
s=s-60;m++;
if(m>=60){m=m-60;h++;}
}
m+=c;
if(m>=60){m=m-60;h++;}
break;
}
}
}
printf("Samuel will watch Channel[V] for %d hour(s),%d minute(s),%d second(s).\n",h,m,s);
}
return 0;
}