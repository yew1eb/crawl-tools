#include<cstdio>

using namespace std;
int main()
{
int n,p,q;
while(scanf("%d%d%d",&n,&p,&q)!=EOF)
{int a=n%(p+q);
if(a<=p&&a!=0)
printf("LOST\n");
else
printf("WIN\n");
}
}