#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
int len;
char s[111];
char str[1111];
string s1,s2,s3;
int main()
{
    int i,j,k,m,x,y,pos;
    scanf("%d",&k);
    while(k--)
    {
        s1=s2=s3="";
        for(i=390;i<=610;i++) str[i]='*';
          scanf("%s",s);
          len=strlen(s);
          m=99999;
          for(i=len-1;i>=0;i--) if(s[i]!='0'&&s[i]<m) { m=s[i];pos=i;}
          s1=m;
          for(i=pos+1;i<len;i++) s3+=s[i];
          if(pos==0)
          {
                    printf("%s",s1.c_str());
                    printf("%s\n",s3.c_str());
                    continue;
          }
          x=501;
          y=500; 
          int mid=s[0];
          str[y--]=s[0];
          i=1;
          for(;i<pos;i++)
          {
                if(s[i]<=mid)
                {
                    str[y--]=s[i];
                    mid=s[i];
                }
                else str[x++]=s[i];
          }
          printf("%s",s1.c_str());
         for(i=390;i<=610;i++)
            if(str[i]!='*')  printf("%c",str[i]);
          printf("%s\n",s3.c_str());
    }
    return 0;
}
