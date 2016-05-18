#include<cstdio>
#include<vector>

#define MAXX 32000

int i,j,m,n;
std::vector<int>prm;
bool flag[MAXX];

int main()
{
 prm.reserve(MAXX);
 for(i=2;i<MAXX;++i)
 {
 if(!flag[i])
 prm.push_back(i);
 for(j=0;j<prm.size() && i*prm[j]<MAXX;++j)
 {
 flag[i*prm[j]]=true;
 if(i%prm[j]==0)
 break;
 }
 }
 while(scanf("%d",&m)!=EOF)
 {
 if(!m)
 {
 puts("0");
 continue;
 }
 if(m<8)
 {
 printf("%d\n",m-1);
 continue;
 }
 n=m;
 if(!(m&1))
 {
 m>>=1;
 if(!(m&1))
 {
 puts("1");
 continue;
 }
 }
 for(i=1;i<prm.size();++i)
 if(m%prm[i]==0)
 {
 do
 m/=prm[i];
 while(m%prm[i]==0);
 break;
 }
 if(m==1 || i>=prm.size())
 printf("%d\n",n-1);
 else
 puts("1");
 }
 return 0;
}