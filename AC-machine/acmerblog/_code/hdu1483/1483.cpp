#include<iostream>
using namespace std;
struct NODE
{
 char s[26];
 char t[26];//ji de '?'-1
}; 
struct NODE2
{
 char s[26];
 char t[26];
 int val;
};
int main()
{
 bool mainn();
 while(mainn());
 return 0;
}
int N,M;
NODE node[100001];
NODE2 tcin;
int ptr;
int tval;
int la;
inline f(const char s[],char t[])
{
 int i;
 for(i=0;s[i]!='\0';i++)
 {
  t[s[i]-'a']++;
 }
}
inline Cval(NODE2 tcin,int id)
{
 int i,j;
 int t=0;
 if(!strcmp(tcin.s,node[id].s))return 0;//letter letter
 int lb=strlen(node[id].s);
 if(la==lb)
 {
  t=0;//lettre letter 
  if(!memcmp(tcin.t,node[id].t,sizeof(char)*26))
  {
   for(i=0;i<la;i++)
   {
    if(tcin.s[i]!=node[id].s[i])
    {
     t++;
     if(t>2)
      break;
    }
   }
   if(t==2)return 1;
  }
  t=0;//ketter letter 
  for(i=0;i<la;i++)
  {
   if(tcin.s[i]!=node[id].s[i])
   {
    t++;
    if(t>1)break;
   }
  }
  if(t==1)return 1;
 }
 
 if(abs(la-lb)==1)
 {
  if(la<lb)//leter letter 
  {
   t=0;
   for(i=0,j=0;i<la && j<lb;i++,j++)
   {
    if(tcin.s[i]==node[id].s[j])continue;
    i--;t++;
    if(t>2)
     break;
   }
   if(t<2)return 1;
  }
  else if(la>lb)//lettter letter
  {
   t=0;
   for(i=0,j=0;i<la && j<lb;i++,j++)
   {
    if(tcin.s[i]==node[id].s[j])continue;
    j--;t++;
    if(t>2)
     break;
   }
   if(t<2)return 1;
  }
 }
 return 2; 

}
bool mainn()
{
 int i,j,flag;
 if(EOF==scanf("%d",&N))return false;
 for(i=0;i<N;i++)
 {
  scanf("%s",node[i].s);
  memset(node[i].t,0,sizeof(char)*26);
  f(node[i].s,node[i].t);
 }
 scanf("%d",&M);
 for(i=0;i<M;i++)
 {
  scanf("%s",tcin.s);
  memset(tcin.t,0,sizeof(char)*26);
  tcin.val=2;
  ptr=-1;
  f(tcin.s,tcin.t);
  la=strlen(tcin.s);
  for(j=0;j<N;j++)
  {
   tval=Cval(tcin,j);
   if(tval<tcin.val)
   {
    tcin.val=tval;
    ptr=j;
    if(tcin.val==0)
    {
     break;
    }
   }
  }
  if(tcin.val==2)
  {
   printf("%s is unknown\n",tcin.s);
   continue;
  }
  if(tcin.val==1)
  {
   printf("%s is a misspelling of %s\n",tcin.s,node[ptr].s);
   continue;
  }
  if(tcin.val==0)
  {
   printf("%s is correct\n",tcin.s);
   continue;
  }
 }
 return true;
}