#include<stdio.h>
#include<string.h>
#include<math.h>
char s[1248];
double Getanswer(char *s)
{
  double ans,p,x,y;
  int i,j,n;
  if(s[0]!='(')//输入的就是一个数字
  {
    sscanf(s,"%lf",&ans);//字符串转换为double
    return ans;
  }
  sscanf(s+1,"%lf",&p);
  i=0;
  while(s[i++]!=' ');       //while(s[i]!=' ')    {  i++;   }
  if(s[i]!='(')
  {
    sscanf(s+i,"%lf",&x);
    while(s[i++]!=' ');
    if(s[i]!='(')   sscanf(s+i,"%lf",&y);
    else             y=Getanswer(s+i);
  }
  else
  {
     n=1;
     for(j=i+1;n;j++)//左右括号的析取抵消
      {
        if(s[j]=='(')   ++n;
        if(s[j]==')')     --n;
      }
      s[j]='\0';
      x=Getanswer(s+i);
      if(s[j+1]=='(')    y=Getanswer(s+j+1);
      else              sscanf(s+j+1,"%lf",&y);
  }
  return x+(p+p-1)*y;
}
int main()
{
   while(gets(s))
    {
     if(strcmp(s,"()")==0)     break;
      printf("%.2lf\n",Getanswer(s));
    }
}