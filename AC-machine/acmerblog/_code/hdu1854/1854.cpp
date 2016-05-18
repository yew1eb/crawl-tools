#include<stdio.h>
#include<string.h>
char s[1005];
int flag;
int  search(char * s)
{
int len=strlen(s);
int i;
flag=0;
for(i=0;i<len;i++)
{
if(s[i]=='0')
{
flag++;
}
else if(s[i]=='1')
{
if(flag==1)
return flag=0;
flag--;
}
}
if(flag==1)
return flag;
}
int main()
{
int n;
scanf("%d",&n);
while(n--)
{
scanf("%s",s);
search(s);
if(flag)
printf("Yes\n");
else
printf("No\n");
}
return 0;
}