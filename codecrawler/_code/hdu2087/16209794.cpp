#include<stdio.h>
#include<string.h>
#define MAX 1002
char target[MAX];
char pattern[MAX];
int next[MAX];
int lenp,lent;
int index;
void my_overlay()
{ 
 int i;
 next[0]=-1;
 for(i=1;i<lenp;i++)
 {
    index=next[i-1];
    while(index>=0&&pattern[i]!=pattern[index+1])
    {
       index=next[index];
    }
    if(pattern[i]==pattern[index+1])
     next[i]=index+1;
    else next[i]=-1;
 }
}
void my_kmp()
{
   int i=0,j=0,count=0;
   for(i=0;i<lent;)
   {
   
      if(pattern[j]==target[i]) 
   {
   ++i;
   ++j;
   }
   else
   {   
    if(j==0) i++;
    else  j=next[j-1]+1;     
   }
   if(j==lenp)
   {
    j=0;
    count++;   
   }
   }
   printf("%d\n",count);
}
int main()
{
  
   while(1)
   {
       scanf("%s",target);
    if(strcmp(target,"#")==0) break;
    scanf("%s",pattern);
    lent=strlen(target);
    lenp=strlen(pattern);
    if(lenp>lent) printf("%d\n",0);
    else
    {
      my_overlay();
      my_kmp();
    }   
   }
   return 0;
}