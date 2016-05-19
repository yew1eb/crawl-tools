#include<iostream>
using namespace std;
int next[400005];
char s[400005];
int len;
void get_next()
{
  int k=-1,j=0;
  next[0]=-1;
  len=strlen(s);
  while(j<len)
  {
    if(k==-1||s[j]==s[k])
    {
      next[j+1]=k+1;
      j++;k++;
    }
    else
    k=next[k];
  }
}
int main()
{
  int tmp[400005];
  while(scanf("%s",s)!=EOF)
  {
    int i=1;
    get_next();
    for(int g=0;g<=len;g++)
    printf("%d ",next[g]);
    int end=len;
    tmp[0]=len;
    while(next[len]!=0)//递归的找
    {
      tmp[i++]=next[len];
      len=next[len];
    }
    if(s[0]==s[end])
    printf("1 ");
    for(int j=i-1;j>0;j--)
    printf("%d ",tmp[j]);
    printf("%d\n",tmp[0]);
  }
}