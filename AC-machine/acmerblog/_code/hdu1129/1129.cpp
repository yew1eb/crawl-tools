#include <iostream>
#define   N 75
using namespace std;
char ct[N],pt[N];
int cc[N],pc[N];
int k,len;
void ctTocc(){
for (int i=0;i<len;i++)
{
   if (ct[i]=='_')
    cc[i] = 0;
   else if(ct[i]=='.')
    cc[i] = 27;
   else{
    cc[i] = ct[i]-'a'+1;
   }
}
}
void ccTopc(){
int j;
for (int i=0;i<len;i++)
{
   j = (cc[i] +i+28)%28;
   pc[(k*i)%len]=j;
}
}
void pcTopt(){
int i,j;
for (i=0;i<len;i++)
{
   if (pc[i]==0)
    pt[i] = '_';
   else if (pc[i]==27)
    pt[i]='.';
   else
    pt[i]='a'+pc[i]-1;
}
pt[len]='\0';
}
int main()
{
while (scanf("%d",&k)&&k!=0)
{
   scanf("%s",&ct);
   len = strlen(ct);
   ctTocc();
   ccTopc();
   pcTopt();
   printf("%s\n",pt);
}
return 0;
}